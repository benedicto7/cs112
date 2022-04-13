/*
 * main.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 *      Student: Ben
 * 		Date: 2/16/22
 */

#include <cassert>
#include <string>
#include <iostream>
#include "CS112List.h"
using namespace std;

int main() {
	cout << "Test constructors...\n";
	CS112List<string> lst;
	assert(lst.getSize() == 0);

	CS112List<string> lst2(5);
	assert(lst2.getSize() == 5);

	cout << "Testing getValue\n";
	assert(lst2.getValue(0) == "");
	assert(lst2.getValue(4) == "");
	try {
		assert(lst2.getValue(5) == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "testing setValue\n";
	lst2.setValue(0, "hi");
	assert(lst2.getValue(0) == "hi");
	try {
		assert(lst2.getValue(5) == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "Testing []\n";
	assert(lst2[0] == "hi");  // getting the value
	lst2[1] = "hello";        // setting the value.
	assert(lst2[1] == "hello");
	try {
		assert(lst2[5] == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "Test copy constructor\n";
	CS112List<string> lst3(lst2);
	assert(lst3.getSize() == lst2.getSize());
	lst2[2] = "please work!";
	assert(lst3[2] != "please work!");

	cout << "Testing printing...\n";
	CS112List<string> lst4(2);
	lst4[0] = "Emma";
	lst4[1] = "Wang";
	cout << "This is a list -->" << lst4 << "<--\n";

	cout << "Testing append...\n";
	CS112List<string> aList;
	assert(aList.getSize() == 0);
	aList.append("Alex");
	assert(aList.getSize() == 1);
	assert(aList[0] == "Alex");
	cout << aList << endl;

	aList.append("Heyab");
	assert(aList.getSize() == 2);
	assert(aList[0] == "Alex");
	assert(aList[1] == "Heyab");
	cout << aList << endl;

	aList.append("Prof Norman is weird.");
	cout << aList << endl;

	cout << "Testing operator+" << endl;
	CS112List<string> l1;
	l1.append("Hi");
	CS112List<string> l2;
	l2.append("Nihao");
	l2.append("Konnichiwa");
	CS112List<string> l3 = l1 + l2;
	cout << l3 << endl;
	assert(l3.getSize() == 3);
	assert(l3[0] == "Hi");
	assert(l3[1] == "Nihao");
	assert(l3[2] == "Konnichiwa");

	cout << "Testing negative indexes..." << endl;
	assert(l3[-1] == "Konnichiwa");
	assert(l3[-2] == "Nihao");
	assert(l3.getItem(-2) == "Nihao");
	try {
		l3[-4];
		assert(false);
	} catch (const range_error &re) {
		// nothing here.
	}

	l3[-1] = "AufWiedersehen";
	assert(l3[2] == "AufWiedersehen");
	l3.setItem(-1, "Hallo");
	assert(l3[2] == "Hallo");

	//checking method find()
	l3.append("Hallo");

	assert(l3.find("Hallo") == 2);
	assert(l3.find("ssss") == -1);

	cout << endl;

	cout << "Testing insert() function..." << endl;
	CS112List<string> l4(6);
	l4.setValue(0, "Ben");
	l4.setValue(1, "Elpidius");
	l4.setValue(2, "Krisno");
	l4.setValue(3, "Sophomore");
	l4.setValue(4, "Computer Science");
	l4.setValue(5, "Calvin");
	assert(l4[1] == "Elpidius");
	assert(l4.getSize() == 6);

	cout << "Array of l4 before insert():" << endl;
	for (int i = 0; i < l4.getSize(); i++)
		{
		cout << l4.getValue(i) << endl;
		}

	// inserts 2 value
	l4.insert(4, "It's me mario!");
	l4.insert(0, "Professor");

	cout << "Array of l4 after insert():" << endl;
	for (int i = 0; i < l4.getSize(); i++)
		{
		cout << l4.getValue(i) << endl;
		}

	assert(l4[5] == "It's me mario!");
	assert(l4[6] == "Computer Science");
	assert(l4[7] == "Calvin");
	assert(l4[0] == "Professor");
	assert(l4[7] == "Calvin");
	assert(l4[5] == "It's me mario!");
	assert(l4.getSize() == 8);
	cout << "insert() passed" << endl;

	cout << endl;

	cout << "testing remove()..." << endl;
	// removes 2 value
	l4.remove("Professor");
	l4.remove("Krisno");
	assert(l4.getSize() == 6);

	cout << "Array of l4 after remove():" << endl;
	for (int i = 0; i < l4.getSize(); i++)
		{
		cout << l4.getValue(i) << endl;
		}

	assert(l4[0] == "Ben");
	assert(l4[2] == "Sophomore");

	cout << "Removing nothing (literally): " << l4.remove("nothing") << endl;

	cout << "remove() passed" << endl;

	cout << endl;

	cout << "testing removeAt()..." << endl;
	string firstRemoveAt = l4.removeAt(0);
	string secondRemoveAt = l4.removeAt(3);

	cout << "array of l4 after removeAt():" << endl;
	for (int i = 0; i < l4.getSize(); i++)
	{
		cout << l4.getValue(i) << endl;
	}

	assert(l4[0] == "Elpidius");
	assert(l4[3] == "Calvin");
	assert(l4.getSize() == 4);

	cout << "Value of removeAt(0): " << firstRemoveAt << endl;
	cout << "value of removeAt(3): " << secondRemoveAt << endl;
	cout << "removeAt() passed" << endl;

	cout << "All tests passed!\n";

	cout << endl;

	cout << "---Extra Credit---" << endl;
	CS112List<int> l5(10);

	// inputing values
	cout << "Inputing values into l5..." << endl;

	int x = 0;
	for (int i = 0; i < l5.getSize(); i++)
	{
		l5.setValue(i, x);
		x++;
	}

	// printing l5
	cout << "[";
	for (int i = 0; i < l5.getSize(); i++)
	{
		cout << l5.getValue(i);
		if (i < l5.getSize() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << endl;

	// first slice: stop_index
	CS112List<int> l6 = l5.slice(4); // 0 to 3

	cout << "Size after slice using stop_index (l6): " << l6.getSize() << endl;
	assert(&l5 != &l6); // asserts the address of l5 and l6
	assert(l5.getSize() == 10);

	// print out l6
	cout << "[";
	for (int i = 0; i < l6.getSize(); i++)
	{
		cout << l6.getValue(i);
		if (i < l6.getSize() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << endl;

	// second slice: start_index, stop_index
	CS112List<int> l7 = l5.slice(1, 4); // 1 to 3

	cout << "Size after slice using start_index and stop_index (l7): " << l7.getSize() << endl;
	assert(&l5 != &l7);

	// print out l7
	cout << "[";
	for (int i = 0; i< l7.getSize(); i++)
	{
		cout << l7.getValue(i);
		if (i < l7.getSize() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << endl;

	// third slice: start_index, stop_index, step_index
	CS112List<int> l8 = l5.slice(0, 9, 2); // 0 to 8, incremented by 2

	cout << "Size after slice using start_index, stop_index, and step_index (l8): " << l8.getSize() << endl;
	assert(&l5 != &l8);

	// print out l8
	cout << "[";
	for (int i = 0; i < l8.getSize(); i++)
	{
		cout << l8.getValue(i);
		if (i < l8.getSize() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << endl;

	// try invalid step index
	cout << "Trying invalid step_index..." << endl;
	try {
		CS112List<int> l9 = l5.slice(0, 9, 0);
		cerr << "Step_index = 0 succeeded." << endl;
		exit(1);
	} catch (const invalid_argument &ie) {
		cout << ie.what() << endl;
	}

	cout << endl;

	// try negative start index
	CS112List<int> l10 = l5.slice(-5, 5);

	cout << "Size after slice using negative start_index (l10): " << l10.getSize() << endl;

	// print out l10
	cout << "[";
	for (int i = 0; i < l10.getSize(); i++)
	{
		cout << l10.getValue(i);
		if (i < l10.getSize() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << endl;

	// try start index greater than mySize
	CS112List<int> l11 = l5.slice(0, 11);

	cout << "Size after slice using start_index greater than mySize (l11): " << l11.getSize() << endl;

	// print out l11
	cout << "[";
	for (int i = 0; i < l11.getSize(); i++)
	{
		cout << l11.getValue(i);
		if (i < l11.getSize() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << endl;

	// empty list with negative stop index smaller than -mySize
	CS112List<int> l12 = l5.slice(0,-11);

	cout << "Size after slice using stop_index smaller than -(mySize) for empty list (l12): " << l12.getSize() << endl;

	// print out l12
	cout << "[";
	for (int i = 0; i < l12.getSize(); i++)
	{
		cout << l12.getValue(i);
		if (i < l12.getSize() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << endl;

	cout << "All tests passed!\n";

	return 0;
}
