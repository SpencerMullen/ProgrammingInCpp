/*
Spencer Mullen
Partner: Ethan
Date: 9/17/2021
This is my in class assignment 1 ver 2.

Lines of code: 57 --> 51
*/

#include <iostream>
#include <string>
using namespace std;


int main()
{
	string first_name, last_name, class_standing;
	int grad_year;
	double GPA;

	cout << "Enter your first name, last name, graduation year,\nclass standing (freshman, sophomore, junior, senior, etc.), and your ideal GPA.\n";

	cin >> first_name >> last_name >> grad_year >> class_standing >> GPA;

	cout << GPA << class_standing << grad_year << last_name << first_name;

	int index1, index2, index3;
	cout << "\n\nEnter 3 integer values (5 or less).\n";
	cin >> index1 >> index2 >> index3;

	// If the index is greater than the length of the string, return the last character in the stirng.
	char char1, char2, char3;
	if (index1 < first_name.length() - 1) {
		char1 = first_name.at(index1);
	}
	else {
		char1 = first_name.at(first_name.length() - 1);
	}
	if (index2 < last_name.length() - 1) {
		char2 = last_name.at(index2);
	}
	else {
		char2 = last_name.at(last_name.length() - 1);
	}
	if (index3 < class_standing.length() - 1) {
		char3 = class_standing.at(index3);
	}
	else {
		char3 = class_standing.at(class_standing.length() - 1);
	}

	string combined = "";
	combined = combined + char1 + char2 + char3;

	int ascii = static_cast<int>(char1) + static_cast<int>(char2) + static_cast<int>(char3);

	cout << "Combined String: " << combined << ", Ascii: " << ascii << ", Sqrt: " << sqrt(GPA) << ", Cbrt: " << cbrt(GPA);

	return EXIT_SUCCESS;
}
