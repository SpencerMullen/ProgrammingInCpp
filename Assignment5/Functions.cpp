#include <iostream>
#include "Functions.hpp"
#include <stdlib.h> 
#include <time.h>
#include <algorithm>
#include <cstring>
#include <array>

using namespace std;

// int add with int
int add_me(int a, int b) {
	return a + b;
}

// float add with float
float add_me(double a, double b) {
	return a + b;
}

// int add with float (return cstring)
char* add_me(int a, double b) {
	string s = to_string(b + a);
	char cs[50];
	for (int i = 0; i < s.length(); i++) {
		cs[i] = s[i];
	}
	cs[s.length()] = '\0';
	return cs;
}

// float add with int (return cstring)
string add_me(double a, int b) {
	return add_me(b, a);
}

// cstring add with cstring to double
double add_me(const char* a, const char* b) {
	string st1 = a;
	string st2 = b;
	char chars[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < strlen(chars); i++) {
		st1.erase(std::remove(st1.begin(), st1.end(), chars[i]), st1.end());
		st2.erase(std::remove(st2.begin(), st2.end(), chars[i]), st2.end());
	}

	return stod(st1) + stod(st2);
}

// cstring add with cstring to cstring
char* add_me(string a, string b) {
	string st1 = a;
	string st2 = b;
	char chars[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < strlen(chars); i++) {
		st1.erase(std::remove(st1.begin(), st1.end(), chars[i]), st1.end());
		st2.erase(std::remove(st2.begin(), st2.end(), chars[i]), st2.end());
	}

	string s = to_string(stod(st1) + stod(st2));
	char cs[50];
	for (int i = 0; i < s.length(); i++) {
		cs[i] = s[i];
	}
	cs[s.length()] = '\0';
	return cs;
}

// float add with cstring to cstring
string add_me(double a, string b) {
	string st = "";
	string alpha = "";
	bool num = false;
	for (int i = 0; i < b.length(); i++) {
		if (isdigit(b[i])) {
			num = true;
		}
		if (isalpha(b[i])) {
			alpha += b[i];
		}
	}
	if (num)
		st += to_string(a + stod(b));
	else
		st += to_string(a);

	return st + alpha;
}