/*
 * HighScores.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: bee6, Ben Elpidius
 */

#include "HighScores.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

HighScores::HighScores() {
	myNumScores = 0;
}

int HighScores::getNumScores(){
	return myNumScores;
}

int HighScores::getScore(int i){
	if(i >= 10)
	{
		throw invalid_argument("Index is out of range.");
	}

	return myScores[i];
}

int HighScores::findLocationToInsert(int newScore) {
	// compares newScore to each values in the array to find location k, where to insert the new score
	for(int k=0; k<10; k++)
	{
		if(newScore > myScores[k])
		{
			return k; // location of index
		}
	}
	return -1;
}

void HighScores::shiftUp(int fromIndex) {
	// shift the value from index 9 to fromIndex (k)
	for(int i=9; i>(fromIndex); i--)
	{
		myScores[i] = myScores[i-1];
	}
}

void HighScores::addScore(int aScore){
	if(aScore > myScores[9])
	{
		int k = findLocationToInsert(aScore);
		shiftUp(k);
		myScores[k] = aScore;
	}

	if(myNumScores > 9)
	{
		return;
	}

	myNumScores = myNumScores + 1;
}

