#pragma once

#include "./wave/wave.hpp"
#include "./flac/flac.hpp"


//  00100001 - 8 bits, 1 bytes | 1 octets
//  
//  buffer -> 00111000101010101010101010;
//  exemple : fileTypeChunkId (32 bits) -> 4 bytes (4 * 8 = 32 bits)
//
//  STOCKAGE DU SON:
//
//  numChannels (nombre de canaux [1 = mono , 2 = stereo]) | bitsPerSample (nombre de bits dans un sample [8, 16, 24])
//
// son actuel : 16 bits (2 bytes) | 1 canal (mono)
//  data = |255 + 120|130 + 200| 2 samples
//  255 = 11111111
//  120 = 01111000
//  1er sample = 11111111 01111000 = 65496
//
//  2 canaux (stereo) : 24 bits
// data = |255 + 120 + 130| 1 sample left
// left = 11111111 01111000 = 65496
// right = 10000010 11001000 = 33416
// all datas ---> class Sample