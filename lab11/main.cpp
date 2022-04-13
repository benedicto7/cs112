/*
 * main.cpp is a driver for an ImageConverter program
 *  using OpenMP to parallelize the image processing
 *  and TSGL to view the processing in near real time.
 *
 * Author: Joel Adams, for CS 112 at Calvin College.
 *  Name: Ben (bee6), Heon Jae (hk238)
 * Date: March 2015.
 * Revised: November 2016.
 * Revised for TSGL-2: November 2016.
 */

 #include "ImageConverter.h"

 int main() {
	 omp_set_num_threads(6);
	 ImageConverter iConverter("pics/beads.jpg", 800, 800);
	 iConverter.run();
 }
