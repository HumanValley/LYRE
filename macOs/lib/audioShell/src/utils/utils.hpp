#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <fstream>
#include "../files/wave/wave.hpp"

// ENDIAN.CPP

template <typename T> T swap_endian(T u) {
    union
    {
        T u;
        unsigned char u8[sizeof(T)];
    } source, dest;

    source.u = u;

    for (size_t k = 0; k < sizeof(T); k++)
        dest.u8[k] = source.u8[sizeof(T) - k - 1];

    return dest.u;
}

// CONVERT.CPP

char *				uint32_tToChar(uint32_t value);
char *              uint16_tToChar(uint16_t value);
void                writeint32_t(std::ofstream &file, uint32_t value);
void                writeint16_t(std::ofstream &file, uint16_t value);

// FILE.CPP

char *				readFile(const std::string path);
std::streampos		getFileSize(std::fstream &fileStream);
