/* Experiment0.cpp defines methods for timing the vector subscript operation.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: student: Ben (BEE6) Heonjae (HK238)
 * Date: 8/mar/2022
 */

#include "Experiment0.h"
#include <iomanip>    // setw()
using namespace std;
	
void Experiment0::run() {
	cout << "\n0. Timing vector subscript operations using "
	     << myTimer.getTicksPerSecond() << " ticks/sec..."
	     << endl;
	timeAccessesForVectorOfSize(10);
	timeAccessesForVectorOfSize(100);
	timeAccessesForVectorOfSize(1000);
	timeAccessesForVectorOfSize(10000);
	timeAccessesForVectorOfSize(100000);
	cout << "Experiment complete." << endl;
}

void Experiment0::timeAccessesForVectorOfSize(int size) {
	cout << "* timing accesses for vector of size " << size << endl;
	myVector.resize(size);                    // set vector's size
	                                          // then time access to
	timeAccessAtIndex(0);                     // - first  item
	timeAccessAtIndex( myVector.size() / 2 ); // - middle item
	timeAccessAtIndex( myVector.size() - 1 ); // - last item
}

void Experiment0::timeAccessAtIndex(int index) {
	cout << "-- Time to access value at index "  
	     << setw(5) << index << ": " << flush;
	myTimer.reset();                    // clear the timer
	for (int i = 0; i < REPS; i++) {
		myTimer.start();                    // start it
		myVector[index];                    // access item at index
		myTimer.stop();                     // stop it
	}
	cout  << myTimer.getTicks() / REPS << endl; // display results
}
