/*
 * palindromeDetector.cpp
 *
 *  Created on: Mar 23, 2022
 *      Author: bee6, ben elpidius
 */

#include "palindromeDetector.h"
#include <cassert>
#include <fstream>

palindromeDetector::palindromeDetector(string& input, string& output) {
	myInput = input;
	myOutput = output;
}

void palindromeDetector::detectPalindromes() {
	// open input and output file
	ifstream fin(myInput);
	assert(fin.is_open());

	ofstream fout(myOutput);
	assert(fout.is_open());

	string str;
	while(getline(fin, str)) {
		if(isPalindrome(str)) {
			fout << str << " ***";
		}

		else {
			fout << str;
		}

		if(!fin.eof()) {
			fout << "\n";
		}
	}

	fin.close();
	fout.close();
}

bool palindromeDetector::isPalindrome(const string& str) {
	ArrayQueue<char> myQueue(1);
	Stack<char> myStack(1);

	// pushing and appending
	string sentence = str;
	unsigned i = 0;

	while(sentence[i]) {
		if(isalpha(sentence[i])) {
			char lower_case = tolower(sentence[i]);

			try {
				myStack.push(lower_case);
				myQueue.append(lower_case);
			}
			catch (...) {
				myStack.setCapacity(myStack.getCapacity()*2);
				myQueue.setCapacity(myQueue.getCapacity()*2);
				myStack.push(lower_case);
				myQueue.append(lower_case);
			}
		}
		i++;
	}

	// comparing if it is a palindrome
	string forward; // Queue
	string backward; // Stack

	// returns false if it is an empty string
	if (myQueue.isEmpty() || myStack.isEmpty()) {
		return false;
	}

	while (true) {
		if (myQueue.isEmpty() && myStack.isEmpty()) {
			break;
		}

		forward = forward + myQueue.remove();
		backward = backward + myStack.pop();
	}

	return (forward == backward);
}

palindromeDetector::~palindromeDetector() {
	// TODO Auto-generated destructor stub
}
