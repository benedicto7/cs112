/* Experiment1.h measures how long it takes to append an item to a vector or list.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: student: Ben (BEE6) Heonjae (HK238)
 * Date: 8/mar/2022
 */

#ifndef EXPERIMENT1_H_
#define EXPERIMENT1_H_

#include "Timer.h"

class Experiment1 {
public:
	void run();
	void timeAppendToVectorOfSize(unsigned size);
	void timeRepeatedAppendUntilVectorIsSize(unsigned reps);

	void timeAppendToListOfSize(unsigned n);
	void timeRepeatedAppendUntilListIsSize(unsigned n);
private:
	enum repetitions {REPS = 100000};
	Timer myTimer;
};

#endif /*EXPERIMENT1_H_*/
