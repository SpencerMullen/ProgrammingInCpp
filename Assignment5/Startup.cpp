/*
Spencer Mullen
Date: 10/24/2021
Startup for Assignment 5.
*/

#include <iostream>	
#include <string>
#include <bitset>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

// Group 1's methods for accessing the central list (pass by value)
vector<string> group1hire(vector<string> employees, string employee);

vector<string> group1fire(vector<string> employees, int index);

// Group 2's methods for modifying the central list (pass by reference)
void group2hire(vector<string> &employees, string employee);

void group2fire(vector<string>& employees, int index);

int main() {
	// central list of employees and titles
	vector<string> employees;

	employees.push_back("John, Founder");
	employees.push_back("Jane, Founder");
	employees.push_back("Spencer, Manager");
	employees.push_back("Paul, Manager");
	employees.push_back("Hannah, Engineer");
	employees.push_back("Alice, Engineer");
	employees.push_back("Edward, Designer");
	employees.push_back("Sam, Designer");

	cout << "Original central list: \n";
	for (auto i : employees) {
		cout << i << endl;
	}
	cout << endl;

	// Hire Sarah, Designer
	vector<string> sam_list = group1hire(employees, "Sarah, Designer");
	// Fire Spencer (can't because manager)
	sam_list = group1fire(sam_list, 2);
	// Fire Edward
	sam_list = group1fire(sam_list, 6);

	cout << "Sam's list: \n";
	for (auto i : sam_list) {
		cout << i << endl;
	}
	cout << endl;

	// Show that pass by value worked
	cout << "Unchanged central list: \n";
	for (auto i : employees) {
		cout << i << endl;
	}
	cout << endl;

	// Hire Alan, Marketer
	group2hire(employees, "Alan, Marketer");
	// Fire Paul, Manager
	group2fire(employees, 3);
	// Fire Alice, Engineer
	group2fire(employees, 4);

	// Show that pass by reference worked
	cout << "Updated central list: \n";
	for (auto i : employees) {
		cout << i << endl;
	}
	cout << endl;
}

// Group 1's method for hiring an employee
vector<string> group1hire(vector<string> employees, string employee) {
	employees.push_back(employee);
	return employees;
}

// Group 1's method for firing an employee (if they are not a founder or manager)
vector<string> group1fire(vector<string> employees, int i) {
	if (employees[i].substr(employees[i].length() - 7, employees[i].length() - 1) != "Founder" &&
		employees[i].substr(employees[i].length() - 7, employees[i].length() - 1) != "Manager") {
		employees.erase(employees.begin() + i);
	}
	return employees;
}

// Group 2's methods for hiring an employee
void group2hire(vector<string>& employees, string employee) {
	employees.push_back(employee);
}

// Group 2's method for firing an employee
void group2fire(vector<string>& employees, int i) {
	employees.erase(employees.begin() + i);
}