#include "wave.hpp"


void volumeUp(ADSH::Wave &wavefile, float volume) {

    const uint32_t samplesLen = wavefile.getSamplesNumber();
	for (int i = 0; i < samplesLen; i++)
        for (int j = 0; j < wavefile.header.numChannels; j++)
            wavefile.data[i].channels[j] *= volume;
}

void volumeDown(ADSH::Wave &wavefile, float volume) {

    const uint32_t samplesLen = wavefile.getSamplesNumber();
    for (int i = 0; i < samplesLen; i++)
        for (int j = 0; j < wavefile.header.numChannels; j++)
            wavefile.data[i].channels[j] /= volume;
}

int main() {
    ADSH::Wave wavefile;

    wavefile.load("./piano2.wav");
    volumeDown(wavefile, 2);
    wavefile.save("./piano2_louder.wav");
    return 0;
}