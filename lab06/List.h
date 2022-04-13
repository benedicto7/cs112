/*
 * List.h
 *
 * student: Heonjae(hk238), Ben(bee6)
 * date: 22 Feb 2022
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using namespace std;

template <class Item>
class List {
public:
	// constructor
	List();

	// copy constructor
	List(const List<Item> &original);

	// destructor
	virtual ~List();

	// getters
	unsigned getSize() const {return mySize;}
	Item getFirst() const;
	Item getLast() const;
	int getIndexOf(const Item &it) const;

	// others
	void prepend(const Item &it);
	void append(const Item &it);
	void writeTo(ostream &out) const;
	bool Equality(const List<Item> &comp)const;

private:
	struct Node {
		Node();
		Node(Item it, Node* next);
		virtual ~Node();
		Item myItem;
		Node *myNext;
	};
	unsigned mySize;
	Node *myFirst;
	Node *myLast;

	friend class ListTester;
};

template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = nullptr;
}

template <class Item>
List<Item>::List(const List<Item> &original){
	mySize = 0;
	myFirst = myLast = nullptr;

	for (Node* curr = original.myFirst; curr != nullptr; curr = curr -> myNext){
		this -> append(curr -> myItem);
	}
}

template <class Item>
List<Item>::~List() {
	mySize = 0;
	delete myFirst;
	myFirst = myLast = nullptr;
}

template <class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

template <class Item>
List<Item>::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

template <class Item>
List<Item>::Node::~Node() {
	// cout << "~Node() is deallocating the node containing item "
	//		<< myItem << endl;
	delete myNext;
	myNext = nullptr;
}

template <class Item>
Item List<Item>::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("list is empty");
	}
	return myFirst->myItem;
}

template <class Item>
Item List<Item>::getLast() const {
	if (mySize == 0) {
		throw underflow_error("list is empty");
	}
	return myLast->myItem;
}

template <class Item>
void List<Item>::prepend(const Item &it) {
	Node *newNode = new Node(it, myFirst);
	myFirst = newNode;
	if (mySize == 0) {
		myLast = newNode;
	}
	mySize++;
}

template <class Item>
void List<Item>::append(const Item &it) {
	Node *newNode = new Node(it, nullptr);
	if (mySize == 0) {
		myFirst = newNode;
	}
	else {
		myLast -> myNext = newNode;
	}
	myLast = newNode;
	mySize++;
}

template <class Item>
int List<Item>::getIndexOf(const Item &it) const {
	int result = 0;
	for (Node * curr = myFirst; curr != nullptr; curr = curr-> myNext){
		if (curr -> myItem == it){
			return result;
		}
		result++;
	}
	return -1;
}

template <class Item>
bool List<Item>::Equality(const List<Item> &comp)const {
	if (mySize != comp.mySize){
		return false;
	}
	else{
		Node * node1 = myFirst;
		Node * node2 = comp.myFirst;

		while (node1 != nullptr){
			if (node1 -> myItem != node2 -> myItem){
				return false;
			}
			node1 = node1 -> myNext;
			node2 = node2 -> myNext;
		}
	}
	return true;
}

template <class Item>
void List<Item>::writeTo(ostream &out) const {
	for (Node *curr = myFirst; curr != nullptr; curr = curr->myNext) {
		out << curr->myItem << " ";
	}
}

#endif /* LIST_H_ */
