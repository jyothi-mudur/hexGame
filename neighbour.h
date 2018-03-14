/*
 * neighbour.h
 *
 *  Created on: Jan 30, 2018
 *      Author: jyothi
 */

#ifndef NEIGHBOUR_H_
#define NEIGHBOUR_H_

#include <vector>
#include <map>
#include "defines.h"


class neighbour {
public:
	neighbour();
	~neighbour();
	std::vector<int> getNeighbours(int pos);
	void init();
private:
	std::vector<int> makeVector(int,int,int,int,int,int);
	std::map<int,std::vector<int> > neighbourCells;
};

#endif /* NEIGHBOUR_H_ */
