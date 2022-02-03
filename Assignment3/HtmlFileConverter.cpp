/*
Spencer Mullen
Date: 10/10/2021
Assignment 3 HtmlFileConverter
*/

#include <iostream>	
#include <string>
#include <fstream>

using namespace std;

int main() {
	// reading from files using ifstream
	ifstream infile("myfile.txt");
	// if infile pointer invalid
	if (!infile) {
		cout << "Can't open the file myfile.txt" << endl;
		return EXIT_FAILURE;
	}

	// writing to files using ofstream
	ofstream outfile("myfile.html");
	if (!outfile) {
		cout << "Can't open the file myfile.html" << endl;
		return EXIT_FAILURE;
	}

	// Title
	outfile << "<html>\n<title>\nThis is my C++ html converter, Spencer Mullen.\n</title>\n";
	// Heading using <h1>
	outfile << "<h1>\nSpencer Mullen's C++ to HTML converter\n</h1>\n";

	// Body
	outfile << "<body>" << endl;
	// read from myfile.txt and write to myfile.html
	string line;
	while (outfile && getline(infile, line)) {
		outfile << line << " <br>" << '\n';
	}

	// Paragraph text using <p>
	outfile << "<p>\nThis is some paragraph text.\n</p>\n";

	// Bold text using <b>
	outfile << "<b>\nThis is some bold text.\n</b>\n";

	// Closing tags
	outfile << "</body>\n</html>";
}