#ifndef MY_CODE
#define MY_CODE

#include<string>

using namespace std;

// You can organize functions into namespaces to be included in files
// Note: you must include declarations and definitions
namespace functions1 {
	// this is function declaration
	void f1(void);

	// override function declaration
	void f1(int a);
	// for declarations only, you don't need a variable name, only type is required
	// ex.
	// void f1(int);

	// If we use the exact type (int or double) this override raises no problems.
	// Problems arise with this when we try to use a float.
	// Float will be converted to the closest valid type and passed in.
	// void f1(double a);

	// default argument declaration
	// if only and int a is passed, function will assume st is "Hello"
	void f2(int a, string st = "Hello");
}

// Another namespace
namespace functions2 {
	// you can not have a default argument declaration and an override declaration that takes in the
	// same arguments as such. This will raise an ambiguous error unless we use namespaces and 
	// specify which namespace it is from.
	void f2(int a);

	// my_func1 declaration (pass by value)
	int my_func1(int in);

	// my_func2 declaration (pass by reference)
	int my_func2(int& in);

	// my_func3 declaration (pass by pointer)
	int my_func3(int* in);

	// print_me declaration, uses arrays
	void print_me(int abc[], int size);
}

// this is to ensure we don't have an endless cycle where we are including files over and over again
#endif