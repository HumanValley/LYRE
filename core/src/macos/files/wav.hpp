#pragma once
// #pragma packed

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

struct Header{ // size = 44 bytes
    
    public: 

        // [BLOC DE DECLARATION DU FICHIER] -- 12 bytes -- 
        
        uint32_t FileTypeBlocId; // "RIFF" (need 4 bytes)
        uint32_t FileSize;
        uint32_t FileFormatId; // "WAVE" (need 4 bytes)

        // [BLOC DE DESCRIPTION DU FICHIER] -- 24 bytes --
        
        uint32_t subChunk1ID; // "fmt " (need 4 bytes)
        uint32_t dwChunkSize;
        uint16_t audioFormat;
        uint16_t numChannels;
        uint32_t sampleRate;
        uint32_t byteRate;
        uint16_t blockAlign;
        uint16_t bitsPerSample;
        
        // [BLOC DE DONNEES] -- 8 bytes --

        uint32_t subChunk2ID; // "data" (need 4 bytes)
        uint32_t subChunk2Size;
};

class Wav {

    public: // ---------- PUBLIC VARIABLES ----------

    protected: // ---------- PROTECTED VARIABLES ----------

    private: // ---------- PRIVATE VARIABLES ----------

        Header header;    
        char * data;
        
    public: // ---------- PUBLIC FUNCTIONS ----------

        Wav();
        Wav(const Wav & src);
        Wav(const std::string path);

        char *readFile(const std::string path);
        

        ~Wav();

        // ---------- GETTERS ----------

        const Header & getHeader();

        // ---------- SETTERS ----------

        void setHeader(const Header & header);

    protected: // ---------- PROTECTED FUNCTIONS ----------

    private: // ---------- PRIVATE FUNCTIONS ----------

        void initHeader(char * buffer);
        void initData(char * buffer);

};

// ---------- OPERATORS ----------
std::ostream & operator<<(std::ostream & o, const Header & rhs);