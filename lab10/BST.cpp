/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Heonjae, Ben
 * Date: 3/29/2022
 */
 
#include "BST.h"


BST::BST(){
	myRoot = nullptr;
	myNumItems = 0;
}

BST::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = nullptr;
   myRight = nullptr;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

void BST::traversePostorder(){
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

void BST::Node::traversePostorder(){
	if (myLeft != nullptr) {
		myLeft -> traversePostorder();
	}
	if (myRight != nullptr) {
		myRight -> traversePostorder();
	}
	processItem();
}

void BST::traverseInorder(){
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

void BST::Node::traverseInorder(){
	if (myLeft != nullptr) {
		myLeft -> traverseInorder();
	}
	processItem();
	if (myRight != nullptr) {
		myRight -> traverseInorder();
	}
}

void BST::Node::processItem() {
		cout << ' ' << myItem;
}

void BST::insert(const Item & it){
	if (myRoot == nullptr){
		Node * newNode = new Node(it);
		myRoot = newNode;
	}
	else {
		myRoot -> insert(it);
	}
	myNumItems++;
}

void BST::Node::insert(const Item & it) {
	if (myItem == it){
		throw Exception("insert()", "contains it");
	}

	if (myItem > it) {
		if (myLeft == nullptr) {	
			Node * newNode = new Node(it);
			myLeft = newNode;
		}
		else {
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

bool BST::contains(const Item & it) {
	if (myRoot == nullptr){
		return false;
	}
	else {
		myRoot -> contains(it);
	}
}

bool BST::Node::contains( const Item & it){
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
