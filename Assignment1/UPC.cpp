/*
Spencer Mullen
Date: 9/24/2021
This is the UPC file for assignment 1.
*/

#include <iostream>	
#include <string>

using namespace std;


int main() {
	// initialize variables
	int manufacturer_code;
	int product_code;
	int check_digit;

	// recieve input from the user
	cout << "Enter the manufacturer code: ";
	cin >> manufacturer_code;
	cout << "\nEnter the product code: ";
	cin >> product_code;
	cout << "\nEnter the check digit: ";
	cin >> check_digit;
	cout << endl;

	// calculate if the code is valid
	int step_a = (manufacturer_code / 10 % 10) + (manufacturer_code / 1000 % 10);
	int step_b = (product_code % 10) + (product_code / 100 % 10) + (product_code / 10000 % 10);
	int step_c = 3 * (step_a + step_b);
	int step_d = (manufacturer_code % 10) + (manufacturer_code / 100 % 10) + (manufacturer_code / 10000 % 10);
	int step_e = (product_code / 10 % 10) + (product_code / 1000 % 10);
	int step_f = step_d + step_e + step_c;
	int step_g = step_f % 10;
	int step_h = 10 - step_g;

	// print the result
	bool valid = (step_h == check_digit);
	cout << "Code Validity " << valid;
}
