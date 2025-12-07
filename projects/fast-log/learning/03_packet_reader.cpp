#include <iostream>
#include <fstream>
#include <stdint.h>
#include <vector>
#pragma pack(push, 1)
struct LogEntry {
    uint64_t timestamp;
    uint8_t type;
    uint32_t value;
};
#pragma pack(pop)

int main() {
    std::ifstream ifs("logfile.bin", std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "Unable to open logfile.log" << std::endl;
        return 1;
    }
    LogEntry logEntry;
    int counter = 0;
    while (ifs.read(reinterpret_cast<char*>(&logEntry), sizeof(logEntry)))
        {
        counter++;
        std::cout << "Entry " << counter << ": "
                  << "Timestamp: " << logEntry.timestamp << ", "
                  << "Type: " << (int)logEntry.type<< ", "
                  << "Value: " << logEntry.value << std::endl;
    }
}