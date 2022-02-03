#include<iostream>
#include "ClassOct8f1.hpp"

using namespace std;

// You can organize functions into namespaces to be included in files
// Note: you must include declarations and definitions
namespace functions1 {
	// define function f1 that couts "f1" and requires no return because it's void
	// void in arguments is not necessary
	// this is function definition (need one for every function that we use)
	void f1(void) {
		cout << "f1" << endl;
	}

	// override functions
	void f1(int a) {
		cout << "f1" << a << endl;
	}

	// define function f2
	void f2(int a, string st) {
		cout << "f2" << st << endl;
	}
}

namespace functions2 {

	// define function f2
	void f2(int a) {
		cout << "f2" << a << endl;
	}

	// define function my_func1 (pass by value)
	int my_func1(int in) {
		cout << "In: " << &in << ", ";
		// This does not change the value of in, only passing in the value
		in = in + 100;
		return in;
	}

	// define function my_func2 (pass by reference)
	int my_func2(int& in) {
		cout << "In: " << &in << ", ";
		// This changes the actual value of in
		in = in + 100;
		return in;
	}

	// define function my_func3 (pass by pointer)
	int my_func3(int* in) {
		cout << "In: " << in << ", ";
		// This changes the actual value of in
		*in = *in + 100;
		return *in;
	}

	// define function print_me, function with array
	// alternate header to prevent changes from your array
	// void print_me(const int abc[], int size) {
	void print_me(int abc[], int size) {
		// In cpp, you always pass in a size argument because there is no way
		// to find the size of the array with only the starting address
		for (int i = 0; i < size; i++) {
			cout << abc[i] << " ";
			abc[i] += 10;
		}
		cout << endl;
	}
}