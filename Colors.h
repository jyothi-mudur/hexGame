/*
 * Colors.h
 *
 *  Created on: Jan 31, 2018
 *      Author: jyothi
 */

#ifndef COLORS_H_
#define COLORS_H_

#include "defines.h"

class Colors {
public:
	Colors();
	~Colors();
	void vUseColor();
	void vRemoveColor();
	bool bIsColorAvailable() const;
	void init(int count);
private:
	//int maxCount;
	int availableCount;
};

#endif /* COLORS_H_ */
