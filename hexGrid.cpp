/*
 * hexGrid.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: jyothi
 */

#include "hexGrid.h"

int hexGrid::count = 0;

hexGrid::hexGrid() {
	init();
}

hexGrid::~hexGrid() {
	init();
}

void hexGrid::init() {
	for(int i=1;i<=MAX_HEXCELLS;i++) {
		mHexBoard[i].vSetColor(DEF);
	}
	mPosCol.init();
}

std::string hexGrid::sGetStringCol(eColor color) {
	std::string result="";
	switch(color) {
		case G:{
			result = "Green";
			break;
		}
		case Y:{
			result = "Yellow";
			break;
		}
		case R:{
			result = "Red";
			break;
		}
		case B:{
			result = "Blue";
			break;
		}
		case DEF:{
			result = "White";
			break;
		}
	}//switch
	return result;
}

void hexGrid::printGrid() {
	count++;
	std::cout << "Trial No: " << count << "\t";
	for(int i=1;i<=MAX_HEXCELLS;i++) {
		std::cout << i <<"-" \
				<< sGetStringCol(mHexBoard[i].bGetColor()) << "\t";
	}
	std::cout << std::endl;

	// verify the solution
	if(bVerifySolution()) {
		std::cout << "Solution is verified!" << std::endl;
	} else {
		std::cout << "Solution is not correct!" << std::endl;
	}
}

bool hexGrid::bIsHexCellEmpty(int pos) {
	return (mHexBoard[pos].bIsEmpty());
}

void hexGrid::remove(eColor color,int pos) {
	mHexBoard[pos].vSetColor(DEF);
	mPosCol.vRemoveColor(color);
}

eColor hexGrid::GetDefNeighbourColor(int neighbourPos) {
	eColor color = DEF;
	switch(neighbourPos) {
		case GREEN:{
			color = G;
			break;
		}
		case YELLOW:{
			color = Y;
			break;
		}
		case RED:{
			color = R;
			break;
		}
		case BLUE:{
			color = B;
			break;
		}
		default:{
			color = DEF;
			break;
		}
	} // switch
	return color;
}

std::set<eColor> hexGrid::getColorChoices(int pos) {
	eColor colorPossible[4] = {G,Y,R,B};
	std::set<eColor> colorsPossible(colorPossible, colorPossible+4);

	// check if the cell is empty
	bool bValue = true ; //bIsHexCellEmpty(pos);
	if (bValue == true) {
		// get the neighbours and their colors
		neighbour myNeighbour;
		std::vector<int> neighbours = myNeighbour.getNeighbours(pos);
		std::set<eColor> neighbourColors;

		std::set<eColor>::iterator it;

		// get the choices available
		for (unsigned int i=0;i < neighbours.size();i++) {
			eColor neighbourColor = DEF;
			if (neighbours[i] > DEFAULT) {
				neighbourColor = GetDefNeighbourColor(neighbours[i]);
			} else
			{
				neighbourColor = mHexBoard[neighbours[i]].bGetColor();
			}
		    neighbourColors.insert(neighbourColor);
		}

		for (it = neighbourColors.begin();it != neighbourColors.end();it++) {
			colorsPossible.erase(*it);
		}

		for(it=colorsPossible.begin();it!= colorsPossible.end();) {
			eColor colorToCheck = *it;
			bool bCheck = mPosCol.bCheckIfColorIsAvailable(colorToCheck);
			if (false ==  bCheck) {
				colorsPossible.erase(it++);
			} else {
				++it;
			}
		}
	}
	return colorsPossible;
}

void hexGrid::place(eColor color, int pos) {
	mHexBoard[pos].vSetColor(color);
	mPosCol.vSetColor(color);
}

bool hexGrid::bCheckNeighbours() {
	bool bReturn = false;
	neighbour myNeighbour;
	std::vector<int> neighbourCells;
	int cellNo = 0;
	for(int pos = 1; pos < MAX_HEXCELLS+1; pos++) {
		neighbourCells = myNeighbour.getNeighbours(pos);
		cellNo = pos;

		// verify
		for(unsigned int index=0; index < neighbourCells.size(); index++) {
			if (neighbourCells[index] < DEFAULT) {
				std::vector<int> neighbourNeighbour;
				neighbourNeighbour = myNeighbour.getNeighbours(neighbourCells[index]);

				for (unsigned int nCell=0;nCell < neighbourNeighbour.size();nCell++) {
					if (cellNo == neighbourNeighbour[nCell]) {
						bReturn = true;
					}
				}
				if (bReturn == false) {
					std::cout << cellNo << "has wrong neighbour:" << neighbourCells[index] << std::endl;
				}
			}
		}
	}
	return bReturn;
}

void hexGrid::vSolve(int pos){
	if (pos > MAX_HEXCELLS) {
		printGrid();
	} else {
		std::set<eColor> vChoices = getColorChoices(pos);
		std::set<eColor>::iterator it;
		for(it=vChoices.begin();it!=vChoices.end();it++) {
			place(*it,pos);
			vSolve(pos+1);
			remove(*it,pos);
		}
	}
}


bool hexGrid::bVerifyCell(int pos) {
	bool bReturn = true;

	// get neighbours
	neighbour myNeighbour;
	std::vector<int> neighbourCells = myNeighbour.getNeighbours(pos);

	// get position color
	eColor posColor = mHexBoard[pos].bGetColor();

	// get neighbour colors and compare
	for (unsigned int index=0;index < neighbourCells.size();index++) {
		eColor neighbourColor = DEF;
		if (neighbourCells[index] > DEFAULT) {
			neighbourColor = GetDefNeighbourColor(neighbourCells[index]);
		} else
		{
			neighbourColor = mHexBoard[neighbourCells[index]].bGetColor();
		}
	    if (posColor == neighbourColor) {
	    	bReturn = false;
	    	break;
	    }
	}
	return bReturn;
}

bool hexGrid::bVerifyColorCount(){
	bool bReturn = true;
	int tGreen=0, tYellow = 0, tBlue = 0, tRed = 0;
	for (int pos = 1; pos < MAX_HEXCELLS+1; pos++) {
		eColor color = mHexBoard[pos].bGetColor();

		switch(color) {
			case G:{
				tGreen++;
				break;
			}
			case Y:{
				tYellow++;
				break;
			}
			case R:{
				tRed++;
				break;
			}
			case B:{
				tBlue++;
				break;
			}
			default:{
				break;
			}
		} // switch

		if ((tGreen > MAX_COLOR_COUNT) || (tBlue > MAX_COLOR_COUNT) ||
				(tRed > MAX_COLOR_COUNT) || (tYellow > MAX_COLOR_COUNT)) {
			bReturn = false;
			break;
		}
	}
	return bReturn;
}

bool hexGrid::bVerifySolution() {
	bool result = true;
	for (int pos = 1; pos <= MAX_HEXCELLS && result; pos++) {
		result = result && bVerifyCell(pos);
		if (!result){
			std::cout << "failed for " << pos << std::endl;
		}
	}
	result = result && bVerifyColorCount();
	return result;
}
