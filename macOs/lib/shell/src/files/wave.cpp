#include "./wave.hpp"

using namespace ADSH;

Wave::Wave() {}

Wave::Wave(const Wave &src) {

    *this = src;
}

Wave::Wave(const Wave &&src) noexcept {

    // *this = src;
}

Wave::~Wave() {}

Wave &Wave::operator=(const ADSH::Wave &rhs) {

    if (this != &rhs) {
        this->header = rhs.header;
        this->data = rhs.data;
    }
    return *this;
}

void Wave::load(const std::string path) {
    int i = 7;

    int js = 3;

    i = 2;
    js = 1;

    char etstte = 'e';
}

void Wave::build(const WaveHeader header, const char *data) {}

void Wave::save(const std::string path) {}

Wave &Wave::operator=(Wave &&rhs) noexcept {

    // if (this != &rhs) {
    //     this->header = rhs.header;
    //     this->data = rhs.data;
    // }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Wave &rhs) {
	
    o << "Header:" << std::endl;
    // o << "FileTypeBlocId: " << uint32_tToChar(rhs.FileTypeBlocId) << std::endl;
    // o << "ChunkSize: " << rhs.FileSize << std::endl;
    // o << "FileFormatId: " << uint32_tToChar(rhs.FileFormatId) << std::endl << std::endl;
    // o << "subChunk1ID: " << rhs.subChunk1ID << std::endl;
    // o << "dwChunkSize: " << rhs.dwChunkSize << std::endl;
    // o << "audioFormat: " << rhs.audioFormat << std::endl;
    // o << "numChannels: " << rhs.numChannels << std::endl;
    // o << "sampleRate: " << rhs.sampleRate << std::endl;
    // o << "ByteRate: " << rhs.byteRate << std::endl;
    // o << "BlockAlign: " << rhs.blockAlign << std::endl;
    // o << "BitsPerSample: " << rhs.bitsPerSample << std::endl << std::endl;
    // o << "Subchunk2ID: " << uint32_tToChar(rhs.subChunk2ID) << std::endl;
    // o << "Subchunk2Size: " << rhs.subChunk2Size << std::endl;
    // o << "Data: " << rhs.data << std::endl;

    return o;
}