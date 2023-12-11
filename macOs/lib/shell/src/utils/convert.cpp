#include "./utils.hpp"

char * uint32_tToChar(uint32_t value) {

    char * result = new char[5];
    result[0] = (value >> 24) & 0xFF;
    result[1] = (value >> 16) & 0xFF;
    result[2] = (value >> 8) & 0xFF;
    result[3] = value & 0xFF;
	result[4] = '\0';
    return result;
}