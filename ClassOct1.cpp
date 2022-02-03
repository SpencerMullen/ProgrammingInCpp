/*
Spencer Mullen
Date: 10/1/2021
Notes for class.
*/

#include <iostream>	
#include <string>
#include <bitset>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

int main() {

	// STREAMS
	//int x;
	// cout is an output stream, can only output
	//cout << "Enter a value for x: ";
	// cin is an input stream, can only recieve input
	//cin >> x;
	// both of these are one directional only

	//bitset<4> f_val(cin.rdstate());
	//cout << f_val << endl;
	//cout << "Bad: " << cin.bad() << " Fail: " << cin.fail() << " EOF: " << cin.eof() << " Good: " << cin.good() << endl;
	//cout << "rdstate: " << cin.rdstate();

	// Functions to check state flags
	// cin.good(); No errors (0 value io state, depends on other 3)
	// cin.eof(); End-of-File reached on input operation	
	// cin.fail(); Logical error on i/o operation (fail state still usable)
	// cin.bad(); Read/writing error on i/o operation (bad state not usable)
	// cin.rdstate(); Check the state flag directly

	// cin.failbit(); cin.badbit();

	int x = 0;

	// Entering a non int, like 'a' makes the it infinitely loop
	// To solve this you need to 1: clear the flags, 2: flush the stream
	while (true) {
		cout << "Enter a number: ";
		cin >> x;
		if (cin.good()) { // If the input is valid
			break;
		}
		else if (cin.bad()) { // You want to check if bad first because bad means it's unrecoverable
			cout << "Unrecoverable error" << endl;
			return EXIT_FAILURE;
		}
		else if (cin.eof()) { // If the end of file is reached
			cout << "Goodbye" << endl;
			return EXIT_SUCCESS;
		}
		else if (cin.fail()) { // If input is invalid
			cout << "Please try again" << endl;
			// clears the flags
			cin.clear();
			// flushes the stream up to the new line character
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else { // Should not be possible to get here
			cout << "Unknown error or state" << endl;
			return EXIT_FAILURE;
		}
	}
	cout << "Number is: " << x << endl;

	// iomanip library - input/output manipulators
	// Change text alignment
	// setw(x) changes the width of your indent to x spaces
	// if print length is more than the setw value, it juts prints it to the left (no truncate)
	cout << '\n' << "iomanip library" << endl;
	cout << setw(5) << 2 << '\n';
	cout << setw(5) << 54 << '\n';
	cout << setw(5) << 1329 << '\n';
	cout << setw(5) << 1000000 << endl;

	// fixed makes numbers in fixed point notation (decimals shown always) and 
	// setprecision sets how many decimals are to be shown
	cout << fixed << setprecision(3) << setw(7) << 25.1 << endl;
	cout << 25.1 << endl;
	// sticky vs non sticky
	// sticky: if you set something once it will affect the rest of the program if not changed again
	//	ex. fixed, setprecision(3)
	// nonsticky: if you set something once it will only affect the next value
	//	ex. setw


	// if you want to know which flags/settings you set, use
	// ios_base::fmtflags orig_flags = cout.flags(); these are the original flags
	// you would put this at the beginning of the code to save the original settings if you want to revert later

	// to set your settings to certain flags, use
	// cout.flags(orig_flags);


	// sstream library - string streams
	// create an instance of istringstream and give it the string "1 2 3 4"
	string numbers = "1 2 3 4";
	istringstream istr(numbers);

	cout << '\n' << "sstream library" << endl;
	int i;
	while (istr >> i) {
		cout << i << endl;
	}

	ostringstream ostr;
	for (int i = 0; i < 4; i++) {
		ostr << i << (i + 1 < 4? ", " : "");
	}
	cout << "The string is: " << ostr.str() << endl;


	// fstream library - file streams
	cout << '\n' << "fstream library" << endl;

	// you want to always move the file pointer forwards

	// another way to open a file
	// fstream file_name;
	// file_name.open("ClassOct1.txt", ios::in);

	// ios.in - read
	// ios.out - write
	// ios.app - append (read + write)

	// reading from files using ifstream
	ifstream infile("ClassOct1In.txt");
	// if infile pointer invalid
	if (!infile) {
		cout << "Can't open the file ClassOct1In.txt" << endl;
		return EXIT_FAILURE;
	}
	// print contents of infile
	string line;
	//while (getline(infile, line)) {
	//	cout << line << endl;
	//}

	// writing to files using ofstream
	ofstream outfile("ClassOct1Out.txt");
	if (!outfile) {
		cout << "Can't open the file ClassOct1Out.txt" << endl;
		return EXIT_FAILURE;
	}
	// write to file
	string line2;
	// note: can only do this if lines 142 to 144 are not being run because the pointer
	// would be at the end of the file already otherwise
	//while (outfile && getline(infile, line2)) {
	//	outfile << line2 << endl;
	//}

	cout << endl << endl;
	// this int is an unsigned int, not supposed to have negative numbers
	// treated it as twos compliment representation, negative one is all ones
	// therefore prints the largest int number
	unsigned int negative_one = -1;
	cout << negative_one << endl;

	// prints "-2 > 2" because comparing these two different types causes
	// -2 to change into an unsigned int making it a huge number, so
	// 1. don't compare different types or 2. use typecasting
	unsigned int two = 2;
	int minus_two = -2;

	if (minus_two < two)
		cout << "-2 < 2" << endl;
	else
		cout << "-2 > 2" << endl;

	// CPP Coersion Rules
	// 1. char, short, unsigned char ... are automatically promoted to ... int
	// others go from lower ranking to higher ranking (promote)
	// Ranking: int -> unsigned int -> long -> unsigned long -> float -> double -> long double
	// final value is converted to the type that it is being assigned to (demote if needed)

}