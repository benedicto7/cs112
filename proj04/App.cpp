/*
 * App.cpp
 *
 *  Created on: Feb 27, 2020
 *      Author: vtn2
 *      ben elpidius, 10 feb 2022
 */

#include "App.h"
#include <iostream>
#include "Vec.h"
using namespace std;

App::App() {}

// runs the app
void App::run() {
    unsigned numDims = printInstructions();
    Vec startingPos = getStartingPosition(numDims);
    Vec resultingPos = getVectors(startingPos);
    printResults(startingPos, resultingPos);
}

// asks the user to type in the number of dimension
unsigned App::printInstructions() {
    unsigned numDims;
    cout << "This application simulates how to move through space by\nadding "
            "together any number of vectors of a given size."
         << endl;
    cout << "How many dimensions would you like to work with? ";
    cin >> numDims;
    return numDims;
}

// gets the starting position based on the number of dimension
Vec App::getStartingPosition(unsigned numDims) {
    cout << "Enter starting position: " << endl;
    return getVectorFromUser(numDims);
}

// user types in the position based on the number of dimension and reads from it
Vec App::getVectorFromUser(unsigned numDims) {
	Vec sum(numDims);
	sum.readFrom(cin);

	return sum;
}

// adds the vector together using addition operator
Vec App::getVectors(const Vec& startVec) {
    char yorn;
    Vec res(startVec);
    while (true) {
        cout << "Do you want to enter another vector? (y/n): ";
        cin >> yorn;
        if (yorn == 'y') {
            Vec v = getVectorFromUser(startVec.getSize());
            res = res + v;
        } else {
            break;
        }
    }
    return res;
}

// prints the initial and final position
void App::printResults(const Vec &start, const Vec &end) {
	cout << "Initial Position:" << endl;
	start.writeTo(cout);

	cout << endl;

	cout << "Final Position:" << endl;
	end.writeTo(cout);
}
