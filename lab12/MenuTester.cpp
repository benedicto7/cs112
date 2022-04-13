/* MenuTester.cpp defines test-methods for class Menu.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Heonjae(hk238) Ben(bee6)
 * Date: 12 Apr, 2022
 */
#include <cassert>
#include "MenuTester.h"

void MenuTester::runTests() {
	cout << "Testing the Menu class..." << endl;
	Menu m;
	assert( m.containsChoice('a') );
	assert( m.containsChoice('b') );
	assert( m.containsChoice('c') );
	assert( m.containsChoice('d') );
	assert( m.containsChoice('q') );
	assert( !m.containsChoice('e') );
	cout << "Passed!\n" << endl;
}

