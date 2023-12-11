#pragma once

#include <string>
#include <fstream>
#include <cstdint>
#include <iostream>

#include "../../utils/utils.hpp"

namespace	ADSH {

	struct	WaveHeader {
		
		public:	uint32_t	fileTypeChunkId;	// [4 bytes] (RIFF) DECLARATION BLOCK [12 bytes]
		public:	uint32_t	fileSize;			// [4 bytes] 
		public:	uint32_t	fileFormatId;		// [4 bytes] (WAVE)
	

		public:	uint32_t	formatChunkID;		// [4 bytes] (ftm ) DESCRIPTION BLOCK [24 bytes]
		public:	uint32_t	formatChunkSize;	// [4 bytes] 
		public:	uint16_t	audioFormat;		// [2 bytes] 
		public:	uint16_t	numChannels;		// [2 bytes] 
		public:	uint32_t	sampleRate;			// [4 bytes] 
		public:	uint32_t	byteRate;			// [4 bytes]
		public:	uint16_t	blockAlign;			// [2 bytes] 
		public:	uint16_t	bitsPerSample;		// [2 bytes] 

		public:	uint32_t	dataChunkID;		// [4 bytes] (data) DATA BLOCK [8 bytes]
		public:	uint32_t	dataChunkSize;		// [4 bytes] 
	};

	class	Wave {

		// VARIABLES

		public:		WaveHeader	header;
		public:		char *		data;

		// CONSTRUCTORS & DESTRUCTOR

		public:		Wave() noexcept;							// Default constructor
		public:		Wave(const Wave & rhs) noexcept;			// Copy constructor
		public:		Wave( Wave && rhs) noexcept;				// Move constructor
		public:		~Wave() noexcept;							// Destructor

		friend		std::ostream &	operator<<(std::ostream & o, const Wave & rhs) noexcept;

		// OPERATORS

		public:		Wave &			operator=(const Wave & rhs)noexcept;	// Copy assignment operator
		public:		Wave &			operator=(Wave && rhs) noexcept;		// Move assignment operator

		// METHODS

		public:		void load(const std::string path);
		public:		void build(const WaveHeader header, const char * data);
		public:		void save(const std::string path);

		private:	void _loadHeader(const char * buffer);
		private:	void _loadData(const char * buffer);

	};

} // ADSH