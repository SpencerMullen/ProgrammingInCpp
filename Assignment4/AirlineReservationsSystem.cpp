/*
Spencer Mullen
Date: 10/17/2021
Assignment 4 - Airline Reservations System.
*/

#include <iostream>	
#include <algorithm>
#include <string>
#include <bitset>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include "SystemDeclarations.hpp"

using namespace std;

int main() {

	// 2D array to represent the seat availability on the plane
	int seats[20][7];
	// 2D vector to represent the names of passengers on the plane
	vector<vector<string>> names;
	// String vector to represent the manifest of passengers
	vector <string> manifest;

	for (int i = 0; i < 20; i++) {
		names.push_back(vector<string>());
		for (int j = 0; j < 7; j++) {
			seats[i][j] = 0;
			names.at(i).push_back("");
		}
	}

	// Give the following menu options to the user: 
	int option = 0;
	while (option != 8) {
		// Print commands
		if ((option > 8 || option < 1) && cin.good()) {
			cout << "Enter a valid command:\n" << "(1) Load Previous \"Seat Assignment and Passenger Manifest\"\n";
			cout << "(2) Save Current \"Seat Assignment and Passenger Manifest\"\n" << "(3) Choose a seat (with the help of automated system)\n";
			cout << "(4) Cancel seat assignment\n" << "(5) Print boarding pass\n";
			cout << "(6) Display the seating map\n" << "(7) Prints a passenger manifest\n" << "(8) Quit the program\n";
			cin >> option;
			cout << endl;
		}
		// If cin fails, reset
		if (!cin.good()) {
			option = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		// load previous seat assignment and passenger manifest
		if (option == 1) {
			// reading from files using ifstream
			ifstream infile("system.txt");
			// if infile pointer invalid
			if (!infile) {
				cout << "Can't open the file system.txt" << endl;
				return EXIT_FAILURE;
			}
			string line;
			getline(infile, line);
			// Get the seat assignment
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 7; j++) {
					getline(infile, line);
					if (line != "0") {
						seats[i][j] = 1;
						names[i][j] = line;
					}
				}
			}
			getline(infile, line);
			// Get the passenger manifest
			while (getline(infile, line)) {
				manifest.push_back(line);
			}
		}

		// save current seat assignment and passenger manifest
		if (option == 2) {
			// writing to files using ofstream
			ofstream outfile("system.txt");
			if (!outfile) {
				cout << "Can't write to file system.txt" << endl;
				return EXIT_FAILURE;
			}
			// Write the passengers to file
			outfile << "SEAT ASSIGNMENT\n";
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 7; j++) { 
					if (seats[i][j] == 1) {
						outfile << names[i][j];
					}
					else {
						outfile << "0";
					}
					outfile << '\n';
				}
			}

			// Write the manifest to file
			outfile << "MANIFEST" << endl;
			// send entries into a vector
			stringstream entry;
			manifest = {};
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 7; j++) {
					if (seats[i][j] == 1) {
						entry << left << setw(15) << names[i][j] << setw(7) << getSeat(i * 20 + j);
						manifest.push_back(entry.str());
						entry.str("");
					}
				}
			}
			for (int i = 0; i < manifest.size(); i++) {
				outfile << manifest[i] << '\n';
			}
		}

		// choose a seat
		char seat;
		if (option == 3) {
			cout << "Please choose a class:\n'F' for first class\n";
			cout << "'B' for business class\n Others will be economy class\n";
			cin >> seat;
			// Check what class user entered
			if (seat != 'F' && seat != 'B') {
				seat = 'E';
			}
			assignSeat(seat, seats, names);
			cout << endl;
		}

		// cancel seat assignment
		if (option == 4) {
			string seat;
			int seatNum;
			cout << "Which seat would you like to cancel? ";
			cin >> seat;
			seatNum = getSeatNum(seat);
			seats[seatNum / 7][seatNum % 7] = 0;
			names[seatNum / 7][seatNum % 7] == "";
		}

		// prints a boarding pass for a chosen seat number
		if (option == 5) {
			string seat;
			int seatNum;
			cout << "Enter the seat: \n";
			cin >> seat;
			seatNum = getSeatNum(seat);
			if (seats[seatNum / 7][seatNum % 7] == 0) {
				cout << "Seat Unassigned - No boarding pass available. Try again!";
			} else {
				cout << names[seatNum / 7][seatNum % 7] << ", SEAT: ";
				cout << getSeat(seatNum) << ", Level: " << getLevel(seatNum);
			}
		}

		// display the seating map
		if (option == 6) {
			char row = 'A';
			for (int i = 0; i < 9; i++) {
				cout << static_cast<char>(row + i) << " ";
			}
			cout << endl;
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 7; j++) {
					cout << seats[i][j] << " ";
					if (j == 1 || j == 4) {
						cout << "  ";
					}
				}
				cout << "| " << i + 1;
				if (i == 2 || i == 6)
					cout << endl;
				cout << endl;
			}
		}

		// prints a passenger manifest
		if (option == 7) {
			string alphab;
			cout << "Do you want to print the manifest in alphabetical format? (Y/N): ";
			cin >> alphab;
			cout << left << setw(15) << "Name" << setw(7) << "Seat" << endl;
			
			// send entries into a vector
			manifest = {};
			stringstream entry;
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 7; j++) {
					if (seats[i][j] == 1) {
						entry << left << setw(15) << names[i][j] << setw(7) << getSeat(i * 7 + j);
						manifest.push_back(entry.str());
						entry.str("");
					}
				}
			}
			// sort if alphabetical
			if (alphab == "Y") {
				sort(manifest.begin(), manifest.end());//sort the vector
			}

			for (string s : manifest) {
				cout << s << endl;
			}
		}

		if (option == 8) {
			break;
		}

		// Reset option
		option = 0;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
	}

	// if user quits
	if (option == 8) {
		cout << "Quitting..." << endl;
		return EXIT_SUCCESS;
	}
}