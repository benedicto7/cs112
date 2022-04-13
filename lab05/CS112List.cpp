/*
 * CS112List.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 *      Student: Heonjae, Ben
 * 		Date: 2/15/22
 */

#include <stdexcept>
#include <iostream>
using namespace std;
#include "CS112List.h"

CS112List::CS112List() {
	mySize = 0;
	myCapacity = 0;
	myArray = nullptr;
}

CS112List::CS112List(int size) {
	mySize = myCapacity = size;
	myArray = new Item[size]();
}

CS112List::CS112List(const CS112List &orig) {
	// cout << "copy ctor called with object " << &orig << endl;
	mySize = orig.mySize;
	myCapacity = orig.myCapacity;
	if (myCapacity == 0) {
		myArray = nullptr;
	} else {
		// deep copy.
		myArray = new Item[mySize]();
		for (int i = 0; i < mySize; i++) {
			myArray[i] = orig.myArray[i];
		}
	}
}

int CS112List::validate_index(int index) const{
	if (index >= mySize) {
		throw range_error("index " + to_string(index) + " out of range.");
	}
	if (index < -mySize) {
		throw range_error("index" + to_string(index) + " out of range.");
	}
	else {
		if (index < 0){
			index = mySize + index;
		}
	}
	return index;
}

// called when object goes out of scope.
CS112List::~CS112List() {
	delete [] myArray;
}

void CS112List::append(const Item &value) {
    if (mySize >= myCapacity) {
        // Note: double the capacity, unless it was 0, then make it 1.
        int newCapacity = myCapacity == 0 ? 1 : myCapacity * 2;
        Item *tmp = new Item[newCapacity]();
        for (int i = 0; i < mySize; i++) {
            tmp[i] = myArray[i];
        }
        myCapacity = newCapacity;
        delete[] myArray;
        myArray = tmp;
    }
    myArray[mySize] = value;
    mySize++;
}

int CS112List::find(const Item& value) const {
	for (int i = 0; i < mySize; i++) {
		if (myArray[i] == value) {
			return i;
		}
	}
	return -1;
}

int CS112List::getSize() const {
	return mySize;
}

Item CS112List::getItem(int index) const {
	return myArray[validate_index(index)];
}

Item CS112List::getValue(int index) const {
	return myArray[validate_index(index)];
}

void CS112List::setValue(int index, const Item &value) {
	myArray[validate_index(index)] = value;
}

void CS112List::setItem(int index, const Item &value) {
	myArray[validate_index(index)] = value;
}

// return a reference to the index-th location.
Item & CS112List::operator[](int index) const {
	return myArray[validate_index(index)];
}

CS112List & CS112List::operator+(const CS112List &rhs) const {
	CS112List *result = new CS112List(mySize + rhs.mySize);
	for (int i = 0; i < mySize; i++) {
		(*result)[i] = myArray[i];
	}
	for (int i = 0; i < rhs.mySize; i++) {
		(*result)[mySize + i] = rhs[i];
	}
	return *result;
}

ostream& operator<<(ostream &out, const CS112List &rhs) {
	out << "[";
	for (int i = 0; i < rhs.getSize(); i++) {
		out << rhs[i];
		if (i < rhs.getSize() - 1) {
			out << ", ";
		}
	}
	out << "]";
	return out;
}


