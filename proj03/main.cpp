/*
 * main.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: bee6, Ben
 */

#include <iostream>
#include <string>
#include <cassert>
#include "HighScores.h"
#include <stdexcept>
using namespace std;

int main(){

	HighScores scores;

	// prints out the values inside the array before any high score is added
	for(int i=0; i<10; i++)
	{
		cout << scores.getScore(i) << endl;
	}
	cout << endl;

	assert(scores.getNumScores() == 0);
	scores.addScore(30);
	assert(scores.getNumScores() == 1);

	// adds values 0-9 into the array
	for(int i=0; i<10; i++)
	{
		scores.addScore(i);
	}

	assert(scores.getNumScores() == 10);

	// prints out the values inside the array after high scores has been added and arranged
	for(int i=0; i<10; i++)
	{
		cout << scores.getScore(i) << endl;
	}
	cout << endl;

	assert(scores.getScore(0) == 30);
	assert(scores.getScore(1) == 9);
	assert(scores.getScore(6) == 4);
	assert(scores.getScore(9) == 1);

	try{
		scores.getScore(10);
		assert(false);
	}
	catch(const invalid_argument &ie) {
		cout << ie.what() << endl;
	}

	cout << endl;

	// adds more value into the array and arranges
	scores.addScore(25);
	scores.addScore(20);
	scores.addScore(50);
	scores.addScore(78);
	scores.addScore(22);
	scores.addScore(21);
	scores.addScore(1);
	scores.addScore(52);
	scores.addScore(99);
	scores.addScore(100);
	scores.addScore(2);
	scores.addScore(5);
	scores.addScore(4);

	// prints out the value after new high scores has been added
	for(int i=0; i<10; i++)
	{
		cout << scores.getScore(i) << endl;
	}

	cout << endl;
	cout << "All test passed!!!" << endl;
	cout << endl;
	cout << "Yes!!!" << endl;

	return 0;
}


