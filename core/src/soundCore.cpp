#include "./soundCore.hpp"

SoundCore::SoundCore() {

    #ifdef _WIN32 // Windows constructor

        std::cout << "Windows" << std::endl;

    #elif defined(__APPLE__) // macOS constructor

        std::cout << "macOS" << std::endl;

    #elif defined(__linux__) // Linux constructor

        std::cout << "Linux" << std::endl;

    #else // Other OS

        #error "Système d'exploitation non pris en charge"

    #endif

}

SoundCore::~SoundCore() {
    
}