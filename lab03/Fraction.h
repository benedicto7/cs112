/*
 * Fraction.h
 *
 *  Created on: Feb 1, 2022
 *      Author: hk238, bee6
 */
#include <iostream>
#include <string>
using namespace std;


#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {
public:
	Fraction();
	Fraction(int Numerator, int Denominator);

	int getNumerator();
	int getDenominator();

	void setNumerator(int new_Numerator);
	void setDenominator(int new_Denominator);

	string asString();

private:
	int myNumerator;
	int myDenominator;
	void simplify();

};

#endif /* FRACTION_H_ */
