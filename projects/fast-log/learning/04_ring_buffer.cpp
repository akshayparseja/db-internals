#include <iostream>
#include <mutex>
#include <thread>
struct RingBuffer{
    int buffer[10];
    int head = 0;
    int tail = 0;
    bool isFull = false;
    std::mutex mtx;
    std::condition_variable cv;
};

RingBuffer rb;
void producer() {
    for (int i = 0; i < 50; i++) {
        std::unique_lock<std::mutex> lock(rb.mtx);
        while (rb.isFull) {
            rb.cv.wait(lock);
        }
        rb.buffer[rb.head] = i;
        std::cout << "Produced: " << i << std::endl;
        rb.head = (rb.head + 1) % 10;

        if (rb.head == rb.tail) {
            rb.isFull = true;
        }
        lock.unlock();
        rb.cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void consumer() {
    for (int i = 0; i < 50; i++) {
        std::unique_lock<std::mutex> lock(rb.mtx);
        while (rb.head == rb.tail && !rb.isFull) {
            std::cout << "Buffer empty" << std::endl;
            rb.cv.wait(lock);
        }
        int value = rb.buffer[rb.tail];
        std::cout << "Consumed: " << value << std::endl;
        rb.tail = (rb.tail + 1) % 10;
        rb.isFull = false;
        lock.unlock();
        rb.cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));

    }

}
int main() {
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();

    return 0;

}

