// #include "./wav.hpp"












// bool getSystemEndianess() { // 0 for little-endian, 1 for big-endian
//     union {
//         uint32_t intValue;
//         char byteArray[4];
//     } endianTest;

//     endianTest.intValue = 1;

//     if (endianTest.byteArray[0] == 1) {
//         return 0;
//     } else {
//         return 1;
//     }
//     return 0;
// }

// template <typename T> T swap_endian(T u, bool needEndian) {

//     if (needEndian == getSystemEndianess())
//         return u;
//     static_assert (CHAR_BIT == 8, "CHAR_BIT != 8");
//     union
//     {
//         T u;
//         unsigned char u8[sizeof(T)];
//     } source, dest;

//     source.u = u;

//     for (size_t k = 0; k < sizeof(T); k++)
//         dest.u8[k] = source.u8[sizeof(T) - k - 1];

//     return dest.u;
// }

// Wav::Wav() {
// }

// Wav::Wav(const Wav & src) {
//     *this = src;
// }

// Wav::Wav(const std::string path) {
//     char *buffer;

//     try {
//         buffer = readFile(path);
//         initHeader(buffer);
//         initData(buffer);
//     } catch (std::exception & e) {
//         std::cerr << e.what() << std::endl;
//     }
// }

// Wav::~Wav() {
// }

// const Header & Wav::getHeader() {
    
//     return this->header;
// }

// char *Wav::readFile(const std::string path){

//     char *          buffer;
//     std::fstream    fileStream(path);

//     if (!fileStream.good())
//         throw std::runtime_error("Error: file not found");
//     buffer = new char[45];
//     fileStream.read(buffer, 44);
//     fileStream.close();
//     return buffer;
// }

// void Wav::initHeader(char * raw) {

//     char * buffer;
//     Header header;

//     buffer = raw;

//     // [BLOC DE DECLARATION DU FICHIER] -- 12 bytes --
    
//     memcpy(&header.FileTypeBlocId, buffer, 4);
//     header.FileTypeBlocId = swap_endian(header.FileTypeBlocId, 1);
//     buffer += 4;
//     memcpy(&header.FileSize, buffer, 4);
//     header.FileSize = swap_endian(header.FileSize, 0);
//     buffer += 4;
//    memcpy(&header.FileFormatId, buffer, 4);
//     header.FileFormatId = swap_endian(header.FileFormatId, 1);
//     buffer += 4;

//     // [BLOC DE DESCRIPTION DU FICHIER] -- 24 bytes --

//    memcpy(&header.subChunk1ID, buffer, 4);
//     header.subChunk1ID = swap_endian(header.subChunk1ID, 1);
//     buffer += 4;
//     memcpy(&header.dwChunkSize, buffer, 4);
//     header.dwChunkSize = swap_endian(header.dwChunkSize, 0);
//     buffer += 4;
//     memcpy(&header.audioFormat, buffer, 2);
//     header.audioFormat = swap_endian(header.audioFormat, 0);
//     buffer += 2;
//     memcpy(&header.numChannels, buffer, 2);
//     header.numChannels = swap_endian(header.numChannels, 0);
//     buffer += 2;
//     memcpy(&header.sampleRate, buffer, 4);
//     header.sampleRate = swap_endian(header.sampleRate, 0);
//     buffer += 4;
//     memcpy(&header.byteRate, buffer, 4);
//     header.byteRate = swap_endian(header.byteRate, 0);
//     buffer += 4;
//     memcpy(&header.blockAlign, buffer, 2);
//     header.blockAlign = swap_endian(header.blockAlign, 0);
//     buffer += 2;
//     memcpy(&header.bitsPerSample, buffer, 2);
//     header.bitsPerSample = swap_endian(header.bitsPerSample, 0);
//     buffer += 2;

//     // [BLOC DE DONNEES] --8 bytes--

//     memcpy(&header.subChunk2ID, buffer, 4);
//     header.subChunk2ID = swap_endian(header.subChunk2ID, 1);
//     buffer += 4;
//     memcpy(&header.subChunk2Size, buffer, 4);
//     header.subChunk2Size = swap_endian(header.subChunk2Size, 0);
//     buffer += 4;

//     this->header = header;
// }

// void Wav::initData(char * buffer) {
//     char * raw;
//     void * data;

//     raw = buffer + sizeof(Header);
//     std::cout << this->header << std::endl;
//     data = std::malloc(this->header.subChunk2Size);
//     memcpy(data, raw, this->header.subChunk2Size); //segfault jsp pk
// }

// char * uint32_tToChar(uint32_t value) {
    
//     char * result = new char[4];
//     result[0] = (value >> 24) & 0xFF;
//     result[1] = (value >> 16) & 0xFF;
//     result[2] = (value >> 8) & 0xFF;
//     result[3] = value & 0xFF;
//     return result;
// }

// std::ostream & operator<<(std::ostream & o, const Header & rhs) {
//     o << "Header:" << std::endl;
//     o << "FileTypeBlocId: " << uint32_tToChar(rhs.FileTypeBlocId) << std::endl;
//     o << "ChunkSize: " << rhs.FileSize << std::endl;
//     o << "FileFormatId: " << uint32_tToChar(rhs.FileFormatId) << std::endl << std::endl;
//     o << "subChunk1ID: " << rhs.subChunk1ID << std::endl;
//     o << "dwChunkSize: " << rhs.dwChunkSize << std::endl;
//     o << "audioFormat: " << rhs.audioFormat << std::endl;
//     o << "numChannels: " << rhs.numChannels << std::endl;
//     o << "sampleRate: " << rhs.sampleRate << std::endl;
//     o << "ByteRate: " << rhs.byteRate << std::endl;
//     o << "BlockAlign: " << rhs.blockAlign << std::endl;
//     o << "BitsPerSample: " << rhs.bitsPerSample << std::endl << std::endl;
//     o << "Subchunk2ID: " << uint32_tToChar(rhs.subChunk2ID) << std::endl;
//     o << "Subchunk2Size: " << rhs.subChunk2Size << std::endl;
//     // o << "Data: " << rhs.data << std::endl;

//     return o;
// }
