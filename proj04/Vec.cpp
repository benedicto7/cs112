/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student: Ben (BEE6)
 * Date: 10/Feb/2022
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */
 
#include "Vec.h"

Vec::Vec() {
    mySize = 0;
    myArray = nullptr;
}

Vec::Vec(unsigned size) {
	mySize = size;
	if (size <= 0){
		myArray = nullptr;
	} else {
		myArray = new Item[size]();
	}
}

// copy constructor
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize <= 0){
		myArray = nullptr;
	} else {
		myArray = new Item[mySize](); // creates an array and initialize to 0
		for (unsigned i=0; i < original.mySize; i++){
			myArray[i] = original.myArray[i];
		}
	}
}

// assignment operator
Vec& Vec::operator=(const Vec& original) {
	if (myArray != original.myArray){
		if (mySize != original.mySize){
			if (mySize > 0){
				delete[] myArray;
				myArray = nullptr;
			}
			if (original.mySize > 0){
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		for (unsigned i = 0; i < mySize; i++){
			myArray[i] = original.myArray[i];
		}
	}
    return *this;
 }

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (index < 0 || index >= mySize){
		throw range_error("Invalid index.");
	}
	else{
		myArray[index] = it;
	}
}

Item Vec::getItem(unsigned index) const {
	if (index < 0 || index >= mySize){
		throw range_error("Invalid index.");
	}
	else {
		return myArray[index];
	}
}

// when user enters a new size for the array and then copies the array from the old size to the new size
void Vec::setSize(unsigned newSize) {
	if (mySize != newSize){
		if (newSize == 0){
			delete[]myArray;
			myArray = nullptr;
			mySize = 0;
		}
		else {
			Item* copy = new Item[newSize]();
			if (mySize < newSize){
				for (unsigned i = 0; i < mySize; i++){
					copy[i] = myArray[i];
				}
			}
			else {
				for (unsigned i = 0; i < newSize; i++){
					copy[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete[]myArray;
			myArray = copy;
		}
	}
}

// asserts if the old and new vector are the same size
bool Vec::operator==(const Vec& v2) const {
	if (mySize != v2.mySize){
		return false;
	} else {
		for (unsigned i = 0; i < mySize; i++){
			if (myArray[i] != v2.myArray[i]) {
				return false;
			}
		}
	}
	return true;
}

// subscript operator
Item & Vec::operator[](unsigned index) const {
	if (index >= mySize)
	{
		throw range_error("Invalid index.");
	}
	return myArray[index];
}

// vector addition
Vec Vec::operator+(const Vec& other) const {
	if (other.mySize != this->mySize)
	{
		throw invalid_argument("Vector has different size.");
	}

	Vec addition(mySize);
	for (unsigned i = 0; i < mySize; i++)
	{
		addition.myArray[i] = this->myArray[i] + other.myArray[i];
	}

	return addition;
}

// vector subtraction
Vec Vec::operator-(const Vec& other) const {
	if (other.mySize != this->mySize)
	{
		throw invalid_argument("Vector has different size.");
	}

	Vec subtraction(mySize);
	for (unsigned i = 0; i < mySize; i++)
	{
		subtraction[i] = this->myArray[i] - other.myArray[i];
	}

	return subtraction;
}

// writes the value out in my array at index i
void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++)
	{
		out << myArray[i] << endl;
	}
}

// reads a value and inserts it to my array at index i
void Vec::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++){
		in >> myArray[i];
	}
}

// destructor
Vec::~Vec() {
	delete[] myArray;
	myArray = nullptr;
	mySize = 0;
}
