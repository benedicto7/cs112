/*
 * main.cpp
 *
 *  Created on: Feb 1, 2022
 *      Author: bee6
 */

#include <cassert>
#include <iostream>
#include "student.h"
#include "Fraction.h"
#include <string>
#include <stdexcept>
using namespace std;

int main(){

	// part 1 ----------------------------
	student aStudent;
	assert(aStudent.getMajor() == "Undecided");
	assert(aStudent.getId() == 0);
	assert(aStudent.getName() == "");
	assert(aStudent.getGpa() == 0.0);

	aStudent.setGpa(4);
	assert(aStudent.getGpa() == 4);
	aStudent.setMajor("Computer Science");
	assert(aStudent.getMajor() == "Computer Science");

	student calvin("Daniel", 2608580);
	assert(calvin.getName() == "Daniel");
	assert(calvin.getId() == 2608580);
	assert(calvin.getGpa() == 0.0);

	cout << "Part 1 all tests passed!" << endl;

	// part 2 ----------------------------

	Fraction number(2,4);
	assert(number.getNumerator() == 1);
	assert(number.getDenominator() == 2);

	number.setNumerator(10);
	number.setDenominator(5);
	assert(number.getNumerator() == 1);
	assert(number.getDenominator() == 1);

	try {
		number.setDenominator(0);
		assert(false);
	} catch (const invalid_argument &ie){
		assert(number.getDenominator() != 0);
		cout << ie.what() << endl;
	}

	Fraction newFrac;
	assert(newFrac.asString() == "0/1");
	newFrac.setNumerator(5);
	newFrac.setDenominator(10);
	assert(newFrac.asString() == "1/2");

	Fraction newFrac_1(20, 10);
	assert(newFrac_1.asString() == "2/1");

	Fraction newFrac_2(100,2);
	newFrac_2.setDenominator(12);
	assert(newFrac_2.asString() == "25/6");

	cout << "Part 2 all tests passed!" << endl;

	return 0;
}


