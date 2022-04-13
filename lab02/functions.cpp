/*
 * fuctions.cpp
 *
 *  Created on: Jan 25, 2022
 *      Author: hk238, BEE6
 */


#include "functions.h"

bool findDuplicate(int arr[], int size, int &dup_number){
	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				dup_number = arr[i];
				return true; //duplicate found
			}
		}
	}
	return false; // duplicate not found
}
