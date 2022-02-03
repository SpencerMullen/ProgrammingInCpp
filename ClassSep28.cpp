/*
Spencer Mullen
Date: 9/28/2021
Notes for class.
*/

#include <iostream>	
#include <string>
#include <bitset>

using namespace std;

int main() {
	
	// Print numbers from 20 --> 0 but only odd numbers
	//for (int i = 19; i > 0; i-=2) {
	//	cout << i << " ";
	//}
	//for (int i = 20; i > 0; i -= 2) {
	//	cout << i  - 1 << " ";
	//}


	// Ways to print a string using a loop
	//string str = "";
	//cin >> str;

	//for (int i = 0; i < str.length(); i++) {
	// These two are the same
	//	cout << str[i];
	//	cout << str.at(i);
	//}
	//cout << endl;
	//for (char ch : str) {
	//	cout << ch;
	//}

	// For loops allow you to have a comma seperated list for the initilization block
	// and the incrementation block (you can not have comma seperated conditionals)
	// However, you can have conditionals altered with logical operators
	//for (int i = 20, j = 10; i > 0 && j > 0; i -= 2, j-=2) {
	//	cout << --i << " ";
	//	j--;
	//}

	// Short circuiting to prevent errors
	//int i = 0; char ch;
	//while (i < str.size() && (ch = str.at(i)) != '\n') {
	//	cout << ch;
	//	i++;
	//}

	// POINTERS

	// Memory is allocated for the size of an int (4, 8, etc bytes depending on machine)
	// If you aren't sure, print a sizeof(datatype)
	int x;
	cout << "Enter an integer: ";
	cin >> x;
	// To find our the address of a variable, add an ampersan before the variable name
	// x has a box that stores an integer value of what we entered, size is 4 bytes for this machine
	// address is in hex
	cout << "Value: " << x << ", Address: " << &x << endl;

	// This variable, initialized by int*, is an integer pointer
	// Pointers are containers for memory addresses
	// Addresses have the same size regardless of type
	int* ptr_x = &x;
	// Since pointers are variables too, they have their own memory address as well

	// We can use memory addresses to find the contents of a variable
	// This is called dereferencing and it's used by using the * operator on a pointer variable
	cout << "Contents of x: " << *ptr_x << endl;

	// You can declare pointer variables with any of the following, spaces don't matter
	//int* ptr_y;
	//int *ptr_y;
	//int*ptr_y;
	//int * ptr_y;

	// Once you know the memory address/pointer of a variable, you can go to that variable and modify its value
	// You can restrict pointers to only be able to read the value, not write

	// Pointer of a pointer (possible since pointers are variables just like everything else)
	int  var;
	int* ptr1;
	int** ptr2;

	var = 500;

	// take the address of var
	ptr1 = &var;

	// take the address of ptr using address of operator &
	ptr2 = &ptr1;

	// take the value using pptr
	cout << "Value of var: " << var << endl;
	cout << "Value available at *ptr: " << *ptr1 << endl;
	cout << "Value available at **pptr: " << **ptr2 << endl;

	// STREAMS
	int x;
	// cout is an output stream, can only output
	cout << "Enter a value for x: ";
	// cin is an input stream, can only recieve input
	cin >> x;
	// both of these are one directional only

	while (cin) {

		cout << x << endl;
	}
}