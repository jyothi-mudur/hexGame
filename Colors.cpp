/*
 * Colors.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: jyothi
 */

#include "Colors.h"

Colors::Colors() {
	//maxCount = count;
	availableCount = 0;
}

Colors::~Colors() {
	//maxCount = 10;
	availableCount = 0;
}

void Colors::init(int count){
	availableCount = count;
}

bool Colors::bIsColorAvailable() const {
	return (availableCount != 0);
}

void Colors::vUseColor() {
	availableCount -= 1;
}

void Colors::vRemoveColor() {
	availableCount +=1;
}


