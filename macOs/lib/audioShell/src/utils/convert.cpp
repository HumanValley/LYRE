#include "./utils.hpp"
#include <iostream>

char * uint32_tToChar(uint32_t value) {

    char * result = new char[5];
    result[0] = (value >> 24) & 0xFF;
    result[1] = (value >> 16) & 0xFF;
    result[2] = (value >> 8) & 0xFF;
    result[3] = value & 0xFF;
	result[4] = '\0';
    return result;
}

char * uint16_tToChar(uint16_t value) {

    char * result = new char[3];
    result[0] = (value >> 8) & 0xFF;
    result[1] = value & 0xFF;
    result[2] = '\0';
    return result;
}

void writeint32_t(std::ofstream &file, uint32_t value) {

    for (int i = 0; i < 4; i++)
    {
        file << static_cast<uint8_t>(value >> (i * 8));
    }
}

void writeint16_t(std::ofstream &file, uint16_t value) {
    for (int i = 0; i < 2; i++)
    {
        file << static_cast<uint8_t>(value >> (i * 8));
    }
}