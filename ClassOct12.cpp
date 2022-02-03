/*
Spencer Mullen
Date: 10/12/2021
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

using namespace std;
/*
int main() {
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };

	// we can loop using iterators
	// begin() returns the reference of an iterator pointing to the beginning of the vector
	// end() returns the reference of an iterator pointing to the end of the vector
	// iterators can be implemented as such
	for (auto iter = v1.begin(); iter != v1.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	// Built in array 
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	// Array class array
	array<int, 6> arr1 = { 1, 2, 3, 4, 5, 6 };

	// 3d array
	cout << "\n3d arrays\n";
	int matrix[5][4][3] = {};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 3; k++) {
				matrix[i][j][k] = i + j + k;
			}
		}
	}

	// Print contents using indexes
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 3; k++) {
				//cout << matrix[i][j][k] << " ";
			}
			//cout << endl;
		}
		//cout << endl;
	}

	// Print contents using pointers
	// This is a triple pointer and needs 3 dereferences
	int* p = &matrix[0][0][0];
	for (int i = 0; i < 5 * 4 * 3; i++) {
		if (i % 3 == 0 && i > 0) {
			//cout << '\n';
		}
		if (i % 12 == 0 && i > 0) {
			//cout << endl;
		}
		//cout << *(p + i) << " ";
	}
}*/