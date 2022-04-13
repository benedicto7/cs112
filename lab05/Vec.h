/* Vec.h provides a simple vector class named Vec.
 * Student: Heonjae, Ben
 * Date: 2/15/22
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

template <class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	virtual ~Vec();

	//copying operator
	Vec(const Vec<Item>& original);

	//assigning operator
	Vec<Item>& operator=(const Vec<Item>& original);

	//getter
	unsigned getSize() const;
	Item getItem(unsigned index) const;

	//setter
	void setItem(unsigned index, const Item& it);
	void setSize(unsigned newSize);

	//others
	bool operator==(const Vec<Item>& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[](unsigned index) const;
	bool operator!=(const Vec<Item>& v2) const;
	Vec<Item> operator+(const Vec<Item> &v2) const;
	Vec<Item> operator-(const Vec<Item>& v2) const;
	double operator*(const Vec<Item>& v2) const;

private:
    unsigned mySize;
    Item *   myArray;
    Item * mySumArr;
    friend class VecTester;

};

template <class Item>
Vec<Item>::Vec() {
    mySize = 0;
    myArray = nullptr;
    mySumArr = nullptr;
}

template <class Item>
Vec<Item>::Vec(unsigned size) {
	mySumArr = nullptr;
	mySize = size;
	if (size <= 0){
		myArray = nullptr;
	} else {
		myArray = new Item[size]();
	}
}

// copy constructor
template <class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	mySumArr = nullptr;
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
template <class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
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

template <class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

template <class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index < 0 || index >= mySize){
		throw range_error("Invalid index.");
	}
	else{
		myArray[index] = it;
	}
}

template <class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (index < 0 || index >= mySize){
		throw range_error("Invalid index.");
	}
	else {
		return myArray[index];
	}
}

template <class Item>
void Vec<Item>::setSize(unsigned newSize) {
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

template <class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
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

template <class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++)
	{
		out << myArray[i] << " ";
	}
	out << endl;
}

template <class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++){
		in >> myArray[i];
	}
}

template <class Item>
Item& Vec<Item>::operator[](unsigned index) const {
	if (index >= mySize){
		throw range_error("Invalid index.");
	}
	return myArray[index];
}

template <class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) const{
	if (mySize != v2.mySize){
		return true;
	} else {
		for (unsigned i = 0; i < mySize; i++){
			if (myArray[i] != v2.myArray[i]) {
				return true;
			}
		}
	}
	return false;
}

template <class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item> &v2) const{
	if (mySize != v2.mySize){
		throw invalid_argument("Error: two Vectors have different size!");
	}
	else {
		Vec<Item> result(mySize);
		for (unsigned i = 0; i < mySize; i++){
			(result)[i] = myArray[i] + v2.myArray[i];
		}
	return result;
	}
}


template <class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2) const{
	if (mySize != v2.mySize){
		throw invalid_argument("Error: two Vectors have different size!");
	}
	else {
		Vec<Item> result = (mySize);
		for (unsigned i = 0; i < mySize; i++){
			(result)[i] = myArray[i] - v2.myArray[i];
		}
	return result;
	}
}

template <class Item>
double Vec<Item>::operator*(const Vec<Item>& v2) const{
	unsigned sum_array[mySize];
	if (mySize != v2.mySize){
		throw invalid_argument("Error: two Vectors have different size!");
	}
	else {
		for (unsigned i = 0; i < mySize; i++){
			sum_array[i] = (myArray[i]) * (v2.myArray[i]);
		}
	}
	double sum_arr=0;
	for (unsigned i = 0; i < mySize; i++){
		sum_arr = sum_arr + sum_array[i];
	}
	return sum_arr;
}


template <class Item>
Vec<Item>::~Vec() {
	delete[] myArray;
	myArray = nullptr;
	mySize = 0;
}

#endif /*VEC_H_*/
