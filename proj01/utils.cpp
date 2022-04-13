/*
 * utils.cpp
 *
 *  Created on: Jan 18, 2022
 *      Author: bee6
 */

#include "utils.h"

double constrain(double value, double low, double high) {
	if (value > high) {
		return high;
	}
	else if (value < low) {
		return low;
	}
	else {
		return value;
	}
}

int isPrime(unsigned int n) {
	for (unsigned int x=2;x<=(n/2);x++) {
		if ((n%x)==0) {
			return false; //not prime
		}
	}
	if (n==1) {
		return false; //not prime
	}

	else if (n==2) {
		return true; //prime
	}

	return true; //prime
}



