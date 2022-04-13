/*
 * palindromeDetector.h
 *
 *  Created on: Mar 23, 2022
 *      Author: bee6, ben elpidius
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

#include "Stack.h"
#include "ArrayQueue.h"
#include <cctype>
using namespace std;

class palindromeDetector {
public:
	// constructors
	palindromeDetector(string& input, string& output); //input and output files
	virtual ~palindromeDetector();

	// getters
	void detectPalindromes();
	bool isPalindrome(const string& str);

private:
//	ArrayQueue<string> myQueue = ArrayQueue<string> (1); // normal
//	Stack<string> myStack = Stack<string> (1); //reversed
	string myInput; // input file
	string myOutput; // output file

//	string forward; // Queue
//	string backward; // Stack
};

#endif /* PALINDROMEDETECTOR_H_ */
