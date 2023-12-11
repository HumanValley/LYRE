#include "../lib/shell/src/files/files.hpp"

int main() {
    ADSH::Wave wavefile;

    wavefile.load("../test/assets/piano2.wav");
    return 0;
}