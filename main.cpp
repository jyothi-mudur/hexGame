/*
 * main.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: jyothi
 */
#include <iostream>
#include <string>
#include "hexGrid.h"

int main() {
	hexGrid* hexGame = new hexGrid();
	std::cout << "Starting Hex Game..." << std::endl;

	hexGame->init();
	if(hexGame->bCheckNeighbours()) {
		std::cout << "Checked neighbours.. Verified! :)" << std::endl;

		hexGame->vSolve(1);
	} else {
		std::cout << "Wrong neighbours" << std::endl;
	}

	std::cout << "Done! :)" << std::endl;

	delete hexGame;
	return 0;
}



