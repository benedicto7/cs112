/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin University.
 * student: Heonjae(hk238), Ben(bee6)
 * date: 22 Feb 2022
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testPrepend();
	void testAppend();
	void testGetIndexOf();
	void testDestructor();
	void testCopyConstructor();
	void testEquality();
	void testWriteTo();
};

#endif /*LISTTESTER_H_*/
