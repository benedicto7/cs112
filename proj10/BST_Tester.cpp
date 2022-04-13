/* BST_Tester.cpp defines test-methods for class BST.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Heonjae, Ben
 * Date: 3/29/2022
 */
 
#include "BST_Tester.h"
#include <string>
#include <fstream>
#include <cassert>

void BST_Tester::runTests() {
	cout << "Testing class BST" << endl;
	testConstructor();
	testInsert();
	testContains();
	testTraverse();
	testGetHeight();
	testRandomInts();
	cout << "All tests passed!" << endl;
}

void BST_Tester::testGetHeight() {
	cout << "Testing getHeight()..." << flush;
	BST<int> bst;
	// empty
	assert( bst.getHeight() == 0 );
	cout << " 0 " << flush;
	// balanced
	bst.insert(44);
	assert( bst.getHeight() == 1 );
	cout << " 1a " << flush;
	bst.insert(22);
	assert( bst.getHeight() == 2 );
	cout << " 1b " << flush;
	bst.insert(66);
	assert( bst.getHeight() == 2 );
	cout << " 1c " << flush;
	bst.insert(77);
	assert( bst.getHeight() == 3 );
	cout << " 1d " << flush;
	bst.insert(55);
	assert( bst.getHeight() == 3 );
	cout << " 1e " << flush;
	bst.insert(33);
	assert( bst.getHeight() == 3 );
	cout << " 1f " << flush;
	bst.insert(11);
	assert( bst.getHeight() == 3 );
	cout << " 1g " << flush;
	bst.insert(88);
	assert( bst.getHeight() == 4 );
	cout << " 1h " << flush;
	// ascending chain
      BST<int> bst2a;
      bst2a.insert(11);
      bst2a.insert(22);
      bst2a.insert(33);
      bst2a.insert(44);
      bst2a.insert(55);
      bst2a.insert(66);
      bst2a.insert(77);
      assert( bst2a.getHeight() == 7 );
      cout << " 2a " << flush;
	// descending chain
      BST<int> bst2b;
      bst2b.insert(77);
      bst2b.insert(66);
      bst2b.insert(55);
      bst2b.insert(44);
      bst2b.insert(33);
      bst2b.insert(22);
      bst2b.insert(11);
      assert( bst2b.getHeight() == 7 );
      cout << " 2b " << flush;
	// height-3 trees
	BST<int> bst3a;
	bst3a.insert(44);
	bst3a.insert(22);
	bst3a.insert(33);
	bst3a.insert(55);
	assert( bst3a.getHeight() == 3 );
      cout << " 3a " << flush;
	BST<int> bst3b;
	bst3b.insert(44);
	bst3b.insert(33);
	bst3b.insert(22);
	bst3b.insert(55);
	assert( bst3b.getHeight() == 3 );
      cout << " 3b " << flush;
	BST<int> bst3c;
	bst3c.insert(44);
	bst3c.insert(33);
	bst3c.insert(55);
	bst3c.insert(66);
	assert( bst3c.getHeight() == 3 );
      cout << " 3c " << flush;
	BST<int> bst3d;
	bst3d.insert(44);
	bst3d.insert(33);
	bst3d.insert(66);
	bst3d.insert(55);
	assert( bst3d.getHeight() == 3 );
      cout << " 3d " << flush;
      // height-4 trees
      BST<int> bst4a;
      bst4a.insert(44);
      bst4a.insert(66);
      bst4a.insert(77);
      bst4a.insert(55);
      bst4a.insert(33);
      bst4a.insert(22);
      bst4a.insert(11);
	assert( bst4a.getHeight() == 4 );
      cout << " 4a " << flush;
      BST<int> bst4b;
      bst4b.insert(44);
      bst4b.insert(66);
      bst4b.insert(77);
      bst4b.insert(55);
      bst4b.insert(33);
      bst4b.insert(11);
      bst4b.insert(22);
	assert( bst4b.getHeight() == 4 );
      cout << " 4b " << flush;
      BST<int> bst4c;
      bst4c.insert(44);
      bst4c.insert(22);
      bst4c.insert(11);
      bst4c.insert(33);
      bst4c.insert(66);
      bst4c.insert(55);
      bst4c.insert(77);
      bst4c.insert(88);
	assert( bst4c.getHeight() == 4 );
      cout << " 4c " << flush;
      BST<int> bst4d;
      bst4d.insert(44);
      bst4d.insert(22);
      bst4d.insert(11);
      bst4d.insert(33);
      bst4d.insert(66);
      bst4d.insert(55);
      bst4d.insert(88);
      bst4d.insert(77);
	assert( bst4d.getHeight() == 4 );
      cout << " 4d " << flush;
      BST<int> bst4e;
      bst4e.insert(44);
      bst4e.insert(22);
      bst4e.insert(11);
      bst4e.insert(33);
      bst4e.insert(77);
      bst4e.insert(88);
      bst4e.insert(66);
      bst4e.insert(55);
	assert( bst4e.getHeight() == 4 );
      cout << " 4e " << flush;
      BST<int> bst4f;
      bst4f.insert(44);
      bst4f.insert(22);
      bst4f.insert(11);
      bst4f.insert(33);
      bst4f.insert(77);
      bst4f.insert(88);
      bst4f.insert(55);
      bst4f.insert(66);
	assert( bst4f.getHeight() == 4 );
      cout << " 4f " << flush;
	cout << " Passed!" << endl;
}

void BST_Tester::testTraverse() {
	cout << "Testing traverse()..." << endl;
	BST<int> bst;
	bst.insert(55);
	bst.insert(33);
	bst.insert(11);
	bst.insert(22);
	bst.insert(44);
	bst.insert(77);
	bst.insert(99);
	bst.insert(88);
	bst.insert(66);
	cout << "- Preorder: expecting: 55 33 11 22 44 77 66 99 88" << endl;
	cout << "- Got                :" << flush;
	bst.traversePreorder(); cout << endl;
	cout << "\n- Postorder: expecting: 22 11 44 33 66 88 99 77 55" << endl;
	cout << "- Got                 :" << flush;
	bst.traversePostorder(); cout << endl;
	cout << "\n- Inorder: expecting: 11 22 33 44 55 66 77 88 99" << endl;
	cout << "- Got               :" << flush;
	bst.traverseInorder(); cout << endl;
		cout << " Passed!" << endl;
}

void BST_Tester::testContains() {
	cout << "Testing contains()... " << flush;
	// empty bst
	BST<int> bst;
	assert( !bst.contains(55) );
	cout << " 1 " << flush;
	// non-empty bst
	bst.insert(55);
	assert( bst.contains(55) );
	cout << " 2 " << flush;

	bst.insert(33);
	bst.insert(77);
	assert( bst.contains(55) );
	assert( bst.contains(33) );
	assert( bst.contains(77) );
	assert( !bst.contains(11) );
	assert( !bst.contains(111) );
	cout << " 3 " << flush;

	bst.insert(11);
	bst.insert(22);
	bst.insert(44);
	bst.insert(66);
	bst.insert(88);
	bst.insert(99);
	for (int i = 1; i <= 100; ++i) {
		if ( i % 11 ) {
			assert( !bst.contains(i) );
		} else {
			assert( bst.contains(i) );
		}
	}
	cout << " 4 " << flush;

	cout << " Passed!" << endl;
}

void BST_Tester::testInsert() {
	cout << "Testing insert()... " << flush;
	BST<int> bst;
	assert( bst.isEmpty() );
	cout << " 0 " << flush;
	bst.insert(55);
	assert( !bst.isEmpty() );
	assert( bst.myRoot != nullptr );
	assert( bst.myRoot->myItem == 55 );
	assert( bst.myRoot->myLeft == nullptr );
	assert( bst.myRoot->myRight == nullptr );
	assert( bst.getNumItems() == 1 );
	cout << " 1 " << flush;

	bst.insert(33);
	assert( bst.getNumItems() == 2 );
	assert( bst.myRoot->myRight == nullptr );
	assert( bst.myRoot->myLeft != nullptr );
	assert( bst.myRoot->myRight == nullptr );
	assert( bst.myRoot->myLeft->myItem == 33 );
	cout << " 2 " << flush;

	bst.insert(44);
	assert( bst.getNumItems() == 3 );
	assert( bst.myRoot->myRight == nullptr );
	assert( bst.myRoot->myLeft->myRight != nullptr );
	assert( bst.myRoot->myLeft->myRight->myItem == 44 );
	cout << " 3 " << flush;

	bst.insert(11);
	assert( bst.getNumItems() == 4 );
	assert( bst.myRoot->myRight == nullptr );
	assert( bst.myRoot->myLeft->myLeft != nullptr );
	assert( bst.myRoot->myLeft->myLeft->myItem == 11 );
	cout << " 4 " << flush;

	bst.insert(22);
	assert( bst.getNumItems() == 5 );
	assert( bst.myRoot->myRight == nullptr );
	assert( bst.myRoot->myLeft->myLeft->myRight != nullptr );
	assert( bst.myRoot->myLeft->myLeft->myRight->myItem == 22 );
	cout << " 5 " << flush;

	bst.insert(77);
	assert( bst.getNumItems() == 6 );
	assert( bst.myRoot->myRight != nullptr );
	assert( bst.myRoot->myRight->myItem == 77 );
	cout << " 6 " << flush;

	bst.insert(66);
	assert( bst.getNumItems() == 7 );
	assert( bst.myRoot->myRight->myLeft->myItem == 66 );
	cout << " 7 " << flush;

	bst.insert(99);
	assert( bst.getNumItems() == 8 );
	assert( bst.myRoot->myRight->myRight->myItem == 99 );
	cout << " 8 " << flush;

	bst.insert(88);
	assert( bst.getNumItems() == 9 );
	assert( bst.myRoot->myRight->myRight->myLeft->myItem == 88 );
	cout << " 9 " << flush;

	try {
		bst.insert(55);
	} catch (Exception& e) {
		cout << " 10 " << flush;
	}

	try {
		bst.insert(11);
	} catch (Exception& e) {
		cout << " 11 " << flush;
	}

	try {
		bst.insert(88);
	} catch (Exception& e) {
		cout << " 12 " << flush;
	}

	bst.insert(111);
	assert( bst.getNumItems() == 10 );
	assert( bst.myRoot->myRight->myRight->myRight->myItem == 111 );
	cout << " 13 " << flush;

	cout << " Passed!" << endl;
}

void BST_Tester::testConstructor() {
	cout << "Testing constructor... " << flush;
	BST<int> bst;
	assert( bst.isEmpty() );
	assert( bst.getNumItems() == 0 );
	assert( bst.myRoot == nullptr );
	assert( bst.myNumItems == 0 );
	cout << "Passed!" << endl;
}

void BST_Tester::testRandomInts() {
	cout << "Testing randomInts01.txt" << flush;
	ifstream fin1 ("randomInts01.txt");
	assert(fin1.is_open());

	BST<long> r1;

	string file1;
	unsigned duplicate_count_1;
	while(getline(fin1, file1)) {
		try {
			if (fin1.eof()) {
				break;
			}

			r1.insert(stol(file1));
		}
		catch (...) {
			duplicate_count_1++;
		}
	}

	cout << endl;
	cout << "Height" << r1.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_1 << endl;

	cout << "Testing randomInts02.txt" << flush;
	ifstream fin2 ("randomInts02.txt");
	assert(fin2.is_open());

	BST<long> r2;

	string file2;
	unsigned duplicate_count_2;
	while(getline(fin2, file2)) {
		try {
			if (fin2.eof()) {
				break;
			}

			r2.insert(stol(file2));
		}
		catch (...) {
			duplicate_count_2++;
		}
	}

	cout << endl;
	cout << "Height: " << r2.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_2 << endl;

	cout << "Testing randomInts03.txt" << flush;
	ifstream fin3 ("randomInts03.txt");
	assert(fin3.is_open());

	BST<long> r3;

	string file3;
	unsigned duplicate_count_3;
	while(getline(fin3, file3)) {
		try {
			if (fin3.eof()) {
				break;
			}

			r3.insert(stol(file3));
		}
		catch (...) {
			duplicate_count_3++;
		}
	}

	cout << endl;
	cout << "Height: " << r3.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_3 << endl;

	cout << "Testing randomInts04.txt" << flush;
	ifstream fin4 ("randomInts04.txt");
	assert(fin4.is_open());

	BST<long> r4;

	string file4;
	unsigned duplicate_count_4;
	while(getline(fin4, file4)) {
		try {
			if (fin4.eof()) {
				break;
			}

			r4.insert(stol(file4));
		}
		catch (...) {
			duplicate_count_4++;
		}
	}

	cout << endl;
	cout << "Height: " << r4.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_4 << endl;

	cout << "Testing randomInts05.txt" << flush;
	ifstream fin5 ("randomInts05.txt");
	assert(fin5.is_open());

	BST<long> r5;

	string file5;
	unsigned duplicate_count_5;
	while(getline(fin5, file5)) {
		try {
			if (fin5.eof()) {
				break;
			}

			r5.insert(stol(file5));
		}
		catch (...) {
			duplicate_count_5++;
		}
	}

	cout << endl;
	cout << "Height: " << r5.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_5 << endl;

	cout << "Testing randomInts06.txt" << flush;
	ifstream fin6 ("randomInts06.txt");
	assert(fin6.is_open());

	BST<long> r6;

	string file6;
	unsigned duplicate_count_6;
	while(getline(fin6, file6)) {
		try {
			if (fin6.eof()) {
				break;
			}

			r6.insert(stol(file6));
		}
		catch (...) {
			duplicate_count_6++;
		}
	}

	cout << endl;
	cout << "Height: " << r6.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_6 << endl;

	cout << "Testing randomInts07.txt" << flush;
	ifstream fin7 ("randomInts07.txt");
	assert(fin7.is_open());

	BST<long> r7;

	string file7;
	unsigned duplicate_count_7;
	while(getline(fin7, file7)) {
		try {
			if (fin7.eof()) {
				break;
			}

			r7.insert(stol(file7));
		}
		catch (...) {
			duplicate_count_7++;
		}
	}

	cout << endl;
	cout << "Height: " << r7.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_7 << endl;

	cout << "Testing randomInts08.txt" << flush;
	ifstream fin8 ("randomInts08.txt");
	assert(fin8.is_open());

	BST<long> r8;

	string file8;
	unsigned duplicate_count_8;
	while(getline(fin8, file8)) {
		try {
			if (fin8.eof()) {
				break;
			}

			r8.insert(stol(file8));
		}
		catch (...) {
			duplicate_count_8++;
		}
	}

	cout << endl;
	cout << "Height: " << r8.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_8 << endl;

	cout << "Testing randomInts09.txt" << flush;
	ifstream fin9 ("randomInts09.txt");
	assert(fin9.is_open());

	BST<long> r9;

	string file9;
	unsigned duplicate_count_9;
	while(getline(fin9, file9)) {
		try {
			if (fin9.eof()) {
				break;
			}

			r9.insert(stol(file9));
		}
		catch (...) {
			duplicate_count_9++;
		}
	}

	cout << endl;
	cout << "Height: " << r9.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_9 << endl;

	cout << "Testing randomInts10.txt" << flush;
	ifstream fin10 ("randomInts10.txt");
	assert(fin10.is_open());

	BST<long> r10;

	string file10;
	unsigned duplicate_count_10;
	while(getline(fin10, file10)) {
		try {
			if (fin10.eof()) {
				break;
			}

			r10.insert(stol(file10));
		}
		catch (...) {
			duplicate_count_10++;
		}
	}

	cout << endl;
	cout << "Height: " << r10.getHeight() << endl;
	cout << "Duplicate: " << duplicate_count_10 << endl;
}
