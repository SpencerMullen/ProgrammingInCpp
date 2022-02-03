/*
Spencer Mullen
Date: 10/3/2021
Assignment 2 Random Grade Generator.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <string>
#include <iostream>

using namespace std;

int main() {
	// Initialize variables and values
	string grades[12] = { "A", "A-", "B+", "B" , "B-" , "C+" , "C" , "C-" , "D+" , "D" , "D-" , "F" };
	srand(time(NULL));
	int index, num_grades;

	// Prompt user for num grades
	cout << "How many random grades do you want to print? ";
	cin >> num_grades;
	cout << endl;

	// Print random grades
	for (int i = 0; i < num_grades; i++) {
		index = rand() % 11;
		if (i > 0) {
			cout << ", ";
		}
		cout << grades[index];
	}
}