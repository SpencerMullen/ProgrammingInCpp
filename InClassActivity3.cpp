/*
Spencer Mullen
Date: 9/24/2021
In class activity 3.
Partner: Ethan
*/

#include <iostream>	

using namespace std;

int main() {
	int quit;

	while (quit != 1 && quit != 2) {
		cout << "Choose an option: (1) Perform calculations, (2) Quit: ";
		cin >> quit;
		cout << endl;
	}

	while (quit == 1) {
		int format;
		cout << "Choose a number format: (1) Decimal, (2) Hexadecimal, (3) Octal: ";
		cin >> format;
		
		switch (format) {
		case 1: cout << dec;
			break;
		case 2: cout << hex;
			break;
		case 3: cout << oct;
			break;
		default:
			cout << dec << "Defaulted to decimal.";
			break;
		}

		int num1;
		char operation;
		int num2;
		
		cout << "Enter a number, an operation, and another number.";
		cin >> num1 >> operation >> num2;

		switch (operation) {
		case '+': cout << num1 + num2;
			break;
		case '-': cout << num1 - num2;
			break;
		case '*': cout << num1 * num2;
			break;
		case '/': cout << num1 / num2;
			break;
		case '%': cout << num1 % num2;
			break;
		case '&': cout << num1 && num2;
			break;
		case '|': cout << num1 || num2;
			break;
		case '!': cout << (num1 != num2);
			break;
		case '^': cout << (num1 ^ num2);
			break;
		case '<': cout << (num1 << num2);
			break;
		case '>': cout << (num1 >> num2);
			break;



		}

			
	}
}