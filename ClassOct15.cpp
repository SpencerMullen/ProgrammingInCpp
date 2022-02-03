/*
Spencer Mullen
Date: 10/15/2021
Notes for class.
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

using namespace std;
/*
int main() {
	// cstring vs string
	// string class has a lot of overhead, takes a long time for huge inputs
	// cstring is just a character array with a null character to signify end
	// cstring is treated just like a normal array
	// the null character at the end is \0, the ASCII value for null character is 0
	
	// ways to create a cstring
	char ch = '\0'; //'A';
	char ch_arr1[] = {'1','2','3','4','5'};
	// double quotes automatically places a null character at the end of string
	char ch_arr2[] = "Hello";
	char ch_arr3[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	// compared to ch_arr2, there is an arr of size 15, first 5 are "Hello"
	// the remaining 10 will all be null characters
	char ch_arr4[15] = "Hello";
	// this just puts the char value of 0 into the array
	char ch_arr5[] = {0}; // NULL
	char ch_arr6[] = { '\0' }; // NULL
	// cstring library assumes you already have a null character at end, so include it
	cout << "Sizes: " << sizeof(ch_arr4) << " " << strlen(ch_arr4) << endl;


	// print contents of ch_arr4, shows that remaining chars are null
	for (int i = 0; i < sizeof(ch_arr4); i++) {
		cout << static_cast<int>(ch_arr4[i]) << " ";
	}
	cout << endl;

	// If you overflow the bounds of a cstring,
	// it will mess up the values of variables next to the cstring
	int x = 5;
	char str[8];
	cout << x << '\n';
	// When using cstring, don't use cin to read from keyboard
	// use getline instead to avoid issues
	// cin >> str; // <-- entering a string longer than 8 will produce an error
	cin.getline(str, 8);
	cout << str << '\n';
	cout << x << endl;

	// cstring functions
	char st1[100] = "Hello";
	char st2[] = "World";
	//char st3[] = st1 + st2; // you can't concatenate like this anymore, need function
	cout << "strcat: " << strcat(st1, st2) << " "; 
	cout << strncat(st1, st2, 3) << endl;
	//cout << strcmp(st2, st1) << endl;

	// ways of going through a cstring
	char st3[] = "Today is Friday, Yay!";
	char* pp = st3;
	int i = 0;
	// going through until you reach null char
	while (st3[i] != '\0') {
		cout << st3[i] << " ";
		i++;
	}
	cout << endl;
	// using pointers
	while (*pp) {
		cout << *pp << " ";
		pp++;
	}
	cout << endl;

	// using token
	char st4[] = "What's up people!";
	unsigned int len = strlen(st4);
	cout << "st4: " << st4 << endl;
	const char delta[] = " ";
	// Returns the string up to that token
	char* tok = strtok(st4, delta);
	cout << "tok: " << tok << " st4: " << st4 << endl;
	// in subsequent calls of strtok, function expects a null 
	// pointer and uses the position right after the end of the last token
	// to read to the second token, you need to use the null 
	// pointer to go back to the previous call
	while (tok) {
		cout << "tok: " << tok << " st4: " << st4 << endl;
		tok = strtok(nullptr, delta);
	}

	//

}
*/