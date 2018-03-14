/*
 * hexGrid.h
 *
 *  Created on: Jan 30, 2018
 *      Author: jyothi
 */

#ifndef HEXGRID_H_
#define HEXGRID_H_

#include "hexCell.h"
#include "defines.h"
#include "neighbour.h"
#include "PositionColor.h"
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <iostream>

class hexGrid {
public:
	hexGrid();
	~hexGrid();
	void init();
	//bool solve(int);
	bool bVerifySolution();
	void vSolve(int);
	bool bCheckNeighbours();

private:
	hexCell mHexBoard[MAX_HEXCELLS+1];
	PositionColor mPosCol;
	static int count;

	bool bIsHexCellEmpty(int pos);
	void place(eColor color, int pos);
	void remove(eColor color, int pos);
	void printGrid();
	std::string sGetStringCol(eColor color);
	std::set<eColor> getColorChoices(int pos);
	eColor GetDefNeighbourColor(int);
	bool bVerifyCell(int pos);
	bool bVerifyColorCount();
};

#endif /* HEXGRID_H_ */
