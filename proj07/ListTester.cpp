/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin University.
 * ben elpidius, march 10 2022
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
#include <fstream>      // fstream
#include <sstream>		// ostringstream
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
	testInequality();
//	testReadFromStream();
//	testWriteToStream();
//	testReadFromFile();
//	testWriteToFile();
	testPrepend();
	testGetIndexOf();
	testInsertion();
	testRemove();
	testInsertAfter();
	testInsertBefore();
	testOutput();

	cout << "All tests passed!" << endl;
}

void ListTester::testInsertAfter() {
	cout << "Testing insertAfter..." << flush;
	List<int> congaAfter;
	congaAfter.append(1);
	congaAfter.append(2);
	congaAfter.append(3);
	// 1 2 3

	assert(congaAfter.getLast() == 3);
	congaAfter.insertAfter(3, 4);
	assert(congaAfter.getLast() == 4);
	congaAfter.insertAfter(2, 5);
	// 1 2 5 3 4

	assert(congaAfter.insertAfter(1, 10) == true);
	assert(congaAfter.insertAfter(0, 10) == false);
	// 1 10 2 5 3 4

	assert(congaAfter.myFirst->myNext->myNext->myNext->myItem == 5);
	assert(congaAfter.myFirst->myNext->myNext->myItem == 2);

	cout << "Passed." << endl;
}

void ListTester::testInsertBefore() {
	cout << "Testing insertBefore..." << flush;
	List<int> congaBefore;
	congaBefore.append(1);
	congaBefore.append(2);
	congaBefore.append(3);
	// 1 2 3

	assert(congaBefore.getFirst() == 1);
	congaBefore.insertBefore(3, 4);
	congaBefore.insertBefore(1, 5);
	assert(congaBefore.getFirst() == 5);
	// 5 1 2 4 3

	assert(congaBefore.insertBefore(4, 10) == true);
	assert(congaBefore.insertBefore(0, 0) == false);
	// 5 1 2 10 4 3

	assert(congaBefore.myFirst->myNext->myNext->myItem == 2);
	assert(congaBefore.myFirst->myNext->myNext->myNext->myItem == 10);

	cout << "Passed." << endl;
}

void ListTester::testOutput() {
    cout << "Testing Output... " << flush;
	List<string> dance;
	cout << endl;

	dance.append("Ann");
	cout << "Mysize: " << dance.getSize() << endl;

	dance.append("Bob");
	cout << "Mysize: " << dance.getSize() << endl;

	dance.insertAfter("Bob", "Ben");
	cout << "Mysize: " << dance.getSize() << endl;

	dance.insertBefore("Bob", "Elpidius");
	assert(dance.getSize() == 4);

	cout << dance << endl;

	cout << "Check that output looks like this: =Ann=Elpidius=Bob=Ben" << endl;

	cout << "Passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == double() );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
    // check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
    // check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
    // check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testEquality() {
	cout << "Testing equality... " << flush;
	List<double> l0;
	List<double> l1;
	assert(l0 == l1);
	cout << " 0 " << flush;

	// test different # of elements and same number with same values.
	l1.append(1);
	assert(! (l0 == l1));
	cout << " 1 " << flush;
	l0.append(1);
	assert(l0 == l1);
	cout << " 2 " << flush;
	l1.append(2);
	assert(! (l0 == l1));
	cout << " 3 " << flush;
	l0.append(2);
	assert(l0 == l1);
	cout << " 4 " << flush;

	// same # of elements but different value in one of them
	l0.append(3);
	l1.append(4);
	assert(! (l0 == l1));
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInequality() {
	cout << "Testing inequality... " << flush;
	List<double> l0;
	List<double> l1;
	assert(! (l0 != l1));
	cout << " 0 " << flush;

	// test different # of elements and same number with same values.
	l1.append(1);
	assert(l0 != l1);
	cout << " 1 " << flush;
	l0.append(1);
	assert(! (l0 != l1));
	cout << " 2 " << flush;
	l1.append(2);
	assert(l0 != l1);
	cout << " 3 " << flush;
	l0.append(2);
	assert(! (l0 != l1));
	cout << " 4 " << flush;

	// same # of elements but different value in one of them
	l0.append(3);
	l1.append(4);
	assert(l0 != l1);
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}

//void ListTester::testReadFromStream() {
//	cout << "Testing readFrom(stream)... " << flush;
//	ifstream fin("listData.txt");
//	assert(fin.is_open());
//
//	List<double> l0;
//	l0.readFrom(fin);
//	assert(l0.getSize() == 3);
//	assert(l0.getFirst() == 11);
//	assert(l0.myFirst->myNext->myItem == 22);
//	assert(l0.getLast() == 3.5);
//	fin.close();
//	cout << " 0 " << flush;
//
//	cout << "Passed!" << endl;
//}


//void ListTester::testWriteToStream() {
//	cout << "Testing writeTo(stream)..." << flush;
//	ofstream fout("listDataOut.txt");
//	assert(fout.is_open());
//	List<double> l0;
//	l0.append(11);
//	l0.append(22);
//	l0.append(33);
//	l0.writeTo(fout, '\t');
//	fout.close();
//
//	List<double> l1;
//	ifstream fin("listDataOut.txt");
//	assert(fin.is_open());
//	l1.readFrom(fin);
//	assert(l1.mySize == 3);
//	assert(l1.myFirst->myItem == 11);
//	assert(l1.myFirst->myNext->myItem == 22);
//	assert(l1.myFirst->myNext->myNext->myItem == 33);
//	assert(l1.myLast->myItem == 33);
//	assert(l1.myLast->myNext == nullptr);
//	fin.close();
//	cout << " 0 " << flush;
//	cout << "Passed!" << endl;
//}

//void ListTester::testReadFromFile() {
//	cout << "Testing readFromFile... " << flush;
//
//	List<double> l0;
//	// Add something to the list, and then write over it with readFrom.
//	l0.append(33);
//	// List::Node *oldFirstNode = l0.myFirst;   see below
//	l0.readFrom("listData.txt");
//	assert(l0.getSize() == 3);
//	assert(l0.getFirst() == 11);
//	assert(l0.myFirst->myNext->myItem == 22);
//	assert(l0.getLast() == 3.5);
//
//	// Cannot do this safely: the OS might give back the memory that was just released.
//	// assert(l0.myFirst != oldFirstNode);
//	cout << " 0 " << flush;
//
//	cout << "Passed!" << endl;
//}

//void ListTester::testWriteToFile() {
//	cout << "Testing writeToFile..." << flush;
//	List<double> l0;
//	l0.append(11);
//	l0.append(22);
//	l0.append(33);
//	l0.writeTo("listDataOut.txt", '\t');
//
//	List<double> l1;
//	ifstream fin("listDataOut.txt");
//	assert(fin.is_open());
//	l1.readFrom(fin);
//	assert(l1.mySize == 3);
//	assert(l1.myFirst->myItem == 11);
//	assert(l1.myFirst->myNext->myItem == 22);
//	assert(l1.myFirst->myNext->myNext->myItem == 33);
//	assert(l1.myLast->myItem == 33);
//	assert(l1.myLast->myNext == nullptr);
//	fin.close();
//	cout << " 0 " << flush;
//	cout << "Passed!" << endl;
//}

void ListTester::testPrepend() {
	cout << "Testing prepend..." << flush;
	List<double> l0;
	l0.prepend(4);
	assert(l0.mySize == 1);
	assert(l0.myFirst->myItem == 4);
	assert(l0.myFirst->myNext == nullptr);
	cout << " 0 " << flush;

	l0.prepend(3);
	assert(l0.mySize == 2);
	assert(l0.myFirst->myItem == 3);
	assert(l0.myFirst->myNext->myItem == 4);
	assert(l0.myFirst->myNext->myNext == nullptr);
	cout << " 1 " << flush;

	l0.prepend(2);
	assert(l0.mySize == 3);
	assert(l0.myFirst->myItem == 2);
	assert(l0.myFirst->myNext->myItem == 3);
	assert(l0.myFirst->myNext->myNext->myItem == 4);
	assert(l0.myFirst->myNext->myNext->myNext == nullptr);
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testGetIndexOf() {
	cout << "Testing getIndexOf..." << flush;

	List<double> l0;
	// test on empty list.
	assert(l0.getIndexOf(44) == -1);
	cout << " 0 " << flush;
	l0.append(11);
	l0.append(22);
	// search for non-existent item in non-empty list.
	assert(l0.getIndexOf(44) == -1);
	cout << " 1 " << flush;
	assert(l0.getIndexOf(11) == 0);
	cout << " 2 " << flush;
	assert(l0.getIndexOf(22) == 1);
	cout << " 3 " << flush;
	cout << "Passed! " << endl;
}

void ListTester::testInsertion() {
    cout << "Testing insert()..." << flush;
    List<double> l0;
    l0.insert(11, 0);
    assert(l0.mySize == 1);
    assert(l0.myFirst->myItem == 11);
    assert(l0.myFirst->myNext == nullptr);
    cout << " 0 " << flush;

    l0.insert(22, -1);
    assert(l0.mySize == 2);
    assert(l0.myFirst->myItem == 22);
    assert(l0.myFirst->myNext->myItem == 11);
    assert(l0.myFirst->myNext->myNext == nullptr);
    cout << " 1 " << flush;

    l0.insert(33, 88);
    assert(l0.mySize == 3);
    assert(l0.myLast->myItem == 33);
    cout << " 2 " << flush;

    l0.insert(7, 1);
    assert(l0.mySize == 4);
    assert(l0.myFirst->myItem == 22);
    assert(l0.myFirst->myNext->myItem == 7);
    assert(l0.myFirst->myNext->myNext->myItem == 11);
    cout << " 3 " << flush;

    cout << "Passed" << endl;
}

void ListTester::testRemove() {
    cout << "Testing remove()..." << flush;
    List<double> l0;
    l0.insert(11, 0);
    double i = l0.remove(0);
    assert(l0.mySize == 0);
    assert(l0.myFirst == nullptr);
    assert(l0.myLast == nullptr);
    assert(i == 11);
    cout << " 0 " << flush;

    l0.insert(22, -1);
    i = l0.remove(4);   // index is off end
    assert(l0.mySize == 0);
    assert(l0.myFirst == nullptr);
    assert(l0.myLast == nullptr);
    assert(i == 22);
    cout << " 1 " << flush;

    l0.append(33);
    assert(l0.mySize == 1);
    l0.append(22);
    i = l0.remove(4);   // index is off end
    assert(l0.mySize == 1);
    assert(l0.myFirst != nullptr);
    assert(l0.myLast != nullptr);
    assert(l0.myFirst->myItem == 33);
    assert(l0.myFirst->myNext == nullptr);
    assert(l0.myFirst == l0.myLast);
    assert(i == 22);
    cout << " 2 " << flush;

    l0.append(44);
    l0.append(55);
    l0.append(66);
    assert(l0.mySize == 4);
    i = l0.remove(2);   // index is 2nd-to-last node.
    assert(l0.mySize == 3);
    assert(l0.myFirst != nullptr);
    assert(l0.myLast != nullptr);
    assert(l0.getIndexOf(33) == 0);
    assert(l0.getIndexOf(44) == 1);
    assert(l0.getIndexOf(66) == 2);
    cout << " 3 " << flush;

    List<double> lempty;
    try {
    	lempty.remove(3);
    	cerr << "Error: calling remove should have failed" << endl;
    	exit(-1);
    } catch (underflow_error &) {
    	cout << " 4 " << flush;
    }

    cout << "Passed" << endl;
}
