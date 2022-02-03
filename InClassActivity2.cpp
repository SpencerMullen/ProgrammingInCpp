/*
Spencer Mullen
Date: 9/20/2021
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Guest Book\n\n";

	string first_name;
	cout << "First name:\t";
	cin >> first_name;             // get first string only

	char middle_initial;
	cout << "Middle initial:\t";
	cin.ignore(100, '\n');         // ignore leftover chars and newline
	middle_initial = cin.get();    // get first char only

	string last_name;
	cout << "Last name:\t";
	cin.ignore(100, '\n');         // ignore leftover chars and newline
	getline(cin, last_name);       // get entire line

	string address;
	cout << "Address:\t";
	getline(cin, address);

	string city;
	cout << "City:\t\t";
	getline(cin, city);            // get entire line

	string state;
	cout << "State:\t\t";
	getline(cin, state);
	state.substr(0, 2);
	
	string postal_code;
	cout << "Postal code:\t";
	getline(cin, postal_code);

	string country;
	cout << "Country:\t";
	getline(cin, country);         // get entire line


	// Prints the entry.
	string entry = "\;ENTRY\;" + first_name + ' ' + middle_initial + ". " + last_name + '\;'
		+ address + '\;' + city + ", " + state + " " + postal_code + '\;' + country + "\;\;";

	cout << entry;

	//cout << "\nENTRY\n"            // display the entry
	//	<< first_name + ' ' + middle_initial + ". " + last_name + '\n'
	//	<< address + '\n'
	//	<< city + ", " + state + " " + postal_code + '\n'
	//	<< country + '\n' + '\n';
}