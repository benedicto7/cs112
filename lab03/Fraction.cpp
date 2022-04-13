/*
 * Fraction.cpp
 *
 *  Created on: Feb 1, 2022
 *      Author: hk238, bee6
 */
#include <iostream>
#include <string>
#include "Fraction.h"
#include <cstdlib>
using namespace std;

/*
 *  (int, int) -> int
 *  This function finds the greatest common divisor of two integers, using
 *  Euclid's algorithm
 */
int computeGCD(int alpha, int beta) {
	alpha = abs(alpha);
	beta = abs(beta);
	int remainder = alpha % beta;
	while (remainder != 0) {
		alpha = beta;
		beta = remainder;
		remainder = alpha % beta;
	}
	return beta;
}

void Fraction::simplify(){
	int gcd = computeGCD(myNumerator, myDenominator);

	if (gcd != 0){
		myNumerator = myNumerator/ gcd;
		myDenominator = myDenominator / gcd;
	}
	if (myDenominator < 0){
		myNumerator = myNumerator * -1;
		myDenominator = myDenominator * -1;
	}
}

Fraction::Fraction() {
	myNumerator = 0;
	myDenominator = 1;
}

Fraction::Fraction(int Numerator, int Denominator) {
	myNumerator = Numerator;
	myDenominator = Denominator;
	simplify();
}

int Fraction::getNumerator(){
	return myNumerator;
}

int Fraction::getDenominator(){
	return myDenominator;
}

void Fraction::setNumerator(int new_Numerator){
	myNumerator = new_Numerator;
	simplify();
}

void Fraction::setDenominator(int new_Denominator){
	if (new_Denominator == 0){
		throw invalid_argument("0 is invalid denominator.");
	}
	myDenominator = new_Denominator;

	simplify();
}

string Fraction::asString(){
	return to_string(myNumerator) +"/" + to_string(myDenominator);
}
