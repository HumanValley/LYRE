#pragma once

#include <iostream>

#include "../lib/shell/inc/shell.hpp"

class	audioShellTester {
	
	public:		audioShellTester() {}
	public:		~audioShellTester() {}
	
	// METHODS

	public:		void	waveTest() {

		ADSH::Wave wave;

		// wave.load("test.wav");

		// std::cout << wave << std::endl;
	}

	public:		void	fileTest() {

		this->waveTest();
	}
	
};