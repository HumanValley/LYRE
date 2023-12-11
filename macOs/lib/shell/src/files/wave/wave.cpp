#include "./wave.hpp"

ADSH::Wave::Wave() noexcept {}

ADSH::Wave::Wave(const Wave & rhs) noexcept { *this = rhs; }

ADSH::Wave::Wave(Wave && rhs) noexcept {

    if (this != &rhs) {

        header = std::move(rhs.header);
    	data = rhs.data;
		rhs.data = nullptr;
	}
}

ADSH::Wave::~Wave() noexcept {}

ADSH::Wave & ADSH::Wave::operator=(const ADSH::Wave & rhs) noexcept {

    if (this != &rhs) {

        this->header = rhs.header;
        data = new char[rhs.header.dataChunkSize];
    	std::memcpy(data, rhs.data, rhs.header.dataChunkSize);
    }
    return *this;
}

ADSH::Wave & ADSH::Wave::operator=(ADSH::Wave && rhs) noexcept {

    if (this != &rhs) {

        header = std::move(rhs.header);
    	data = rhs.data;
		rhs.data = nullptr;
	}
    return *this;
}

void ADSH::Wave::load(const std::string path) {

    char *buffer;

	buffer = readFile(path);
	this->_loadHeader(buffer);
	// this->_loadData(buffer);
}

void ADSH::Wave::build(const WaveHeader header, const char * data) {}

void ADSH::Wave::save(const std::string path) {

	std::ofstream file(path, std::ios::binary);

	file.write(reinterpret_cast<char*>(&header), sizeof(WaveHeader));

	file.write(data, header.fileSize - sizeof(WaveHeader));

	file.close();

}

void ADSH::Wave::_loadHeader(const char * buffer) {

	ADSH::WaveHeader header;

	// DECLARATION BLOCK [12 bytes]
    memcpy(&header.fileTypeChunkId, buffer, 4);
	header.fileTypeChunkId = bigToLittleEndian(header.fileTypeChunkId);
    buffer += 4;
    memcpy(&header.fileSize, buffer, 4);
    buffer += 4;
   	memcpy(&header.fileFormatId, buffer, 4);
	header.fileFormatId = bigToLittleEndian(header.fileFormatId);
	buffer += 4;

	// JUNK BLOCK [36 bytes]
	if (buffer[0] == 'J' && buffer[1] == 'U' && buffer[2] == 'N' && buffer[3] == 'K')
		buffer += 36;

	// DESCRIPTION BLOCK [12 bytes]
	memcpy(&header.formatChunkID, buffer, 4);
	header.formatChunkID = bigToLittleEndian(header.formatChunkID);
	buffer += 4;
	memcpy(&header.formatChunkSize, buffer, 4);
	buffer += 4;
	memcpy(&header.audioFormat, buffer, 2);
	buffer += 2;
	memcpy(&header.numChannels, buffer, 2);
	buffer += 2;
	memcpy(&header.sampleRate, buffer, 4);
	buffer += 4;
	memcpy(&header.byteRate, buffer, 4);
	buffer += 4;
	memcpy(&header.blockAlign, buffer, 2);
	buffer += 2;
	memcpy(&header.bitsPerSample, buffer, 2);
	buffer += 2;

	// DATA BLOCK [8 bytes]
	memcpy(&header.dataChunkID, buffer, 4);
	header.dataChunkID = bigToLittleEndian(header.dataChunkID);
	buffer += 4;
	memcpy(&header.dataChunkSize, buffer, 4);
	buffer += 4;

	this->header = header;
}

void ADSH::Wave::_loadData(const char * buffer) {

}

std::ostream & ADSH::operator<<(std::ostream & o, const ADSH::Wave & rhs) noexcept {
	
    o << "Header:" << std::endl << std::endl;

	o << "fileTypeChunkId: " << uint32_tToChar(rhs.header.fileTypeChunkId) << std::endl;
	o << "fileSize: " << rhs.header.fileSize << std::endl;
	o << "fileFormatId: " << uint32_tToChar(rhs.header.fileFormatId) << std::endl << std::endl;

	o << "formatChunkID: " << uint32_tToChar(rhs.header.formatChunkID) << std::endl;
	o << "formatChunkSize: " << rhs.header.formatChunkSize << std::endl;
	o << "audioFormat: " << rhs.header.audioFormat << std::endl;
	o << "numChannels: " << rhs.header.numChannels << std::endl;
	o << "sampleRate: " << rhs.header.sampleRate << std::endl;
	o << "byteRate: " << rhs.header.byteRate << std::endl;
	o << "blockAlign: " << rhs.header.blockAlign << std::endl;
	o << "bitsPerSample: " << rhs.header.bitsPerSample << std::endl << std::endl;
	
	o << "dataChunkID: " << uint32_tToChar(rhs.header.dataChunkID) << std::endl;
	o << "dataChunkSize: " << rhs.header.dataChunkSize << std::endl;

	return o;
}