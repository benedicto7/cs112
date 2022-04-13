/* manageUserAccounts.cpp contains the "driver" for class AccountManager.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Heonjae(hk238) Ben(bee6)
 * Date: 12 Apr, 2022
 */

#include "AccountManager.h"

int main() {
	AccountManager manager("accountInfo.txt");
	manager.run();
}
