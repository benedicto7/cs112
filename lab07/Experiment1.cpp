/* Experiment1.cpp defines the methods that measure the time required
 *  to append an item to a vector or list.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: student: Ben (BEE6) Heonjae (HK238)
 * Date: 8/mar/2022
 */
 
 #include "Experiment1.h"

#include <vector>
#include <list>
#include <iomanip>     // setw()
using namespace std;

void Experiment1::run() {
	cout << "\n1a. Timing vector append operations using the average over " << REPS << " repetitions, "
	     << myTimer.getTicksPerSecond() << " ticks/sec..."
	     << endl;
	     
	timeAppendToVectorOfSize(10);
	timeAppendToVectorOfSize(100);
	timeAppendToVectorOfSize(1000);
	timeAppendToVectorOfSize(10000);
	timeAppendToVectorOfSize(100000);
		
	timeRepeatedAppendUntilVectorIsSize(100000);
	

	cout << "\n1a. Timing list append operations using the average over " << REPS << " repetitions, "
	     << myTimer.getTicksPerSecond() << " ticks/sec..."
	     << endl;

	timeAppendToListOfSize(10);
	timeAppendToListOfSize(100);
	timeAppendToListOfSize(1000);
	timeAppendToListOfSize(10000);
	timeAppendToListOfSize(100000);

	timeRepeatedAppendUntilListIsSize(100000);





	cout << "Experiment complete." << endl;
}

void Experiment1::timeAppendToVectorOfSize(unsigned size) {
	cout << " -- time to append to a vector of size "
	     << setw(8) 
	     << size << ":\t" << flush;
	myTimer.reset();
	for (int i = 0; i < REPS; i++) {  // repeatedly...
		vector<int> v(size);      // construct new size-n vector
		myTimer.start();          // start timer
		v.push_back(i);           // append an Item
		myTimer.stop();           // stop timer
	}
	cout << fixed << showpoint        // display average time
	     << myTimer.getTicks() / REPS << " ticks"
	     << endl;
}


void Experiment1::timeRepeatedAppendUntilVectorIsSize(unsigned reps) {
	cout << " ** average time to append to a vector growing from empty to size "
	     << reps << ": " << flush;
	myTimer.reset();
	vector<unsigned> v;                    // construct empty vector
	for (unsigned i = 0; i < reps; i++) {  // repeatedly ...
		myTimer.start();               // start timer
		v.push_back(i);                // append an Item
		myTimer.stop();                // stop timer
	}
	cout << fixed << showpoint             // display average time
	     << myTimer.getTicks() / reps << " ticks" 
	     << endl;
}


void Experiment1::timeAppendToListOfSize(unsigned n){

	cout << " -- time to append to a list of size "
	     << setw(8)
	     << n << ":\t" << flush;
	myTimer.reset();
	for (int i = 0; i < REPS; i++) {  // repeatedly...
		list<int> l(n);      // construct new size-n list
		myTimer.start();          // start timer
		l.push_back(i);           // append an Item
		myTimer.stop();           // stop timer
	}
	cout << fixed << showpoint        // display average time
	     << myTimer.getTicks() / REPS << " ticks"
	     << endl;

}




void Experiment1::timeRepeatedAppendUntilListIsSize(unsigned n){
	cout << " ** average time to append to a list growing from empty to size "
	     << n << ": " << flush;
	myTimer.reset();
	list<unsigned> l;                    // construct empty vector
	for (unsigned i = 0; i < n; i++) {  // repeatedly ...
		myTimer.start();               // start timer
		l.push_back(i);                // append an Item
		myTimer.stop();                // stop timer
	}
	cout << fixed << showpoint             // display average time
	     << myTimer.getTicks() / n << " ticks"
	     << endl;
}



