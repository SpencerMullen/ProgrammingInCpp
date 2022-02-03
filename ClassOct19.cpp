/*
Spencer Mullen
Date: 10/19/2021
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

// Typically, you define structures outside of the main
struct Student {
	// this sets default values
	string name = "SSSS";
	char grade = 'N';
	// this is an array that is a member of a structure
	// int class_nums[40];

	// this is a member function (does the same thing as print_student)
	void print() const;

	// member function that passes Student o by reference that you can not change
	// the second const ensures that this method can not touch members of its structure
	bool equals(const Student& o) const;

	// If we want to use the == operator
	bool operator==(const Student& o) const;
};

// You can have structures as members of other structures
struct Course {
	string teacher;
	int year;
	Student std;
} cs3520, *cscs = &cs3520, fall2021[100]; // <-- cs3520 creates an instance of Course called cs3520
										  // <-- *cscs is a pointer to an instance of struct Course
										  //	 we set it to the address of cs3520
										  // <-- fall2021[100] is an array of type Course from 0 to 99

// Prints student (pass by value)
void print_student(Student s) {
	// void print_student(const Student& s) {
	// this header passes Student s by reference and makes s constant, you can not change it
	cout << s.name << ", " << s.grade << endl;
}

// We need to include to scope operator to specify that this belongs to student (Student::)
void Student::print() const {
	cout << name << ", " << grade << endl;
}

bool Student::equals(const Student& o) const {
	return name == o.name && grade == o.grade;
}

bool Student::operator==(const Student& o) const {
	return name == o.name && grade == o.grade;
}

int main() {
	// Structures
	// Older version of structures in between variables and class
	// Can store multiple variables, can't hold functions
	// New version of structures similar to java class
	// A Structure is not secure and cannot hide its implementation details from the end-user 
	// while a class is secure and can hide its programming and designing details. 
	// --> Structures always public (unsecure), classes private

	// Initialize values
	Student s1;
	s1.name = "Spencer";
	s1.grade = 'A';
	print_student(s1);

	// Another way to intialize values
	Student s2 = { "Bob", 'F' };
	// Print using the global function
	print_student(s2);

	Student s3 = s2;
	// Print using the member function
	s3.print();

	// Array of type student
	Student students[10] = {};
	students[0] = s1;
	students[3] = s2;
	students[5] = s3;

	for (auto s : students) {
		//cout << s.name << ", " << s.grade << endl;
	}

	// Using a field that is an array
	//students[0].class_nums[0] = 3000;
	//cout << "students[0].class_nums[0]: " << students[0].class_nums[0] << endl;

	// The size of structs
	string ss1 = "";
	cout << "Size of string: " << sizeof(ss1) << endl;
	cout << "Size of struct: " << sizeof(s1) << endl;
	cout << "Mem: " << &students[0] << ", " << &students[1] << endl;
	// Comparing the size of a string vs the size of a Student when Students only had
	// 2 members (name, grade) would expectedly return 40 vs 41 (string = 40 + char = 1)
	// However, the size of students is 48 because of a memory hole.
	// Basically, with a 32 bit compiler, the first 10 rows are allocated to the string (4 bytes each row
	// --> 40). The next row of 4 bits is given to the char, leaving a hole of 3 because the char only
	// takes up one spot. 
	// This leads to the == operator not working for structures.


	// A structure instance is passed to a function by value of its members
	// The value of each of its members is copied to the function
	// To pass a structure by reference, 
	Student& s4 = s3;
	// s4 and s3 are the same, s4 is a reference to s3
	
	// using s1 == s2 and cout << s1 give an error because the compiler doesn't know what to do
	// to get around this, we must write a function for the struct that does what we want
	//if (s1 == s2)
	//	cout << "equal" << endl;
	//else
	//	cout << "not equal" << endl;
	// cout << s1;
	// compare function --> equals(Student o)
	// print function --> print() or print_student(Student s)
	if (s1.equals(s2))
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
	if (s2.equals(s3))
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
	s1.print();

	// We can utilize the operator == instead by overloading the function using operator==.
	// Therefore, our previous code won't crash anymore.

	// The point of passing by reference if we don't want to change the values anyways
	// is saving memory. We don't make copies every time we call the function.
}