/*
 * neighbour.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: jyothi
 */

#include "neighbour.h"

neighbour::neighbour() {
	init();
}

neighbour::~neighbour() {
	neighbourCells.clear();
}

std::vector<int> neighbour::makeVector
	(int a, int b, int c, int d, int e, int f) {
	std::vector<int> result;
	result.push_back(a);
	result.push_back(b);
	result.push_back(c);
	result.push_back(d);
	result.push_back(e);
	result.push_back(f);

	return result;
}

void neighbour::init() {
	// fill up the map
	std::vector<int> neighbourVector;

	for (int i = 1; i<= MAX_HEXCELLS; i++) {
		switch(i) {
			case 1:{
				neighbourVector = makeVector(RED,RED,BLUE,2,5,6);
				break;
			}
			case 2:{
				neighbourVector = makeVector(RED,RED,1,3,7,6);
				break;
			}
			case 3:{
				neighbourVector = makeVector(RED,GREEN,2,4,7,8);
				break;
			}
			case 4:{
				neighbourVector = makeVector(GREEN,GREEN,GREEN,3,8,9);
				break;
			}
			case 5:{
				neighbourVector = makeVector(BLUE,BLUE,1,6,15,16);
				break;
			}
			case 6:{
				neighbourVector = makeVector(1,2,5,7,14,15);
				break;
			}
			case 7:{
				neighbourVector = makeVector(2,3,6,8,13,14);
				break;
			}
			case 8:{
				neighbourVector = makeVector(3,4,7,9,12,13);
				break;
			}
			case 9:{
				neighbourVector = makeVector(GREEN,4,8,10,11,12);
				break;
			}
			case 10:{
				neighbourVector = makeVector(GREEN,GREEN,BLUE,BLUE,9,11);
				break;
			}
			case 11:{
				neighbourVector = makeVector(BLUE,9,10,12,22,23);
				break;
			}
			case 12:{
				neighbourVector = makeVector(8,9,11,13,21,22);
				break;
			}
			case 13:{
				neighbourVector = makeVector(7,8,12,14,20,21);
				break;
			}
			case 14:{
				neighbourVector = makeVector(6,7,13,15,19,20);
				break;
			}
			case 15:{
				neighbourVector = makeVector(5,6,14,16,18,19);
				break;
			}
			case 16:{
				neighbourVector = makeVector(BLUE,BLUE,5,15,17,18);
				break;
			}
			case 17:{
				neighbourVector = makeVector(BLUE,YELLOW,YELLOW,16,18,29);
				break;
			}
			case 18:{
				neighbourVector = makeVector(15,16,17,19,28,29);
				break;
			}
			case 19:{
				neighbourVector = makeVector(14,15,18,20,27,28);
				break;
			}
			case 20:{
				neighbourVector = makeVector(13,14,19,21,26,27);
				break;
			}
			case 21:{
				neighbourVector = makeVector(12,13,20,22,25,26);
				break;
			}
			case 22:{
				neighbourVector = makeVector(11,12,21,23,24,25);
				break;
			}
			case 23:{
				neighbourVector = makeVector(BLUE,BLUE,YELLOW,11,22,24);
				break;
			}
			case 24:{
				neighbourVector = makeVector(YELLOW,YELLOW,22,23,25,35);
				break;
			}
			case 25:{
				neighbourVector = makeVector(21,22,24,26,34,35);
				break;
			}
			case 26:{
				neighbourVector = makeVector(20,21,25,27,33,34);
				break;
			}
			case 27:{
				neighbourVector = makeVector(19,20,26,28,32,33);
				break;
			}
			case 28:{
				neighbourVector = makeVector(18,19,27,29,31,32);
				break;
			}
			case 29:{
				neighbourVector = makeVector(YELLOW,17,18,28,30,31);
				break;
			}
			case 30:{
				neighbourVector = makeVector(YELLOW,YELLOW,GREEN,GREEN,29,31);
				break;
			}
			case 31:{
				neighbourVector = makeVector(GREEN,28,29,30,32,39);
				break;
			}
			case 32:{
				neighbourVector = makeVector(27,28,31,33,38,39);
				break;
			}
			case 33:{
				neighbourVector = makeVector(26,27,32,34,37,38);
				break;
			}
			case 34:{
				neighbourVector = makeVector(26,25,33,35,36,37);
				break;
			}
			case 35:{
				neighbourVector = makeVector(YELLOW,YELLOW,24,25,34,36);
				break;
			}
			case 36:{
				neighbourVector = makeVector(YELLOW,YELLOW,RED,34,35,37);
				break;
			}
			case 37:{
				neighbourVector = makeVector(RED,RED,33,34,36,38);
				break;
			}
			case 38:{
				neighbourVector = makeVector(RED,RED,32,33,37,39);
				break;
			}
			case 39:{
				neighbourVector = makeVector(GREEN,GREEN,RED,31,32,38);
				break;
			}
		} // switch
		neighbourCells.insert
			(std::pair<int,std::vector<int> >(i,neighbourVector));
	} // for
}

std::vector<int> neighbour::getNeighbours(int pos) {
	std::map<int, std::vector<int> >::iterator it;
	std::vector<int> myNeighbours;
	it = neighbourCells.find(pos);

	if(it != neighbourCells.end()) {
		myNeighbours = it->second;
	}
	return myNeighbours;
}
