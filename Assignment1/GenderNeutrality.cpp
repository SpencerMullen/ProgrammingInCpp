/*
Spencer Mullen
Date: 9/24/2021
This is the UPC file for assignment 1.
*/

#include <iostream>	
#include <string>

using namespace std;

int main() {
	// recieve the paragraph from the user
	string paragraph;
	cout << "Enter the paragraph you would like to process: ";
	getline(cin, paragraph);
	cout << "\n" << paragraph << endl;

	// process the paragraph, replacing gender-specific words
	bool complete = false;
	size_t pos;
	size_t size;
	string gender_specific[9] = { "wife", "man", "daughter", "sister", "brother", "girls", "boys", "his", "her" };

	do {
		for (string s : gender_specific) {
			pos = paragraph.find(s);
			size = s.length();
			// check for flagged words
			if (pos != string::npos) {
				if (s == "wife") {
					paragraph.replace(pos, size, "spouse");
				}
				else if (s == "man") {
					paragraph.replace(pos, size, "person");
				}
				else if (s == "daughter") {
					paragraph.replace(pos, size, "child");
				}
				else if (s == "sister") {
					paragraph.replace(pos, size, "sibling");
				}
				else if (s == "brother") {
					paragraph.replace(pos, size, "sibling");
				}
				else if (s == "girls") {
					paragraph.replace(pos, size, "kids");
				}
				else if (s == "boys") {
					paragraph.replace(pos, size, "kids");
				}
				else {
					paragraph.replace(pos, size, "their");
				}
			}
		} 

	} while (pos != string::npos);

	cout << "\n" << paragraph << endl;
	
}