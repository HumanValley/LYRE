#pragma once

#include <cstdint>
#include "../files/files.hpp"

namespace ADSH {

    struct StreamBasicDescription {

        uint32_t sampleRate;
        uint32_t fileFormatId;
        uint32_t fileFormatFlags;
        uint32_t bytesPerPackets;
        uint32_t framesPerPacket;
        uint32_t channelsPerFrame;
        uint32_t bitsPerChannel;
        uint32_t reserved;
    };

    struct StreamPacketDescription {
        
        uint32_t startOffset;
        uint32_t variableFramesInPacket;
        uint32_t dataByteSize;
    };

    class Stream {

        // VARIABLES
        public: int32_t * channels;
		public: StreamBasicDescription BasicDescription;
		public: StreamPacketDescription * PacketDescription;

        // Constructors & Destructors
        public:	Stream() noexcept;
        public: Stream(WaveHeader & header, Sample & samples) noexcept;
        public: Stream(const Stream & rhs) noexcept;
        public: Stream(Stream && rhs) noexcept;
        public: ~Stream() noexcept;

        // Operators
        public: Stream & operator=(const Stream & rhs) noexcept;
        public: Stream & operator=(Stream && rhs) noexcept;



        void open(const char* path);
        void close();

        void write(void* buffer, uint32_t frames);

        void seek(uint32_t frame);

        uint32_t getFrameCount();
        uint32_t getFramePosition();

    };

} // namespace ADSH
