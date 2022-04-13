/* Vec.h provides a simple vector class named Vec.
 * Student: ben (BEE6)
 * Date: 10/Feb/2022
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	virtual ~Vec();

	//copying operator
	Vec(const Vec& original);

	//assigning operator
	Vec& operator=(const Vec& original);
	
	//getter
	unsigned getSize() const;
	Item getItem(unsigned index) const;

	//setter
	void setItem(unsigned index, const Item& it);
	void setSize(unsigned newSize);

	//others
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);


private:
    unsigned mySize;
    Item *   myArray;
    friend class VecTester;

};

#endif /*VEC_H_*/
