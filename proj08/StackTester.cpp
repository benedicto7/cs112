/* StackTester.cpp defines test-methods for the 
 *  dynamically allocated (array) Stack operations
 * Joel Adams, for CS 112 at Calvin University
 * Student Name: ben elpidius
 * Date: March 17, 2022
 */

#include "StackTester.h"
#include "reversePoem.h"
#include "StackException.h"
#include <fstream>
#include <iostream>  // cout, cerr, ...
#include <cassert>   // assert()
#include <cstdlib>   // exit()
using namespace std;

void StackTester::runTests() {
	cout << "Testing Stack class..." << endl;
	testConstructor();
	testIsEmpty();
	testPushPeekTopAndIsFull();
	testPop();
	testCopyConstructor();
	testAssignment();
	testDestructor();
	testCapacityAndSize();
	testPoem();
	cout << "All tests passed!" << endl;
}

void StackTester::testConstructor() {
	cout << "- Testing constructor... " << flush;
	// invalid parameter
	try {
		Stack<int> s1(0);
		cerr << "\nConstructed stack of size 0\n";
		exit(1);
	} catch (const StackException& se) {
		cout << se << flush;
		cout << " 0 " << flush;
	}
	// valid parameter
	Stack<int> s2(3);
	cout << " 1 " << flush;
	cout << " Passed!" << endl;
}

void StackTester::testIsEmpty() {
	cout << "- Testing isEmpty()... " << flush;
	// capacity 1
	Stack<int> s1(1);
	assert( s1.isEmpty() );
	cout << " 1 " << flush;
	// capacity > 1
	Stack<int> s2(3);
	assert( s2.isEmpty() );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}


void StackTester::testPushPeekTopAndIsFull() {
	cout << "- Testing push()... " << flush;
	// test with capacity 1
	Stack<int> s1(1);
	s1.push(11);
	assert( s1.peekTop() == 11 );
	assert( !s1.isEmpty() );
	assert( s1.isFull() );
	try {
		s1.push(22);
		cerr << "\npush() worked on a full stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 1 " << flush;
	}
	// test with capacity > 1
	Stack<int> s2(3);
	s2.push(11);
	assert( s2.peekTop() == 11 );
	s2.push(22);
	assert( s2.peekTop() == 22 );
	s2.push(33);
	assert( s2.peekTop() == 33 );
	try {
		s2.push(44);
		cerr << "\npush() worked on a full stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 2 " << flush;
	}
	cout << " Passed! " << endl;
}

void StackTester::testPop() {
	cout << "- Testing pop()... " << flush;
	// try empty, capacity 1
	Stack<int> s1(1);
	assert( s1.isEmpty() );
    try {
            s1.peekTop();
            cerr << "\npeekTop() worked on empty stack (size 1)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 0a " << flush;
    }
	try {
		s1.pop();
		cerr << "\npop() worked on empty stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 0b " << flush;
	}

	// try empty, capacity > 1
	Stack<int> s2(3);
	try {
		s2.pop();
		cerr << "\npop() worked on empty stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 1a " << flush;
	}
    try {
            s2.peekTop();
            cerr << "\npeekTop() worked on empty stack (size 3)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 1b " << flush;
    }

	// try non-empty, capacity 1
	Stack<int> s3(1);
	s3.push(11);
	assert( s3.peekTop() == 11 );
	assert( s3.pop() == 11 );
	cout << " 2 " << flush;
	try {
		s3.pop();
		cerr << "\ns3.pop() worked on empty stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 2a " << flush;
	}
    try {
            s3.peekTop();
            cerr << "\ns3.peekTop() worked on empty stack (size 1)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 2b " << flush;
    }

	// try non-empty, capacity > 1
	Stack<int> s4(3);
	s4.push(11);
	s4.push(22);
	s4.push(33);
	assert( s4.peekTop() == 33 );
	assert( s4.pop() == 33 );
	assert( s4.peekTop() == 22 );
	assert( s4.pop() == 22 );
	assert( s4.peekTop() == 11 );
	assert( s4.pop() == 11 );
	cout << " 3 " << flush;
	try {
		s4.pop();
		cerr << "\ns4.pop() worked on empty stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 3a " << flush;
	}
    try {
            s4.peekTop();
            cerr << "\ns4.peekTop() worked on empty stack (size 3)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 3b " << flush;
    }

	cout << " Passed!" << endl;
}

void StackTester::testCopyConstructor() {
	cout << "- Testing copy constructor... " << flush;
	// minimal empty Stack
	Stack<int> s1(1);
	Stack<int> s2(s1);
	assert( s2.isEmpty() );
	assert( s2.myArray != nullptr );
	assert( s2.myCapacity == 1 );
	assert( s2.myArray != s1.myArray );
	cout << " 1 " << flush;
	// minimal non-empty Stack
	Stack<int> s3(1);
	s3.push(11);
	Stack<int> s4(s3);
	assert( !s4.isEmpty() );
	assert( s4.isFull() );
	assert( s4.peekTop() == 11 );
	assert( s4.myArray != s3.myArray );
	cout << " 2 " << flush;
	// non-minimal, non-empty stack
	Stack<int> s5(3);
	s5.push(11);
	s5.push(22);
	s5.push(33);
	Stack<int> s6(s5);
	assert( s6.myCapacity == s5.myCapacity );
	assert( s6.mySize == s5.mySize );
	assert( s6.myArray != s5.myArray );
	assert( s6.pop() == 33 );
	assert( s6.pop() == 22 );
	assert( s6.pop() == 11 );
	assert( s5.peekTop() == 33 );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void StackTester::testAssignment() {
	cout << "- Testing assignment... " << flush;
	// minimal empty Stacks, same size
	Stack<int> s1(1);
	Stack<int> s2(1);
	s2 = s1;
	assert( s2.isEmpty() );
	assert( s2.myArray != nullptr );
	assert( s2.myArray != s1.myArray );
	assert( s2.myCapacity == 1 );
	cout << " 1 " << flush;
	// minimal non-empty Stack to empty Stack, same capacity
	Stack<int> s3(1);
	s3.push(11);
	Stack<int> s4(1);
	s4 = s3;
	assert( !s4.isEmpty() );
	assert( s4.isFull() );
	assert( s4.peekTop() == 11 );
	assert( s4.myArray != s3.myArray );
	cout << " 2 " << flush;
	// minimal empty stack to non-empty stack, same capacity
	Stack<int> s5(1);
	Stack<int> s6(1);
	s6.push(11);
	s6 = s5;
	assert( s6.isEmpty() );
	assert( s6.myArray != nullptr );
	assert( s6.myArray != s5.myArray );
	assert( s6.myCapacity == 1 );
	cout << " 3 " << flush;
	// non-minimal non-empty stack to empty stack, different capacities
	Stack<int> s7(3);
	s7.push(11);
	s7.push(22);
	s7.push(33);
	Stack<int> s8(2);
	s8 = s7;
	assert( s8.myArray != s7.myArray );
	assert( s8.myCapacity == s7.myCapacity );
	assert( s8.mySize == s7.mySize );
	assert( s8.pop() == 33 );
	assert( s8.pop() == 22 );
	assert( s8.pop() == 11 );
	assert( s7.peekTop() == 33 );
	cout << " 4 " << flush;
	// non-minimal, empty stack to non-empty stack, different capacities
	Stack<int> s9(2);
	Stack<int> s10(3);
	s10.push(11);
	s10.push(22);
	s10.push(33);
	s10 = s9;
	assert( s10.isEmpty() );
	assert( s10.myArray != s9.myArray );
	assert( s10.myCapacity == s10.myCapacity );
	cout << " 5 " << flush;
	// self-assignment, minimal size
	Stack<int> s11(1);
	s11.push(11);
	s11 = s11;
	assert( s11.isFull() );
	assert( !s11.isEmpty() );
	cout << " 6 " << flush;
	// chaining
	Stack<int> s12(2);
	s12.push(11);
	s12.push(22);
	Stack<int> s13(1);
	Stack<int> s14(1);
	s14 = s13 = s12;
	assert( s14.isFull() );
	assert( s14.myArray != s13.myArray );
	assert( s14.myArray != s12.myArray );
	assert( s14.pop() == 22 );
	assert( s14.pop() == 11 );
	assert( s14.isEmpty() );
	cout << " 7 " << flush;
      // self-assignment, non-minimal size
    s13 = s13;
	assert( !s13.isEmpty() );
	assert( s13.isFull() );
	assert( s13.pop() == 22 );
	assert( s13.pop() == 11 );
	assert( s13.isEmpty() );
	cout << " 8 " << flush;
	cout << "Passed!" << endl;
}

void StackTester::testDestructor() {
	cout << "- Testing destructor..." << flush;
	// minimal, empty
	Stack<int> s1(1);
	s1.~Stack();
	assert( s1.isEmpty() );
	assert( s1.myArray == nullptr );
	assert( s1.myCapacity == 0 );
	cout << " 1 " << flush;
	// minimal, non-empty
	Stack<int> s2(1);
	s2.push(11);
	s2.~Stack();
	assert( s2.isEmpty() );
	assert( s2.myArray == nullptr );
	assert( s2.myCapacity == 0 );
	cout << " 2 " << flush;
	// non-minimal, empty
	Stack<int> s3(3);
	s3.~Stack();
	assert( s3.isEmpty() );
	assert( s3.myArray == nullptr );
	assert( s3.myCapacity == 0 );
	cout << " 3 " << flush;
	// non-minimal, non-empty
	Stack<int> s4(3);
	s4.push(11);
	s4.push(22);
	s4.push(33);
	s4.~Stack();
	assert( s4.isEmpty() );
	assert( s4.myArray == nullptr );
	assert( s4.myCapacity == 0 );
	cout << " 4 " << flush;
	cout << " Passed!" << endl;
}

void StackTester::testCapacityAndSize() {
	cout << "Testing capacity and size..." << flush;
	Stack<int> s1(10);

	// get capacity
	assert(s1.getCapacity() == 10);
	cout << " 1 " << flush;

	// get size
	s1.push(10);
	s1.push(20);
	s1.push(30);
	assert(s1.getSize() == 3);
	cout << " 2 " << flush;

	// set capacity
	Stack<int> s2(10);
	for (unsigned i = 0; i<10; i++)
	{
		s2.push(i);
	}

	assert(s2.getCapacity() == 10);
	assert(s2.getSize() == 10);
	try {
		s2.setCapacity(9);
		cerr << "setCapacity() worked on newCapacity smaller than mySize.";
		exit(1);
	} catch (const StackException& se) {
		cout << " 3a " << flush;
	}

	try {
		s2.setCapacity(0);
		cerr << "setCapacity() worked on newCapacity = 0.";
		exit(1);
	} catch(const StackException& se) {
		cout << " 3b " << flush;
	}

	s2.setCapacity(20);
	assert(s2.getSize() == 10);
	assert(s2.getCapacity() == 20);
	s2.setCapacity(21);
	assert(s2.getCapacity() == 21);
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

void StackTester::testPoem() {
	cout << "Testing poem..." << endl;
	cout << "Testing Cats.txt." << endl;
	reversePoem poem("Cats.txt");

	assert(poem.getTitle() == "Cats");
	assert(poem.getAuthor() == "Leo J. Smada");
	assert(poem.getBody() == "I love it when cats rub against me.\nI could never say\nI hate those furry felines.\n");
	assert(poem.getBodyReversed() == "I hate those furry felines.\nI could never say\nI love it when cats rub against me.\n"); // dumb error

	cout << "Title is: " << poem.getTitle() << endl;
	cout << "Author is: " << poem.getAuthor() << endl;
	cout << endl;

	cout << "*** Top-to-Bottom ***" << endl;
	cout << poem.getBody() << endl;

	cout << "*** Bottom-to-Top" << endl;
	cout << poem.getBodyReversed() << endl;

	reversePoem newPoem("Love?.txt");

	assert(newPoem.getTitle() == "Love?");
	assert(newPoem.getAuthor() == "Anonymous");
	assert(newPoem.getBody() == "I don't love you anymore...\nI would be lying if I said\nThat I still love you the way I always did.\nI'm sure\nNothing was in vain.\nAnd I feel inside of me that\nYou mean nothing to me\nI could never really say that\nOur time together matters.\nI feel more and more that\nI'm forgetting you...\nAnd I will never use the phrase\nI love you.\nI'm sorry but I must tell the truth.\n");

	cout << "Title is: " << newPoem.getTitle() << endl;
	cout << "Author is: " << newPoem.getAuthor() << endl;
	cout << endl;

	cout << "*** Top-to-Bottom ***" << endl;
	cout << newPoem.getBody() << endl;

	cout << "*** Bottom-to-Top" << endl;
	cout << newPoem.getBodyReversed() << endl;

	cout << "Passed."<< endl;
}
