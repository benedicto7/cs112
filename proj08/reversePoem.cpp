/*
 * reversePoem.cpp
 *
 *  Created on: Mar 17, 2022
 *      Author: bee6
 */

#include "reversePoem.h"
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
using namespace std;

// explicit
reversePoem::reversePoem(const string& poemFile) {
	ifstream fin(poemFile.c_str());
	assert(fin.is_open());

	getline(fin, myTitle);
	getline(fin, myAuthor);

	string empty_line;
	getline(fin, empty_line);

	// reading body of poem from file: top to bottom
	string body;
	while(getline(fin, body))
	{
		myBody += body + "\n";
		try {
			myPoem.push(body);
		}
		catch (StackException& se) {
			myPoem.setCapacity(myPoem.getCapacity()*2);
			myPoem.push(body);
		}
	}

	// reading body of poem from Stack class: bottom to top
	while(1) {
		if (myPoem.isEmpty()) {
			break;
		}
		myBodyReversed += myPoem.pop() + "\n";
	}
	fin.close();
}
