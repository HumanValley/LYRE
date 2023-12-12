#pragma once

#include "string.h"
#include <fstream>
#include <cstdint>
#include <iostream>

#include "../../utils/utils.hpp"

namespace	ADSH {

	struct Sample {
		public: int32_t * channels; // channels[0] = data of left channel, channels[1] = data of right channel, etc...
	};

	struct	WaveHeader {
		
        // DECLARATION BLOCK [12 bytes]
		public:	uint32_t	fileTypeChunkId;	// [4 bytes] (RIFF) 
		public:	uint32_t	fileSize;			// [4 bytes] 
		public:	uint32_t	fileFormatId;		// [4 bytes] (WAVE)
        // DESCRIPTION BLOCK [24 bytes]
		public:	uint32_t	formatChunkID;		// [4 bytes] (ftm )
		public:	uint32_t	formatChunkSize;	// [4 bytes] 
		public:	uint16_t	audioFormat;		// [2 bytes] 
		public:	uint16_t	numChannels;		// [2 bytes] 
		public:	uint32_t	sampleRate;			// [4 bytes] 
		public:	uint32_t	byteRate;			// [4 bytes]
		public:	uint16_t	blockAlign;			// [2 bytes] 
		public:	uint16_t	bitsPerSample;		// [2 bytes] 
        // DATA BLOCK [8 bytes]
		public:	uint32_t	dataChunkID;		// [4 bytes] (data)
		public:	uint32_t	dataChunkSize;		// [4 bytes] 
	};

	class	Wave {

		// VARIABLES

		public:		WaveHeader	header;
		public:		Sample *	data;

		// CONSTRUCTORS & DESTRUCTOR

		public:		Wave() noexcept;							// Default constructor
		public:		Wave(const Wave & rhs) noexcept	;		// Copy constructor
		public:		Wave( Wave && rhs) noexcept;				// Move constructor
		public:		~Wave() noexcept;							// Destructor

		// OPERATORS

		public:		Wave &		operator=(const Wave & rhs) noexcept;	// Copy assignment operator
		public:		Wave &		operator=(Wave && rhs) noexcept;		// Move assignment operator

		// GETTERS

		public:		uint32_t	getSamplesNumber() const noexcept;

		// METHODS

		public:		void load(const std::string path);
		public:		void build(const WaveHeader header, const char * data);
		public:		void save(const std::string path);

		private:	char * _loadHeader(char * buffer);
		private:	void _loadData(const char * buffer);

	};

} // ADSH

	std::ostream &	operator<<(std::ostream & o, const ADSH::Wave & rhs) noexcept;
