/*
 * CS112List.h
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 *      Student: Ben
 * 		Date: 2/16/22
 */

#ifndef CS112LIST_H_
#define CS112LIST_H_

#include <string>
using namespace std;

template <class Item>
class CS112List {
public:
	CS112List(); // default constructor
	CS112List(int size); // explicit constructor
	CS112List(const CS112List<Item> &orig); // copy constructor
	virtual ~CS112List(); // destructor

	// getters
	int getSize() const;
	Item getItem(int index) const;
	Item getValue(int index) const;
	int find(const Item& value) const;

	// setters
	void setItem(int index, const Item &value);
	void setValue(int index, const Item &value);

	// overloading operator
	Item & operator[](int index) const;
	CS112List<Item>& operator+(const CS112List<Item> &rhs) const;

	// others
	void append(const Item &value);
	void insert(int index, const Item &it);
	bool remove(const Item &it);
	Item removeAt(const int index);

	// slicing
	CS112List<Item>& slice(const int stop_index) const;
	CS112List<Item>& slice(const int start_index, const int stop_index) const;
	CS112List<Item>& slice(const int start_index, const int stop_index, const unsigned step_index) const;

private:
	int mySize;      // number of items in the array
	int myCapacity;  // how much space we have for items
	Item *myArray;   // an array, of course.
	int validate_index(int index) const;

};

// make it so we can do cout << aList.
template <class Item>
ostream& operator<<(ostream &out, const CS112List<Item> &rhs);

// operator<<
template <class Item>
ostream& operator<<(ostream &out, const CS112List<Item> &rhs) {
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

template <class Item>
CS112List<Item>::CS112List() {
	mySize = 0;
	myCapacity = 0;
	myArray = nullptr;
}

template <class Item>
CS112List<Item>::CS112List(int size) {
	mySize = size;
	myCapacity = size;
	myArray = new Item[size]();
}

// copy constructor
template <class Item>
CS112List<Item>::CS112List(const CS112List<Item> &orig) {
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

template <class Item>
int CS112List<Item>::validate_index(int index) const{
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
template <class Item>
CS112List<Item>::~CS112List() {
	delete [] myArray;
}

template <class Item>
void CS112List<Item>::append(const Item &value) {
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

template <class Item>
int CS112List<Item>::find(const Item& value) const {
	for (int i = 0; i < mySize; i++) {
		if (myArray[i] == value) {
			return i;
		}
	}
	return -1;
}

template <class Item>
int CS112List<Item>::getSize() const {
	return mySize;
}

template <class Item>
Item CS112List<Item>::getItem(int index) const {
	return myArray[validate_index(index)];
}

template <class Item>
Item CS112List<Item>::getValue(int index) const {
	return myArray[validate_index(index)];
}

template <class Item>
void CS112List<Item>::setValue(int index, const Item &value) {
	myArray[validate_index(index)] = value;
}

template <class Item>
void CS112List<Item>::setItem(int index, const Item &value) {
	myArray[validate_index(index)] = value;
}

// return a reference to the index-th location.
template <class Item>
Item & CS112List<Item>::operator[](int index) const {
	return myArray[validate_index(index)];
}

template <class Item>
CS112List<Item> & CS112List<Item>::operator+(const CS112List<Item> &rhs) const {
	CS112List<Item> *result = new CS112List<Item>(mySize + rhs.mySize);
	for (int i = 0; i < mySize; i++) {
		(*result)[i] = myArray[i];
	}
	for (int i = 0; i < rhs.mySize; i++) {
		(*result)[mySize + i] = rhs[i];
	}
	return *result;
}

// insert method
template <class Item>
void CS112List<Item>::insert(int index, const Item &it){
	// creates bigger array
	if (mySize == myCapacity)
	{
		int newCapacity = myCapacity * 2;
		Item *temp = new Item[newCapacity]();

		for (int i = 0; i < mySize; i++)
		{
			temp[i] = myArray[i];
		}

		myCapacity = newCapacity;
        delete[] myArray;
		myArray = temp;
	}

	// shifting the array up
	for (int i = mySize; i > index; i--)
	{
		myArray[i] = myArray[i-1];
	}

	// inputs the value at given index
	myArray[index] = it;
	mySize++;
}

// remove method
template <class Item>
bool CS112List<Item>::remove(const Item &it) {
	for (int i = 0; i < mySize; i++)
	{
		if (myArray[i] == it)
		{
			// remove value by shifting down
			for (int x = i; x < (mySize-1); x++)
			{
				myArray[x] = myArray[x+1];
			}

			mySize--;
			return true;
		}
	}
	return false;
}

// removeAt method
template <class Item>
Item CS112List<Item>::removeAt(const int index) {
	if (index >= mySize || index < -mySize)
	{
		throw range_error("Index is out of bounds");
	}

	int indexToRemove = validate_index(index);
	string valueReturned = myArray[indexToRemove];

	for (int i = indexToRemove; i < (mySize-1); i++)
	{
		myArray[i] = myArray[i+1];
	}

	mySize--;
	return valueReturned;
}

// slice method for stop
template <class Item>
CS112List<Item>& CS112List<Item>::slice(const int stop_index) const {
	CS112List<Item> *result = new CS112List;

	// set stop_index
	int stop;
	if (stop_index > mySize)
	{
		stop = mySize;
	}
	else if(stop_index < -(mySize))
	{
		stop = 0;
	}
	else {
		stop = validate_index(stop_index);
	}

	for (int i = 0; i < stop; i++)
	{
		result->append(myArray[i]);
	}

	return *result;
}

// slice method for start and stop
template <class Item>
CS112List<Item>& CS112List<Item>::slice(const int start_index, const int stop_index) const {
	CS112List<Item> *result = new CS112List;

	// set start_index
	int start = start_index;
	if (start_index < 0)
	{
		start = 0;
	}

	// set stop_index
	int stop;
	if (stop_index > mySize)
	{
		stop = mySize;
	}
	else if(stop_index < -(mySize))
	{
		stop = 0;
	}
	else {
		stop = validate_index(stop_index);
	}

	for (int i = start; i < stop; i++)
	{
		result->append(myArray[i]);
	}

	return *result;
}

// slice method for start, stop, and index
template <class Item>
CS112List<Item>& CS112List<Item>::slice(const int start_index, const int stop_index, const unsigned step_index) const {
	if (step_index == 0)
	{
		throw invalid_argument("Step index is invalid.");
	}

	CS112List<Item>* result = new CS112List;

	// sets start_index
	int start = start_index;
	if (start_index < 0)
	{
		start = 0;
	}

	// sets stop_index
	int stop;
	if (stop_index > mySize)
	{
		stop = mySize;
	}
	else if(stop_index < -(mySize))
	{
		stop = 0;
	}
	else {
		stop = validate_index(stop_index);
	}

	for (int i = start; i < stop; i = i + step_index)
	{
		result->append(myArray[i]);
	}

	return *result;
}

#endif /* CS112LIST_H_ */
