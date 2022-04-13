/* Experiment2.h declares a class that times the vector and list prepend operations.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: student: Ben (BEE6) Heonjae (HK238)
 * Date: 8/mar/2022
 */
#ifndef EXPERIMENT2_H_
#define EXPERIMENT2_H_

#include "Timer.h"

class Experiment2 {
public:
	void run();
	void timePrependToVectorOfSize(unsigned size);	
	void timeRepeatedPrependUntilVectorIsSize(unsigned reps);
	void timePrependToListOfSize(unsigned size);
	void timeRepeatedPrependUntilListIsSize(unsigned reps);

private:
	enum repetitions {REPS = 100000};
	Timer myTimer;
};

#endif /*EXPERIMENT2_H_*/
