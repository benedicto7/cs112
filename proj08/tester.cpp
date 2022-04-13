/* tester.cpp is a "driver" to run the tests in the StackTester class.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: ben elpidius
 * Date: March 17, 2022
 */

#include <string>
#include "reversePoem.h"
#include "Stack.h"
#include "StackTester.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	StackTester st;
	st.runTests();
}

