/*
 * PositionColor.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: jyothi
 */

#include "PositionColor.h"

PositionColor::PositionColor() {
	init();
}

PositionColor::~PositionColor() {
	init();
}

void PositionColor::init() {
	for(int i=0;i<4;i++){
		myColor[i].init(MAX_COLOR_COUNT);
	}
	// 0 - G, 1 - Y, 2 - R,  3 - B
}

void PositionColor::vSetColor(eColor color) {
	myColor[color].vUseColor();
}

void PositionColor::vRemoveColor(eColor color) {
	myColor[color].vRemoveColor();
}

bool PositionColor::bCheckIfColorIsAvailable(eColor color) {
	return (myColor[color].bIsColorAvailable());
}

