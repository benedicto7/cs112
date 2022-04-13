/* ArrayQueueTester.h declares the class that tests class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: ben elpidius (bee6)
 * Date: 23 march 2022
 */
 
#ifndef QUEUETESTER_H_
#define QUEUETESTER_H_

#include "ArrayQueue.h"
#include "palindromeDetector.h"

class ArrayQueueTester {
public:
	void runTests();
	void testConstructor();
	void testAppend();
	void testRemove();
	void testCopyConstructor();
	void testAssignment();
	void testSetCapacity();
	void testPalindrome();
};

#endif /*QUEUETESTER_H_*/
