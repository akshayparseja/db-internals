#include <iostream>
#include <fstream>
int main () {
    int testInt=1234567;
    std::ofstream textFile("textfile.txt");
    textFile << testInt;
    textFile.close();
    std::ofstream binaryFile("binaryfile.bin", std::ios::binary);
    binaryFile.write(reinterpret_cast<const char*>(&testInt), sizeof(testInt));
    binaryFile.close();
    return 0;
}

