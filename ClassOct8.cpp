/*
Spencer Mullen
Date: 10/8/2021
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
// our file that contains the function definition for f1()
#include "ClassOct8f1.hpp"

using namespace std;
// namespace we created to use f1() and f2()
using namespace functions1;
using namespace functions2;

int main() {

	int arr[5] = { 1,2,3,4,5 };
	int* p_arr = arr;
	// All of these are equivalent
	cout << "arr[0] = " << arr[0] << ", p_arr[0] = " << p_arr[0];
	cout << ", *p_arr = " << *p_arr << ", *arr = " << *arr << endl;
	// arr vs p_arr
	// arr is a constant pointer, will always point to the memory address of the first element
	// p_arr is not a constant poitner, you can move it to a different location

	// You can mimic this with other elements using an offset
	// Square brackets are the same as dereferencing
	cout << "arr[1] = " << arr[1] << ", p_arr[1] = " << p_arr[1];
	// We can change p_arr like this and it will change what it's pointing to
	p_arr++;
	//arr++; // This will return an error because arr can not be changed
	cout << ", *p_arr = " << *p_arr << ", (*arr + 1) = " << (*arr + 1) << endl;

	// vectors use built-in arrays and guarentees that elements are found in contiguous memory locations
	// you can expand/shrink the size of vectors easily
	// vector<type> name(size) = {values seperated by commas};
	// use name.push_back(element); to add elements to a vector
	
	// int vector
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(10);
	v1.push_back(23);

	cout << "int vector: ";
	v1.resize(10, 123);
	for (auto i : v1) {
		cout << i << " ";
	}
	cout << endl;

	// string vector
	vector<string> v2 = {"Hello", "Hi", "Bye"};
	v2.push_back("Friday");
	// insert expands the vector
	// inserts weekend in between "Bye" and "Friday" by using index 3
	v2.insert(v2.begin() + 3, "Weekend");

	// can use auto here so that the compiler automatically determines the type for you
	cout << "string vector: ";
	for (auto i : v2) {
		cout << i << " ";
	}
	cout << endl;
	
	// 2 dimensional arrays
	cout << "2d array\n";
	int arr2d[5][4] = { {1, 2, 3, 4}, {5, 6, 7}, {8, 9}, {10}, {} };
	// the second row in memory is right after the first row and so on (like a 1d array)
	// print the 2d array
	// the '&' symbol is used because square brackets '[]' are used for dereferencing
	// since we used 2 square brackets for the 2d array, we need an additional pointer
	for (auto& row : arr2d) {
		for (auto j : row) {
			cout << j << " ";
		}
		cout << endl;
	}

	// 2 dimensional vectors
	// unlike with 2 dimensional arrays, multiple vectors are not guarenteed to have contiguous memory locations
	// there is only a guarentee of contiguous memory locations within individual vectors
	cout << "2d vector\n";
	vector<vector<int>> vv;
	vector<int> v = { 1, 2, 3, 4 };
	for (int ii = 0; ii < 5; ii++) {
		vv.push_back(v);
	}

	for (auto& row : vv) {
		for (auto j : row) {
			cout << j << " ";
		}
		cout << endl;
	}
	// ^^ same as
	// for (int ii = 0; ii < 5; ii++) {
	//	for (int jj = 0; jj < 4; jj++) {
	//		cout << vv[ii][jj] << " ";
	//	}
	//	cout << endl;
	// }

	// values are the same, memory addresses are different
	// int x = 100;
	// int y = x;
	// cout << x << ", " << y << endl;
	// cout << &x << ", " << &y << endl;

	// however, if we put an ampersand in front of y, it stores the reference of x in that variable
	// this notation is called a reference variable, now the values and the memory addresses are the same
	// Note: doesn't store an address
	int x = 100;
	int &y = x;
	cout << x << ", " << y << endl;
	cout << &x << ", " << &y << endl;

	// functions, methods (coming from Java), procedures (coming from C)
	// functions are like variables, if you want to use them, declare them
	// similar to variables, you need to define functions top-->down since that's how code is read
	// we can use a function declaration at the top and define it at the bottom

	// we put the function declaration for f1() in the file "ClassOct8f1.hpp"
	// we put the function definition for f1() in the file "ClassOct8f1.cpp"
	// we included our hpp file at the top
	f1();
	// When you have many namespaces or functions with the same name, use this
	functions1::f1();

	// you can also overload functions by changing arguments

	// Functions called in main
	// Declarations in a header file, hpp
	// Definitions in a separate cpp file

	// Pass by value vs pass by reference (vs pass by pointer)
	// To actually change the value of xyz, we need to pass by reference or pointer
	// Passing by value only passes the value of xyz into the function
	int xyz = 100;
	int* p_xyz = &xyz;
	cout << "xyz: " << xyz << ", " << &xyz << endl;
	cout << "Pass by value: " << my_func1(xyz) << endl;
	cout << "xyz: " << xyz << ", " << &xyz << endl;
	cout << "Pass by reference: " << my_func2(xyz) << endl;
	cout << "xyz: " << xyz << ", " << &xyz << endl;
	cout << "Pass by pointer: " << my_func3(p_xyz) << endl;
	cout << "xyz: " << xyz << ", " << &xyz << endl;
	cout << endl;

	// Use function to print array
	int aaa[5] = { 1, 2, 3, 4 };
	print_me(aaa, 5);
	// Notice how aaa retains its changes from function print_me
	for (int i : aaa) {
		cout << i << " ";
	}
	// When you pass in array arguments, you are passing the address of the array
	// into your function and functions can modify it.
	// To stop this from happening, you can create a copy of the array (lot of storage)
	// or define the array as a const.

	// In Java, you could pass in a 2d array as an argument by entering int[][]
	// However, in C/C++ you must leave the first square bracket empty and every
	// subsequent square bracket having their size written --> int[][4]
	// This is because C++ needs the pointer as an argument

	// Comparing arrays with == doesn't compare values, it compares starting addresses
}