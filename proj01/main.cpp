/*
 * main.cpp
 *
 *  Created on: Jan 18, 2022
 *      Author: bee6
 */

#include <iostream>
#include <string>
using namespace std;
#include <cassert>
#include "utils.h"
#include <array>

void findNPrimes(unsigned int primes[], unsigned int size) {
	unsigned y = 0;

	while (true) {
		for (unsigned int x = 2; x<=size; x++) {
			if (isPrime(x)) {
				primes[y]=x; //if its prime, inserts the value into the array
				y++;
			}
		}
		break; //breaks when x exceeds the size of the first x primes we are trying to find.
	}
}

int main() {
	assert(isPrime(7) == true);
	assert(isPrime(6) == false);
	assert(isPrime(1) == false); //not prime
	assert(isPrime(2) == true); //prime
	assert(isPrime(4) == false); //not prime
	assert(isPrime(541) == true);

	unsigned int primes[100];
	findNPrimes(primes, 547);
	assert(primes[0] == 2);
	assert(primes[2] == 5);
	assert(primes[99] == 541);

	cout << "All test passed!" << endl;
}
