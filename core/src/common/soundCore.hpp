#pragma once

#ifdef _WIN32 // Windows defines

    #include <asio.h>

    #include "../windows/files/wav.hpp"

#elif defined(__APPLE__) // macOS defines

    #include <CoreAudio/CoreAudio.h>

    #include "../macos/files/wav.hpp"

#elif defined(__linux__) // Linux defines

    #include <jack/jack.h>

    #include "../linux/files/wav.hpp"

#else // Other OS

    #error "Système d'exploitation non pris en charge"

#endif

#include <iostream>

class SoundCore {

    public :

        SoundCore();
        ~SoundCore();

    private :

};