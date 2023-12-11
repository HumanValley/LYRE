#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <fstream>

// ENDIAN.CPP

template <typename T> T bigToLittleEndian(T u) {

    union { T u; unsigned char u8[sizeof(T)]; } src, dst;

    src.u = u;

    for (size_t k = 0; k < sizeof(T); k++)
        dst.u8[k] = src.u8[sizeof(T) - k - 1];

    return dst.u;
}

// CONVERT.CPP

char *				uint32_tToChar(uint32_t value);

// FILE.CPP

char *				readFile(const std::string path);
std::streampos		getFileSize(std::fstream &fileStream);