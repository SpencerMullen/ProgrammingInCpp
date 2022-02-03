#ifndef MY_CODE
#define MY_CODE

#include<string>
#include<cstring>

using namespace std;

// int add with int
int add_me(int, int);

// float add with float
float add_me(double, double);

// int add with float (return cstring)
char* add_me(int, double);

// float add with int (return cstring)
string add_me(double, int);

// cstring add with cstring (returns double)
double add_me(const char*, const char*);

// cstring add with cstring (returns cstring)
char* add_me(string, string);

// float add with cstring to cstring
string add_me(double, string);

#endif