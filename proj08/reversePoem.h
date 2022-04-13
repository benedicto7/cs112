/*
 * reversePoem.h
 *
 *  Created on: Mar 17, 2022
 *      Author: bee6
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include "Stack.h"
#include <string>
using namespace std;

class reversePoem {
public:
	// explicit
	reversePoem(const string& poemFile);

	// getters
	string getTitle() const {return myTitle;}
	string getAuthor() const {return myAuthor;}
	string getBody() const {return myBody;}
	string getBodyReversed() const {return myBodyReversed;}

private:
	Stack<string> myPoem = Stack<string> (1);

	string myTitle;
	string myAuthor;
	string myBody;
	string myBodyReversed;
};

#endif /* REVERSEPOEM_H_ */
