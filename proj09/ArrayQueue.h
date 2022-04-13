/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: ben elpidius (bee6)
 * Date: 23 march 2022
 *
 * Class Invariant:
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 *
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>  // memcpy()
using namespace std;

template <class Item>
class ArrayQueue {
public:
    // constructor
	ArrayQueue(unsigned capacity);
    ArrayQueue(const ArrayQueue<Item>& original);
    virtual ~ArrayQueue();

    // getters
    Item getFirst() const;
    Item getLast() const;
    unsigned getSize() const;
    unsigned getCapacity() const;
    bool isEmpty() const;
    bool isFull() const;

    // setters
    void append(const Item& it);
    Item remove();
    void setCapacity(unsigned newCapacity);

    // operators
    ArrayQueue<Item>& operator=(const ArrayQueue<Item>& original);

protected:
    virtual void makeCopyOf(const ArrayQueue<Item>& original);

private:
    unsigned mySize;        // number of items I contain
    unsigned myCapacity;    // how many items I can store
    unsigned myFirstIndex;  // index of oldest item (if any)
    unsigned myLastIndex;   // index of newest item (if any)
    Item* myArrayPtr;       // dynamic array of items

    friend class ArrayQueueTester;
};

template <class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
    if (capacity == 0) {
        throw QueueException("ArrayQueue constructor",
                             "cannot create Queue with 0 capacity");
    }
    myCapacity = capacity;
    mySize = 0;
    myFirstIndex = 0;
    myLastIndex = myCapacity - 1;
    myArrayPtr = new Item[myCapacity](); // initialize to 0
}

/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template <class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) { makeCopyOf(original); }

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template <class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
    mySize = original.mySize;
    myCapacity = original.myCapacity;
    myFirstIndex = original.myFirstIndex;
    myLastIndex = original.myLastIndex;
    myArrayPtr = new Item[myCapacity];
    memcpy(myArrayPtr, original.myArrayPtr, myCapacity * sizeof(Item));
}

/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
template <class Item>
ArrayQueue<Item>::~ArrayQueue() {
    delete[] myArrayPtr;
    myArrayPtr = NULL;
    mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
template <class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
    if (this != &aQueue) {
        delete[] myArrayPtr;
        makeCopyOf(aQueue);
    }
    return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
template <class Item>
bool ArrayQueue<Item>::isEmpty() const { return mySize == 0; }

/* Am I full?
 * @return: true if I am full, false othewise.
 */
template <class Item>
bool ArrayQueue<Item>::isFull() const { return getSize() == myCapacity; }

/* accessor for myCapacity
 * @return myCapacity.
 */
template <class Item>
unsigned ArrayQueue<Item>::getCapacity() const { return myCapacity; }

/* accessor for mySize
 * @return mySize.
 */
template <class Item>
unsigned ArrayQueue<Item>::getSize() const { return mySize; }

/* returns first value
 */
template <class Item>
Item ArrayQueue<Item>::getFirst() const {
    if (isEmpty()) {
        throw EmptyQueueException("getFirst()");
    }
    return myArrayPtr[myFirstIndex];
}

/* returns last value
 */
template <class Item>
Item ArrayQueue<Item>::getLast() const {
    if (isEmpty()) {
        throw EmptyQueueException("getLast()");
    }
    return myArrayPtr[myLastIndex];
}

template <class Item>
void ArrayQueue<Item>::append(const Item& it) {
    if (isFull()) {
        throw FullQueueException("append()");
    }
    myLastIndex = (myLastIndex + 1) % myCapacity;
    myArrayPtr[myLastIndex] = it;
    mySize++;
}

template <class Item>
Item ArrayQueue<Item>::remove() {
    if (isEmpty()) {
        throw EmptyQueueException("remove()");
    }
    Item ret = myArrayPtr[myFirstIndex];
    myFirstIndex = (myFirstIndex + 1) % myCapacity;
    mySize--;
    return ret;
}

template <class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity) {
	if ((newCapacity == 0) || (newCapacity < getSize())) {
		throw InvalidSetCapacity("setCapacity()");
	}

	Item* newArray = new Item[newCapacity]();
	unsigned oldArray = myFirstIndex;

	for (unsigned i = 0; i<mySize; i++) {
		newArray[i] = myArrayPtr[oldArray];
		oldArray = (oldArray + 1) % myCapacity;
	}

	delete[] myArrayPtr;
	myArrayPtr = newArray;
	myCapacity = newCapacity;
	myFirstIndex = 0;
	myLastIndex = mySize-1;
}

#endif /*ARRAY_QUEUE_H_*/
