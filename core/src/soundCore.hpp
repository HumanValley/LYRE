#pragma once

#ifdef _WIN32 // Windows defines

    #include <asio.h>

#elif defined(__APPLE__) // macOS defines

    #include <CoreAudio/CoreAudio.h>

#elif defined(__linux__) // Linux defines

    #include <jack/jack.h>

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