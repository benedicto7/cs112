/*
 * main.cpp
 *
 *  Created on: Jan 18, 2022
 *      Author: bee6
 */

#include <iostream>
#include <string>
using namespace std;

// Gets the name of the plan.
string getPlan(){
	string plan_name;
	while(true) {
		cout << "Enter plan name: ";
		getline(cin, plan_name);

		if ((plan_name == "gold") || (plan_name == "silver")) {
			break;
		}
		else {
			cout << "I'm sorry, " << plan_name << " is not a known plan." << endl;
			continue;
		}
	}
	return plan_name;
}

int getMonths() {
	cout << "Enter month: ";
	unsigned int month;
	cin >> month;
	return month;
}

// Returns the total cost for a plan.
string computeCost(string plan_name, int month) {
	if (plan_name == "silver") {
		if (month >= 2) {
			return "The cost for your plan is $60.";
		}
		else if (month == 1) {
			return "The cost for your plan is $90.";
		}
	}

	else if (plan_name == "gold") {
		if (month >= 7) {
			return "The cost for your plan is $35.";
		}
		else if (month >= 2) {
			return "The cost for your plan is $70.";
		}
		else if (month == 1) {
			return "The cost for your plan is $90.";
		}
	}
}

int main() {
	string plan = getPlan();
	int month = getMonths();
	string cost = computeCost(plan, month);
	cout << cost << endl;
}
