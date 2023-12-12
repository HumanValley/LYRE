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
        // data = new char[rhs.header.dataChunkSize];
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
	char *raw;

	buffer = readFile(path);
	raw = this->_loadHeader(buffer);
	this->_loadData(raw);

	delete[] buffer;
}

void ADSH::Wave::build(const WaveHeader header, const char * data) {}

void ADSH::Wave::save(const std::string path) {

	uint32_t numberOfSample;
	std::ofstream file(path, std::ios::binary);

	//--------------WRITE HEADER----------------

	writeint32_t(file, swap_endian(this->header.fileTypeChunkId));
	writeint32_t(file, this->header.fileSize);
	writeint32_t(file, swap_endian(this->header.fileFormatId));

	writeint32_t(file, swap_endian(this->header.formatChunkID));
	writeint32_t(file, this->header.formatChunkSize);
	writeint16_t(file, this->header.audioFormat);
	writeint16_t(file, this->header.numChannels);
	writeint32_t(file, this->header.sampleRate);
	writeint32_t(file, this->header.byteRate);
	writeint16_t(file, this->header.blockAlign);
	writeint16_t(file, this->header.bitsPerSample);

	writeint32_t(file, swap_endian(this->header.dataChunkID));
	writeint32_t(file, this->header.dataChunkSize);

	// --------------WRITE DATA----------------

	numberOfSample = this->getSamplesNumber();
	for (int i = 0; i < numberOfSample; i++) {
		for (int j = 0; j < this->header.numChannels; j++) {
			file << static_cast<uint8_t>(this->data[i].channels[j]);
			file << static_cast<uint8_t>(this->data[i].channels[j] >> 8);
		}
	}

	file.close();

}

 char * ADSH::Wave::_loadHeader(char * buffer) {

	ADSH::WaveHeader header;

	// DECLARATION BLOCK [12 bytes]
    memcpy(&header.fileTypeChunkId, buffer, 4);
	header.fileTypeChunkId = swap_endian(header.fileTypeChunkId);
    buffer += 4;
    memcpy(&header.fileSize, buffer, 4);
    buffer += 4;
   	memcpy(&header.fileFormatId, buffer, 4);
	header.fileFormatId = swap_endian(header.fileFormatId);
	buffer += 4;

	// JUNK BLOCK [36 bytes]
	if (buffer[0] == 'J' && buffer[1] == 'U' && buffer[2] == 'N' && buffer[3] == 'K')
		buffer += 36;

	// DESCRIPTION BLOCK [12 bytes]
	memcpy(&header.formatChunkID, buffer, 4);
	header.formatChunkID = swap_endian(header.formatChunkID);
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
	header.dataChunkID = swap_endian(header.dataChunkID);
	buffer += 4;
	memcpy(&header.dataChunkSize, buffer, 4);
	buffer += 4;

	this->header = header;
	return buffer;
}

void ADSH::Wave::_loadData(const char * buffer) {

	const uint32_t dataSize = header.dataChunkSize; // number of octets in data
	const uint16_t numChannels = header.numChannels; // number of channels (1 = mono, 2 = stereo, etc.)
	const uint16_t bytesPerChannel = header.bitsPerSample / 8; // number of octets per channel (1 = 8 bits, 2 = 16 bits, etc.) 	  //FIX NEED: NEED TO BE A TEMPLATE (uint8_t, uint16_t, uint32_t, uint64_t, related to bitsPerSample)

	const uint32_t numSamples = this->getSamplesNumber(); // number of samples (total number of octets / (number of channels * number of octets per channel))
	
	Sample * samples = new Sample[numSamples];

	for (size_t i = 0; i < numSamples; i++) { //For each sample
		samples[i].channels = new int32_t[numChannels]; // allocate memory for each channel
		for (size_t j = 0; j < numChannels; j++) { // for each channel
			memcpy(&samples[i].channels[j], buffer, bytesPerChannel); // copy bytesPerChannel bytes from buffer to channel
			buffer += bytesPerChannel; // move buffer pointer to next channel
		}
	}

	this->data = samples;
}

uint32_t ADSH::Wave::getSamplesNumber() const noexcept{

	return this->header.dataChunkSize / (this->header.numChannels * (this->header.bitsPerSample / 8));
}

std::ostream & operator<<(std::ostream & o, const ADSH::Wave & rhs) noexcept {
	
    o << std::endl << "Header:" << std::endl << std::endl;

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