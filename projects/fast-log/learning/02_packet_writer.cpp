#include <iostream>
#include <fstream>
#include <stdint.h>

#pragma pack(push, 1)
struct LogEntry {
    uint64_t timestamp;
    uint8_t type;
    uint32_t value;
};
#pragma pack(pop)
int main() {
    LogEntry logEntry;
    logEntry.timestamp = 1625077765123;
    logEntry.type = 1;
    logEntry.value = 42;
    std::ofstream logFile("logfile.bin", std::ios::binary|std::ios::app);
    if (!logFile.is_open()) {
        std::cout << "Unable to open logfile.bin" << std::endl;
        return 1;
    }
    logFile.write(reinterpret_cast<const char*>(&logEntry), sizeof(LogEntry));
    logFile.close();
    std::cout << "Log file written" << std::endl;
    std::cout<< "Size of LogEntry: " << sizeof(LogEntry) << " bytes" << std::endl;
    return 0;

}
