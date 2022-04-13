/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Heonjae, Ben
 * Date: 3/29/2022
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == nullptr ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template <class Item>
class BST {
public:
	// constructors
	BST();
	virtual ~BST();

	// getters
	bool isEmpty() const;
	unsigned getNumItems() const;
	unsigned getDuplicates() const;

	// recursion
	void insert(const Item & it);
	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	bool contains(const Item & it);
	long getHeight();

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();
            virtual void processItem();

            // recursion
            void insert(const Item & it);
            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            bool contains(const Item & it);
            long getHeight();

            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

template <class Item>
BST<Item>::BST(){
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = nullptr;
   myRight = nullptr;
}

template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

// check if BST is empty
template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

// return number of items in BST
template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

// cout BST in pre-order
template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

// pre-order recursion
template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();

	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}

	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

// cout BST in post-order
template <class Item>
void BST<Item>::traversePostorder(){
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

// post-order recursion
template <class Item>
void BST<Item>::Node::traversePostorder(){
	if (myLeft != nullptr) {
		myLeft -> traversePostorder();
	}

	if (myRight != nullptr) {
		myRight -> traversePostorder();
	}

	processItem();
}

// cout BST in in-order
template <class Item>
void BST<Item>::traverseInorder(){
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

// in-order recusion
template <class Item>
void BST<Item>::Node::traverseInorder(){
	if (myLeft != nullptr) {
		myLeft -> traverseInorder();
	}

	processItem();

	if (myRight != nullptr) {
		myRight -> traverseInorder();
	}
}


template <class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

// insert item in BST
template <class Item>
void BST<Item>::insert(const Item & it){
	if (myRoot == nullptr){
		Node * newNode = new Node(it);
		myRoot = newNode;
	}
	else {
		myRoot -> insert(it);
	}
	myNumItems++;
}

// insert recursion
template <class Item>
void BST<Item>::Node::insert(const Item & it) {
	if (myItem == it){
		throw Exception("insert()", "contains it");
	}

	if (myItem > it) {
		if (myLeft == nullptr) {
			Node * newNode = new Node(it);
			myLeft = newNode;
		}

		else{
			myLeft -> insert(it);
		}
	}

	if (myItem < it) {
		if (myRight == nullptr) {
			Node * newNode = new Node(it);
			myRight = newNode;
		}

		else{
			myRight -> insert(it);
		}
	}
}

// checks if item is in BST
template <class Item>
bool BST<Item>::contains(const Item & it) {
	if (myRoot == nullptr){
		return false;
	}

	else {
		myRoot -> contains(it);
	}
}

// contains recursion
template <class Item>
bool BST<Item>::Node::contains(const Item & it){
	if (it == myItem) {
		return true;
	}

	if (it > myItem) {
		if (myRight == nullptr) {
			return false;
		}

		myRight -> contains(it);
	}

	else {
		if (myLeft == nullptr) {
			return false;
		}

		myLeft -> contains(it);
	}
}

// return height of BST
template <class Item>
long BST<Item>::getHeight() {
	// check if BST is empty
	if (isEmpty()) {
		return 0;
	}

	else {
		myRoot->getHeight();
	}
}

// get height recursion
template <class Item>
long BST<Item>::Node::getHeight() {
	// 1. get height of left sub tree
	long leftHeight = (myLeft == nullptr) ? 0 : myLeft->getHeight();

	// 2. get height of right sub tree
	long rightHeight = (myRight == nullptr) ? 0 : myRight->getHeight();

	// 3. compare which is bigger
	long bigger = (leftHeight > rightHeight) ? leftHeight : rightHeight;

	// 4. return the bigger sub tree + 1 for root's height
	return (bigger + 1);
}

#endif /*BST_H_*/
