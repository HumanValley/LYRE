#pragma once

#include <cstdint>

struct StreamBasicDescription {

	uint32_t	sampleRate;
	uint32_t	fileFormatId;
	uint32_t	fileFormatFlags;
	uint32_t	bytesPerPackets;
	uint32_t	framesPerPacket;
	uint32_t	channelsPerFrame;
	uint32_t	bitsPerChannel;
	uint32_t	reserved;

};

struct StreamPacketDescription {

	uint32_t startOffset;
	uint32_t variableFramesInPacket;
	uint32_t dataByteSize;
};
