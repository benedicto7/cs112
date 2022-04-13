/*
 * main.cpp is a driver for an ImageConverter program
 *  using OpenMP to parallelize the image processing
 *  and TSGL to view the processing in near real time.
 *
 * Author: Joel Adams, for CS 112 at Calvin College.
 * Name: Ben (bee6), 8 april 2022
 * Date: March 2015.
 * Revised: November 2016.
 * Revised for TSGL-2: November 2016.
 */

#include "ImageConverter.h"
#include <string>
#include <cmath>
using namespace std;

int main() {
	omp_set_num_threads(16);
	ImageConverter iConverter("pics/templeinsea.jpg", 800, 800); // width, height or x, y
	iConverter.run();

	// crop image according to user size
	cout << "Trying crop image." << endl;
	ImageConverter imageConverter("pics/templeinsea.jpg", 900, 800); // width, height or x, y

	// x and y coordinate to know where to crop
	cout << "Selecting which new origin to crop at." << endl;
	int x = -450;
	int y = -400;

	while (true) {
		cout << "Enter x (from -450 to 450): ";
		cin >> x;

		cout << "Enter y (from -400 to 400): ";
		cin >> y;

		if ((x <= 450) && (x >= -450)) {
			if ((y <= 400) && (y >= -400)) {
				break;
			}
		}

		cout << "X or Y is out of bounds. Enter again." << endl;
	}

	// width to know how wide to crop from origin to right
	cout << "Selecting how wide to crop." << endl;
	int width = 450;

	while (true) {
		cout << "Enter width from " << x << " to 450: ";
		cin >> width;
		if ((width >= x) && (width <= 450)) {
			break;
		}

		cout << "Width is out of bound of the image." << endl;
	}

	// height to know how high to crop from origin to up
	cout << "Selecting how high to crop." << endl;
	int height = 400;

	while (true) {
		cout << "Enter height from " << y << " to 400: ";
		cin >> height;
		if ((height >= y) && (height <= 400)) {
			break;
		}

		cout << "Height is out of bound of the image." << endl;
	}

	imageConverter.cropImage(x, y, width, height);
}
