/* Experiment0.h declares a class that times the vector subscript operation.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: student: Ben (BEE6) Heonjae (HK238)
 * Date: 8/mar/2022
 */
 
#ifndef EXPERIMENT0_H_
#define EXPERIMENT0_H_

#include "Timer.h"
#include <vector>
using namespace std;

class Experiment0 {
public:
	void run();
	void timeAccessesForVectorOfSize(int size);
	void timeAccessAtIndex(int index);
private:
	enum reps { REPS = 100000 };
	Timer myTimer;
	vector<int> myVector;
};

#endif /*EXPERIMENT0_H_*/
