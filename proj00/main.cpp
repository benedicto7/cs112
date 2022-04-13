/*
 * main.cpp
 *
 *  Created on: Jan 11, 2022
 *      Author: bee6
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
	float array[20];
	cout << sizeof (array) << endl;

	float * x = &array[7];
	*x = 17.771;

	cout << array[7] << endl;
	cout << *x << endl;
}


