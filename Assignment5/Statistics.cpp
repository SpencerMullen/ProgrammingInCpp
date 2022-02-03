/*
Spencer Mullen
Date: 10/24/2021
File Statistics for Assignment 5.
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

int main() {
	// Prompt user for file
	string user_file;
	cout << "Enter a filename: ";
	cin >> user_file;

	int sum = 0;
	int alphabet = 0;
	int upper = 0;
	float percentage;
	int words = 0;
	int exclamation = 0;
	int punctuation = 0;

	// Read from file
	fstream file(user_file);
	if (!file) {
		cout << "Can't open the file" << endl;
		return EXIT_FAILURE;
	}

	string line;
	char st[500];
	while (getline(file, line)) {
		// Calculate values
		const char delta[] = " ";
		// Convert line into a cstring to use strtok on
		strcpy(st, line.c_str());

		if (strlen(st) != 0) {
			// Returns the string up to that token
			char* tok = strtok(st, delta);

			// Continue until you reach the end of the line
			while (tok) {
				// Words
				words++;
				// Exclamation
				if (tok[strlen(tok) - 1] == '!') {
					exclamation += 1;
				}
				for (int i = 0; i < strlen(tok); i++) {
					// Alphabetic + Upper
					if (isalpha(tok[i])) {
						alphabet++;
						if (isupper(tok[i])) {
							upper++;
						}
					// Numeric
					}
					else if (isdigit(tok[i])) {
						sum += tok[i] - '0';
					}
					// Punctuation
					else if (ispunct(tok[i])) {
						punctuation++;
					}
				}

				tok = strtok(nullptr, delta);
			}
		}
	}
	string user_out_file;
	cout << "Enter an out file: ";
	cin >> user_out_file;

	// Write to file the results
	ofstream outfile(user_out_file);
	if (!outfile) {
		cout << "Can't open the file" << endl;
		return EXIT_FAILURE;
	}

	percentage = (upper * 1.0) / alphabet * 100;
	outfile << "Sum of numbers: " << sum << endl;
	outfile << "English alphabet/characters: " << upper << "/" << alphabet << " = " << percentage << "%" << endl;
	outfile << "Total words: " << words << endl;
	outfile << "Words that end in !: " << exclamation << endl;
	outfile << "Punctuation marks: " << punctuation << endl;
}
