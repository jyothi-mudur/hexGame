/*
 * hexCell.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: jyothi
 */

#include "hexCell.h"

hexCell::hexCell() {
	// TODO Auto-generated constructor stub
	mColor = DEF;
}

hexCell::~hexCell() {
	// TODO Auto-generated destructor stub
	mColor = DEF;
}
eColor hexCell::bGetColor() const {
	return mColor;
}

bool hexCell::bIsEmpty() {
	if (DEF == bGetColor()) {
		return true;
	} else {
		return false;
	}
}

void hexCell::vSetColor(eColor col) {
	mColor = col;
}

void hexCell::initHexCell() {
	vSetColor(DEF);
}

