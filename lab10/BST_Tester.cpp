/* BST_Tester.cpp defines test-methods for class BST.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Heonjae, Ben
 * Date: 3/29/2022
 */
 
 #include "BST_Tester.h"
#include <cassert>

void BST_Tester::runTests() {
	cout << "Testing class BST" << endl;
	testConstructor();
	testInsert();
	testContains();
	testTraverse();
//	testGetHeight();
	cout << "All tests passed!" << endl;
}

//void BST_Tester::testGetHeight() {
//	cout << "Testing getHeight()..." << flush;
//	BST bst;
//	// empty
//	assert( bst.getHeight() == 0 );
//	cout << " 0 " << flush;
//	// balanced
//	bst.insert(44);
//	assert( bst.getHeight() == 1 );
//	cout << " 1a " << flush;
//	bst.insert(22);
//	assert( bst.getHeight() == 2 );
//	cout << " 1b " << flush;
//	bst.insert(66);
//	assert( bst.getHeight() == 2 );
//	cout << " 1c " << flush;
//	bst.insert(77);
//	assert( bst.getHeight() == 3 );
//	cout << " 1d " << flush;
//	bst.insert(55);
//	assert( bst.getHeight() == 3 );
//	cout << " 1e " << flush;
//	bst.insert(33);
//	assert( bst.getHeight() == 3 );
//	cout << " 1f " << flush;
//	bst.insert(11);
//	assert( bst.getHeight() == 3 );
//	cout << " 1g " << flush;
//	bst.insert(88);
//	assert( bst.getHeight() == 4 );
//	cout << " 1h " << flush;
//	// ascending chain
//      BST bst2a;
//      bst2a.insert(11);
//      bst2a.insert(22);
//      bst2a.insert(33);
//      bst2a.insert(44);
//      bst2a.insert(55);
//      bst2a.insert(66);
//      bst2a.insert(77);
//      assert( bst2a.getHeight() == 7 );
//      cout << " 2a " << flush;
//	// descending chain
//      BST bst2b;
//      bst2b.insert(77);
//      bst2b.insert(66);
//      bst2b.insert(55);
//      bst2b.insert(44);
//      bst2b.insert(33);
//      bst2b.insert(22);
//      bst2b.insert(11);
//      assert( bst2b.getHeight() == 7 );
//      cout << " 2b " << flush;
//	// height-3 trees
//	BST bst3a;
//	bst3a.insert(44);
//	bst3a.insert(22);
//	bst3a.insert(33);
//	bst3a.insert(55);
//	assert( bst3a.getHeight() == 3 );
//      cout << " 3a " << flush;
//	BST bst3b;
//	bst3b.insert(44);
//	bst3b.insert(33);
//	bst3b.insert(22);
//	bst3b.insert(55);
//	assert( bst3b.getHeight() == 3 );
//      cout << " 3b " << flush;
//	BST bst3c;
//	bst3c.insert(44);
//	bst3c.insert(33);
//	bst3c.insert(55);
//	bst3c.insert(66);
//	assert( bst3c.getHeight() == 3 );
//      cout << " 3c " << flush;
//	BST bst3d;
//	bst3d.insert(44);
//	bst3d.insert(33);
//	bst3d.insert(66);
//	bst3d.insert(55);
//	assert( bst3d.getHeight() == 3 );
//      cout << " 3d " << flush;
//      // height-4 trees
//      BST bst4a;
//      bst4a.insert(44);
//      bst4a.insert(66);
//      bst4a.insert(77);
//      bst4a.insert(55);
//      bst4a.insert(33);
//      bst4a.insert(22);
//      bst4a.insert(11);
//	assert( bst4a.getHeight() == 4 );
//      cout << " 4a " << flush;
//      BST bst4b;
//      bst4b.insert(44);
//      bst4b.insert(66);
//      bst4b.insert(77);
//      bst4b.insert(55);
//      bst4b.insert(33);
//      bst4b.insert(11);
//      bst4b.insert(22);
//	assert( bst4b.getHeight() == 4 );
//      cout << " 4b " << flush;
//      BST bst4c;
//      bst4c.insert(44);
//      bst4c.insert(22);
//      bst4c.insert(11);
//      bst4c.insert(33);
//      bst4c.insert(66);
//      bst4c.insert(55);
//      bst4c.insert(77);
//      bst4c.insert(88);
//	assert( bst4c.getHeight() == 4 );
//      cout << " 4c " << flush;
//      BST bst4d;
//      bst4d.insert(44);
//      bst4d.insert(22);
//      bst4d.insert(11);
//      bst4d.insert(33);
//      bst4d.insert(66);
//      bst4d.insert(55);
//      bst4d.insert(88);
//      bst4d.insert(77);
//	assert( bst4d.getHeight() == 4 );
//      cout << " 4d " << flush;
//      BST bst4e;
//      bst4e.insert(44);
//      bst4e.insert(22);
//      bst4e.insert(11);
//      bst4e.insert(33);
//      bst4e.insert(77);
//      bst4e.insert(88);
//      bst4e.insert(66);
//      bst4e.insert(55);
//	assert( bst4e.getHeight() == 4 );
//      cout << " 4e " << flush;
//      BST bst4f;
//      bst4f.insert(44);
//      bst4f.insert(22);
//      bst4f.insert(11);
//      bst4f.insert(33);
//      bst4f.insert(77);
//      bst4f.insert(88);
//      bst4f.insert(55);
//      bst4f.insert(66);
//	assert( bst4f.getHeight() == 4 );
//      cout << " 4f " << flush;
//	cout << " Passed!" << endl;
//}


void BST_Tester::testTraverse() {
	cout << "Testing traverse()..." << endl;
	BST bst;
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
	BST bst;
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
	BST bst;
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
	BST bst;
	assert( bst.isEmpty() );
	assert( bst.getNumItems() == 0 );
	assert( bst.myRoot == nullptr );
	assert( bst.myNumItems == 0 );
	cout << "Passed!" << endl;
}

