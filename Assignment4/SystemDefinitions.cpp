#include <iostream>
#include "SystemDeclarations.hpp"
#include <stdlib.h> 
#include <time.h>

using namespace std;

// Check if a certain class is full
bool classFull(int seats[20][7], char seat) {
	// Check if first class is full
	if (seat == 'F') {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				if (seats[i][j] == 0) {
					return false;
				}
			}
		}
		return true;
		// Check if business class is full
	}
	else if (seat == 'B') {
		for (int i = 3; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (seats[i][j] == 0) {
					return false;
				}
			}
		}
		return true;
		// Check if economy class is full
	}
	else {
		for (int i = 8; i < 20; i++) {
			for (int j = 0; j < 7; j++) {
				if (seats[i][j] == 0) {
					return false;
				}
			}
		}
		return true;
	}
}

// Assigns a random seat
void assignSeat(char seat, int seats[20][7], vector<vector<string>> &names) {
	srand(time(NULL));

	int randomSeat, initialSeat, finalSeat;
	string downgraded = "N", downgraded2 = "N";
	// first class
	if (seat == 'F') {
		// if first class is full
		if (classFull(seats, 'F')) {
			cout << "First class is full. Would you like to move to business class? (Y/N)\n";
			cin >> downgraded;
			if (downgraded == "Y") {
				cout << "Moving to business..." << endl;
			}
			else {
				cout << "Thank you. Choose the next available flight." << endl;
				return;
			}
		}
		// generate random seat
		randomSeat = rand() % 21;
	// business class
	} else if ((seat == 'B' || downgraded == "Y") && downgraded2 == "N") {
		// if business class is full
		if (classFull(seats, 'B')) {
			cout << "Business class is full. Would you like to move to economy class? (Y/N)\n";
			cin >> downgraded2;
			if (downgraded2 == "Y") {
				cout << "Moving to economy..." << endl;
			}
			else {
				cout << "Thank you. Choose the next available flight." << endl;
				return;
			}
		}
		// generate random seat
		randomSeat = rand() % 28 + 21;
	// economy class
	} else {
		if (classFull(seats, 'E')) {
			cout << "Flight is full. Choose the next available flight." << endl;
			return;
		}
		// generate random seat
		randomSeat = rand() % 91 + 49;
	}

	// get the initial seat
	initialSeat = randomSeat;//seats[randomSeat / 7][randomSeat % 7];
	cout << "Initial Seat Selection: " << getLevel(initialSeat) << ": " << getSeat(initialSeat) << endl;
	string upgrade = "N", downgrade = "N";

	// upgrade / downgrade
	if (getLevel(initialSeat) != "First Class") {
		cout << "Do you wish to upgrade? (Y/N)\n";
		cin >> upgrade;
	}
	if (upgrade == "Y") {
		// Upgrade if business
		if (getLevel(initialSeat) == "Business") {
			if (classFull(seats, 'F')) {
				cout << "All seats are full. Next flight leaves in 3 hours." << endl;
			}
			else {
				randomSeat = rand() % 21;
			}
		// Upgrade if economy
		} else {
			// Upgrade to business
			if (classFull(seats, 'B')) {
				// Upgrade to first class
				if (classFull(seats, 'F')) {
					cout << "All seats are full. Next flight leaves in 3 hours." << endl;
				}
				else {
					randomSeat = rand() % 21;
				}
			} else {
				randomSeat = randomSeat = rand() % 49 + 21;
			}
		}
	}

	// Downgrade
	if (upgrade != "Y" && getLevel(initialSeat) != "Economy") {
		cout << "Do you wish to downgrade? (Y/N)\n";
		cin >> downgrade;
	}
	if (downgrade == "Y") {
		// Downgrade if business
		if (getLevel(initialSeat) == "Business") {
			if (classFull(seats, 'E')) {
				cout << "All seats are full. Next flight leaves in 3 hours." << endl;
			}
			else {
				randomSeat = rand() % 140 + 49;
			}
		// Downgrade if First Class
		} else {
			// Downgrade to business
			if (classFull(seats, 'B')) {
				// Downgrade to economy
				if (classFull(seats, 'E')) {
					cout << "All seats are full. Next flight leaves in 3 hours." << endl;
				} else {
					randomSeat = rand() % 140 + 49;
				}
			} else {
				randomSeat = randomSeat = rand() % 49 + 21;
			}
		}
	}

	// Set seat position as taken
	finalSeat = randomSeat;
	if (upgrade != "Y" && downgrade != "Y")
		finalSeat = initialSeat;
	seats[finalSeat / 7][finalSeat % 7] = 1;
	cout << "Final Seat Selection: " << getLevel(finalSeat) << ": " << getSeat(finalSeat) << endl;

	// Get the name of passenger
	string name;
	cout << "Enter your name: ";
	cin >> name;
	names[finalSeat / 7][finalSeat % 7] = name;
}

// Returns the seatNum given a seat
int getSeatNum(string seat) {
	int seatNum = 0;
	if (seat[0] == 'A') {
		seatNum += 0;
	}
	else if (seat[0] == 'B') {
		seatNum += 1;
	}
	else if (seat[0] == 'D') {
		seatNum += 2;
	}
	else if (seat[0] == 'E') {
		seatNum += 3;
	}
	else if (seat[0] == 'F') {
		seatNum += 4;
	}
	else if (seat[0] == 'H') {
		seatNum += 5;
	}
	else if (seat[0] == 'I') {
		seatNum += 6;
	}
	seatNum += ((seat[1] - '0') - 1) * 7;
	return seatNum;
}

// Returns the seat given a seatNum
string getSeat(int seatNum) {
	string seat = "";
	if (seatNum % 7 == 0) {
		seat += "A";
	}
	else if (seatNum % 7 == 1) {
		seat += "B";
	}
	else if (seatNum % 7 == 2) {
		seat += "D";
	}
	else if (seatNum % 7 == 3) {
		seat += "E";
	}
	else if (seatNum % 7 == 4) {
		seat += "F";
	}
	else if (seatNum % 7 == 5) {
		seat += "H";
	}
	else if (seatNum % 7 == 6) {
		seat += "I";
	}
	seat += to_string(seatNum / 7 + 1);

	return seat;
}

// Gets the class given a seatNum
string getLevel(int seatNum) {
	string level = "First Class";
	if (seatNum >= 21) {
		level = "Business";
	}
	if (seatNum >= 49) {
		level = "Economy";
	}

	return level;
}