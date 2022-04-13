/*
 * student.h
 *
 *  Created on: Feb 1, 2022
 *      Author: hk238, bee6
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

class student {
public:
	student();
	student(string initial_Name, unsigned int initial_Id);

	string getMajor();
	string getName();
	unsigned int getId();
	float getGpa();

	void setMajor(string newMajor);
	void setGpa(float newGpa);

private:
	string myName;
	unsigned int myId;
	float myGpa;
	string myMajor;

};

#endif /* STUDENT_H_ */
