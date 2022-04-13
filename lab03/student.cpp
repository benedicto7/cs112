/*
 * student.cpp
 *
 *  Created on: Feb 1, 2022
 *      Author: hk238, bee6
 */

#include "student.h"
#include <iostream>
#include <string>
using namespace std;

student::student() {
	myName = "";
	myId = 0;
	myGpa = 0.0;
	myMajor = "Undecided";
}

student::student(string initial_Name, unsigned int initial_Id){
	myName = initial_Name;
	myId = initial_Id;
	myGpa = 0.0;
	myMajor = "Undecided";
}

string student::getMajor(){
	return myMajor;
}

float student::getGpa(){
	return myGpa;
}

unsigned int student::getId(){
	return myId;
}

string student::getName(){
	return myName;
}

void student::setMajor(string newMajor){
	myMajor = newMajor;
}

void student::setGpa(float newGpa){
	myGpa = newGpa;
}
