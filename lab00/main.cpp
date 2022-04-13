 /* main.cpp
  * Student name: Ben Elpidius
  * Date: Jan 11, 2022
  * Author: Prof. Victor Norman
  * For: CS 112, Lab 0 at Calvin University.
  */

#include <iostream>
#include <string>
#include "utils.h"
using namespace std;

int main() {
	string name = "Ben";
	int course = courseNumber();
	cerr << "Welcome to CS" << course << " and C++, " << name << endl;
	return 0;
}



