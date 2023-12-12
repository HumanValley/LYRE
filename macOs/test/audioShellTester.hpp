#pragma once

#include "../lib/audioShell/inc/shell.hpp"

class	audioShellTester {
	
	public:		audioShellTester() {}
	public:		~audioShellTester() {}
	
	// METHODS

	public:		void	waveTest() {

		ADSH::Wave wave;

		wave.load("../test/assets/piano2.wav");

		std::cout << wave << std::endl;
	}

	public:		void	fileTest() {

		this->waveTest();
	}
	
};