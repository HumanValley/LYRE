#include "stream.hpp"

ADSH::Stream::Stream() noexcept{}

ADSH::Stream::~Stream() noexcept {}

ADSH::Stream::Stream(ADSH::WaveHeader & header, ADSH::Sample & samples) noexcept {
    this->BasicDescription.sampleRate = header.sampleRate;
    this->BasicDescription.fileFormatId = header.fileFormatId;
    this->BasicDescription.channelsPerFrame = header.numChannels;
    this->BasicDescription.bitsPerChannel = header.bitsPerSample;

    this->channels = samples.channels;
}

ADSH::Stream::Stream(const Stream & rhs ) noexcept { *this = rhs; }


ADSH::Stream::Stream(Stream && rhs) noexcept {

    if (this != &rhs) {

        channels = std::move(rhs.channels);
        BasicDescription = std::move(rhs.BasicDescription);
        PacketDescription = std::move(rhs.PacketDescription);
        
		rhs.channels = 0;
	}
}


ADSH::Stream & ADSH::Stream::operator=(const Stream & rhs) noexcept {

    if (this != &rhs) {
        channels = rhs.channels;
        BasicDescription = rhs.BasicDescription;
        PacketDescription = rhs.PacketDescription;
    }

    return *this;
}


ADSH::Stream & ADSH::Stream::operator=(Stream && rhs) noexcept {

    if (this != &rhs) {

        channels = std::move(rhs.channels);
        BasicDescription = std::move(rhs.BasicDescription);
        PacketDescription = std::move(rhs.PacketDescription);

        rhs.channels = 0;
    }

    return *this;
}