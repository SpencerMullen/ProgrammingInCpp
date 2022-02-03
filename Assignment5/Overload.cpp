/*
Spencer Mullen
Date: 10/24/2021
Overload Functions for Assignment 5.
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
#include <cstdlib>
#include <cctype>
#include "Functions.hpp"

using namespace std;

int main() {
	cout << "add_me(123, 677) = " << add_me(123, 677) << endl;
	cout << "add_me(13.1, 67.4) = " << add_me(13.1, 67.4) << endl;
	cout << "add_me(13.1, 67) = " << add_me(13.1, 67) << endl;
	cout << "add_me(\"123A\", \"677B\") = " << add_me("123A", "677B") << endl;
	cout << "add_me(\"12.3V\", \"67.7A\") = " << add_me("12.3V", "67.7A") << endl;
	cout << "add_me(123.2, \"677ABC\") = " << add_me(123.2, "677ABC") << endl;
	cout << "add_me(123.2, \"ABC\") = " << add_me(123.2, "ABC") << endl;
}