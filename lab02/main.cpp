/*
 * main.cpp (part1.cpp)
 *
 *  Created on: Jan 25, 2022
 *      Author: hk238, BEE6
 */
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <cassert>
#include "functions.h"

int main(){
	cout << "Type your filename: " << endl;
	string filename;
	cin >> filename;

	cout << "Type your number of line: " << endl;
	int number_line;
	cin >> number_line;

	ifstream fin;
	fin.open(filename);
	assert(fin.is_open());

	int *numbers = new int[number_line];

	for(int i=0; i < number_line; i++) {
		fin >> numbers[i];
	}

	fin.close();

	int dup_number = 3;
	assert(findDuplicate(numbers, number_line, dup_number));
	cout << "pass!" << endl;

	int duplicate=0;
	if(findDuplicate(numbers, number_line, duplicate)) {
		cout << "A duplicate was found and its duplicate is " << duplicate << endl;
	}

	else {
		cout << "A duplicate was not found." << endl;
	}

	return 0;
}
