/*
Spencer Mullen
Date: 10/3/2021
Assignment 2 Printing Patterns.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	// Initialize variables
	bool quit = false;
	string decision = "";
	int pattern_size;

	// Menu command system
	while (!quit) {
		// Prompt user for pattern or quit
		cout << "Enter a pattern (A, B, C, D, E) or quit (Q): ";
		cin >> decision;

		// Quit if necessary
		if (decision == "Q") {
			cout << "Exiting program." << endl;
			quit = true;
		} else if (decision == "A" || decision == "B" || decision == "C" || decision == "D" || decision == "E") {
			cout << "\nEnter a size for your pattern: ";
			cin >> pattern_size;
		}

		cout << endl;

		// Handle patterns

		// First pattern
		if (decision == "A") {
			for (int i = 0; i < pattern_size; i++) {
				if (i % 2 == 0) {
					cout << "10101\n";
				} else {
					cout << "01010\n";
				}
			}
			cout << endl;

		// Second pattern
		} else if (decision == "B") {
			for (int i = 0; i < pattern_size * 2 - 1; i++) {
				// Depending on if we are on the first or second half, print accordingly
				// First half of triangle
				if (i < pattern_size) {
					for (int j = 0; j < i + 1; j++) {
						cout << "*";
					}
				// Second half of triangle
				} else {
					for (int j = pattern_size * 2 - i - 1; j > 0; j--) {
						cout << "*";
					}
				}
				cout << '\n';
			}
			cout << endl;

		// Third pattern
		} else if (decision == "C") {
			for (int i = 0; i < pattern_size * 2; i++) {
				// Depending on if we are on the first or second half, print accordingly
				// First half of pattern
				if (i < pattern_size) {
					for (int j = pattern_size, k = 0; j > i; j--, k++) {
						cout << char('A' + k) << " ";
					}
				}
				// Second half of pattern
				else {
					for (int j = 0; j < i - pattern_size + 1; j++) {
						cout << char('A' + j) << " ";
					}
				}
				cout << '\n';
			}
			cout << endl;

		// Fourth pattern
		} else if (decision == "D") {
			for (int i = 0; i < pattern_size * 2; i++) {
				// Depending on if we are on the first or second half, print accordingly
				// First half of pattern
				if (i < pattern_size) {
					for (int j = pattern_size, k = 0; j > i; j--, k++) {
						cout << "*";
					}
				}
				// Second half of pattern
				else {
					for (int j = 0; j < i - pattern_size + 1; j++) {
						cout << "*";
					}
				}
				cout << '\n';
			}
			cout << endl;

		// Fifth pattern
		// Prints 000000 when i is even and 111111 when i is odd
		} else if (decision == "E") {
			for (int i = 0; i < pattern_size; i++) {
				if (i % 2 == 0) {
					cout << "000000\n";
				}
				else {
					cout << "111111\n";
				}
			}
			cout << endl;
		// Invalid input
		} else {
			cout << "Invalid command. Please try again." << endl;
		}
	}
}