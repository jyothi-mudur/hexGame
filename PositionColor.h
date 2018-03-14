/*
 * PositionColor.h
 *
 *  Created on: Jan 31, 2018
 *      Author: jyothi
 */

#ifndef POSITIONCOLOR_H_
#define POSITIONCOLOR_H_

#include "neighbour.h"
#include "hexCell.h"
#include "Colors.h"

class PositionColor {
public:
	PositionColor();
	~PositionColor();
	void init();
	void vSetColor(eColor);
	void vRemoveColor(eColor);
	bool bCheckIfColorIsAvailable(eColor color);
private:
	Colors myColor[4];
	neighbour myNeighbour;
	hexCell myCell;
};

#endif /* POSITIONCOLOR_H_ */
