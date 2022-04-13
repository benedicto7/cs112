/*
 * App.h
 *
 *  Created on: Feb 27, 2020
 *      Author: vtn2
 *      ben elpidius, 10 feb 2022
 */

#ifndef APP_H_
#define APP_H_

#include "Vec.h"

class App {
public:
	App();
	void run();

private:
	unsigned printInstructions();
	Vec getStartingPosition(unsigned numDims);
	Vec getVectors(const Vec & startVec);
	void printResults(const Vec &start, const Vec &end);
	Vec getVectorFromUser(unsigned numDims);
};

#endif /* APP_H_ */
