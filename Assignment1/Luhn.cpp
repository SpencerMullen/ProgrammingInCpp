/*
Spencer Mullen
Date: 9/24/2021
This is the Luhn file for assignment 1.
*/

#include <iostream>	
#include <string>

using namespace std;


int main() {
	// variables for the credit card number, in groups of 4
	int group1;
	int group2;
	int group3;
	int group4;

	// recieve input from the user
	cout << "Enter a credit card (in groups of 4): ";
	cin >> group1 >> group2 >> group3 >> group4;

	// variables for doubling numbers and adding double digits for each group
	// double1 is for group1, double2 is for group2, etc...
	int double1;
	int double2;
	int double3;
	int double4;
	// calculate if the card is valid
	for (int i = 10; i < 1001; i *= 100) {
		// double the correct digit and add any double digits
		double1 = (group1 / i % 10) * 2;
		if (double1 >= 10) {
			double1 = (double1 / 10 % 10) + (double1 % 10);
		}
		double2 = (group2 / i % 10) * 2;
		if (double2 >= 10) {
			double2 = (double2 / 10 % 10) + (double2 % 10);
		}
		double3 = (group3 / i % 10) * 2;
		if (double3 >= 10) {
			double3 = (double3 / 10 % 10) + (double3 % 10);
		}
		double4 = (group4 / i % 10) * 2;
		if (double4 >= 10) {
			double4 = (double4 / 10 % 10) + (double4 % 10);
		}

		// put the new digit in its correct place
		if (i == 10) {
			group1 = (group1 / 1000 % 10 * 1000) + (group1 / 100 % 10 * 100) + (double1 * 10) + (group1 % 10);
			group2 = (group2 / 1000 % 10 * 1000) + (group2 / 100 % 10 * 100) + (double2 * 10) + (group2 % 10);
			group3 = (group3 / 1000 % 10 * 1000) + (group3 / 100 % 10 * 100) + (double3 * 10) + (group3 % 10);
			group4 = (group4 / 1000 % 10 * 1000) + (group4 / 100 % 10 * 100) + (double4 * 10) + (group4 % 10);
		} else {
			group1 = (double1 * 1000) + (group1 / 100 % 10 * 100) + (group1 / 10 % 10 * 10) + (group1 % 10);
			group2 = (double2 * 1000) + (group2 / 100 % 10 * 100) + (group2 / 10 % 10 * 10) + (group2 % 10);
			group3 = (double3 * 1000) + (group3 / 100 % 10 * 100) + (group3 / 10 % 10 * 10) + (group3 % 10);
			group4 = (double4 * 1000) + (group4 / 100 % 10 * 100) + (group4 / 10 % 10 * 10) + (group4 % 10);
		}
	}

	// add all numbers
	int sum = 0;
	for (int j = 1; j < 1001; j *= 10) {
		sum += (group1 / j % 10) + (group2 / j % 10) + (group3 / j % 10) + (group4 / j % 10);
	}
	
	// check whether the card is valid
	bool valid = (sum % 10 == 0);
	cout << "Card Validity: " << valid << endl;
}