/*
 * main.cpp
 *
 *  Created on: Jan 25, 2022
 *      Author: Ben Elpidius, bee6
 */

#include <cassert>
#include <string>
#include <iostream>
using namespace std;
#include <cassert>
#include <iomanip>

int main() {

	// Checks if it is odd and between 1 to 15 inclusive
	cout << "Enter an odd number between 1 to 15 inclusive: ";
	int x;
	cin >> x;

	if((x>15) || (x<1) || (x%2==0))
	{
		cerr << "Error! The number you have entered is invalid." << endl;
		cerr << "Proceeding to quit program..." << endl;
		exit(1);
	}

	cout << endl;

	// Initialize the array
	int magic_square[15][15] = {};
	int total_number = x*x;

	// Inputs 1 into the middle top of the row
	magic_square[0][(x-1)/2] = 1;

	int j, i;
	j = 0;
	i = (x-1)/2;

	// Inputs the number into magic square
	for(int num=2; num<=total_number; ++num)
	{
		--j;
		++i;

		if(j==-1) // wraps down if it goes over the top
		{
			j=(x-1);
		}

		if(i==x) // wraps left if it goes over the right
		{
			i=0;
		}

		if(magic_square[j][i] != 0) // puts number below if there is a number
		{
			++j;
			--i;
			j+=x; // helped by Darren and April
			i+=x; // helped by Darren and April
			j%=x; // helped by Darren and April
			i%=x; // helped by Darren and April
			++j;
		}

		magic_square[j][i] = num;
	}

	// Prints out magic square nicely
	for(int i=0; i<x; ++i)
	{
		for(int j=0; j<x; ++j)
		{
			cout << setw(4);
			cout << magic_square[i][j];
		}
		cout << endl;
	}

	cout << endl;
	cout << "Your magic square is complete!" << endl;

	return 0;
}
