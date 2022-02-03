/*
Spencer Mullen
Date: 10/22/2021
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

int main() {
	// Pointers
	
	// Different types of variables have different sizes but
	// addresses of pointers, regardless of type, have same size (8 bytes)

	// int v = 108;
	// To get the value of a variable
	// --> v
	// To get the address of a variable, add an ampersand & to the front of it
	// --> &v
	// To store an address, make a pointer variable by using *
	// int *p or int* p or int * p or int*p = &v;
	// --> p
	// To get the address of a pointaer variable, add an ampersand & to the front of it
	// --> &p
	
	// int arr[5] = {1, 2, 5, 7, 19};
	// int *pa = arr or &arr[0] or &arr
	// difference between pa and arr
	// --> arr is a constant pointer and pa is not
	// arr[0], pa[0], *pa, *(pa + 0), *arr --> all of these print 1 (first element of arr)
	// incrementing a pointer by doing pa++ means that pa now points to 2 (second element of arr)

	// 2D Pointers

	// char suit; -----> single char variable
	// char* suit; ----> single char pointer
	// char suit[4]; --> array of char variables
	// char* suit[4]; -> array of char pointers

	// const char* suit[4] = {"Hello", "Hi", "How", "Bye"};
	// suit is a 2d array of pointers pointing to cstrings
	// double pointer to point to suit
	// char **ps = suit;

	// *suit[1] = suit[1][0] // both would print 'H' in "Hi"
	// Note: square brackets [] have precedence over dereference star *
	// --> *(*(suit + 1) + 0) same as above statements (0 is unnecessary)

	// suit[1][1] = *(*(ps + 1) + 1) // both would print 'i' in "Hi"
	// dereference is same as square brackets, can replace ps in above statement with suit
	// using name of array is same as pointer to beginning of array


}