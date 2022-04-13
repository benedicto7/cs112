/*
 * HighScores.h
 *
 *  Created on: Feb 3, 2022
 *      Author: bee6, Ben Elpidius
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef HIGHSCORES_H_
#define HIGHSCORES_H_

class HighScores {
public:
	HighScores();

	// getters
	int getNumScores();
	int getScore(int i);


	// setters
	void addScore(int aScore);

private:
	int myNumScores;
	int myScores[10] = {};

	int findLocationToInsert(int newScore);
	void shiftUp(int fromIndex);

};

#endif /* HIGHSCORES_H_ */
