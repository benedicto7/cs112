/* Experiment2.cpp defines the methods that measure the time required
 *  to prepend an item to a vector or list.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: student: Ben (BEE6) Heonjae (HK238)
 * Date: 8/mar/2022
 */
#include "Experiment2.h"

#include <iostream>
#include <iomanip>    // setw()
#include <vector>
#include <list>
using namespace std;

void Experiment2::run() {
	cout << "\n2a. Timing vector prepend operations using the average over " << REPS << " repetitions, "
	     << myTimer.getTicksPerSecond() << " ticks/sec..."
	     << endl;

	timePrependToVectorOfSize(10);
	timePrependToVectorOfSize(100);
	timePrependToVectorOfSize(1000);
	timePrependToVectorOfSize(10000);
	timePrependToVectorOfSize(100000);
	
	timeRepeatedPrependUntilVectorIsSize(100000);
	

	cout << "\n2a. Timing list prepend operations using the average over " << REPS << " repetitions, "
	     << myTimer.getTicksPerSecond() << " ticks/sec..."
	     << endl;

	timePrependToListOfSize(10);
	timePrependToListOfSize(100);
	timePrependToListOfSize(1000);
	timePrependToListOfSize(10000);
	timePrependToListOfSize(100000);

	timeRepeatedPrependUntilListIsSize(100000);

	cout << "Experiment complete." << endl;





}

void Experiment2::timePrependToVectorOfSize(unsigned size) {
	cout << " - time to prepend to a vector of size "
	     << setw(8) 
	     << size << ":\t" << flush;
	myTimer.reset();
	for (unsigned i = 0; i < REPS; i++) {  // repeatedly...
		vector<unsigned> v(size);      // construct new size-n vector
		myTimer.start();               // start timer
		v.insert( v.begin(), i);       // prepend item
		myTimer.stop();                // stop timer
	}
	cout << fixed << showpoint             // compute average time
	     << myTimer.getTicks() / REPS << " ticks"
	     << endl;
	
}


void Experiment2::timeRepeatedPrependUntilVectorIsSize(unsigned reps) {
	cout << " - average time to prepend to a vector growing from empty to size "
	     << reps << ": " << flush;
	myTimer.reset();
	vector<unsigned> v;                    // costruct new empty vector
	for (unsigned i = 0; i < reps; i++) {  // repeatedly...
		myTimer.start();               // start timer
		v.insert( v.begin(), i );      // prepend item
		myTimer.stop();                // stop timer
	}
	cout << fixed << showpoint             // compute average time
	     << myTimer.getTicks() / reps << " ticks" 
	     << endl;
}



void Experiment2::timePrependToListOfSize(unsigned n){


	cout << " - time to prepend to a list of size "
	     << setw(8)
	     << n << ":\t" << flush;
	myTimer.reset();
	for (unsigned i = 0; i < REPS; i++) {  // repeatedly...
		list<unsigned> l(n);      // construct new size-n vector
		myTimer.start();               // start timer
		l.push_front(i);       // prepend item
		myTimer.stop();                // stop timer
	}
	cout << fixed << showpoint             // compute average time
	     << myTimer.getTicks() / REPS << " ticks"
	     << endl;

}




void Experiment2::timeRepeatedPrependUntilListIsSize(unsigned n){
	cout << " - average time to prepend to a list growing from empty to size "
	     << n << ": " << flush;
	myTimer.reset();
	list<unsigned> l;                    // costruct new empty vector
	for (unsigned i = 0; i < n; i++) {  // repeatedly...
		myTimer.start();               // start timer
		l.push_front(i);               // prepend item
		myTimer.stop();                // stop timer
	}
	cout << fixed << showpoint             // compute average time
	     << myTimer.getTicks() / n << " ticks"
	     << endl;


}
