/*
 * hexCell.h
 *
 *  Created on: Jan 30, 2018
 *      Author: jyothi
 */

#ifndef HEXCELL_H_
#define HEXCELL_H_

#include "defines.h"

class hexCell {
public:
	hexCell();
	~hexCell();
	bool bIsEmpty();
	eColor bGetColor() const;
	void initHexCell();
	void vSetColor(eColor col);
private:
	eColor mColor;
};

#endif /* HEXCELL_H_ */
