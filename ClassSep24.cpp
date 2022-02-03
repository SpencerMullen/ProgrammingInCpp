/*
Spencer Mullen
Date: 9/24/2021
Notes for class.
*/

#include <iostream>	
#include <string>
#include <bitset>

using namespace std;

/*
* Different bases
* Important numbers are B^x

Decimal --> Base = 10 : 0 through 9
	10^x = 1, 10, 100, 1,000,...
	739 = 7*10^2 + 3*10^1 + 9*10^0
Binary --> Base = 2 : 0, 1
	2^x = 1, 2, 4, 8, 16,...
	10110_2 = 1*2^4 + 0*2^3 + 1*2^2 + 1*2^1 + 0*2^0 = 22
	^MSB^LSB | MSB = most significant bit, LSB = least significant bit
Hexadecimal --> Base = 16 : 0 through 9, a through f
	16^x = 1, 16, 256, 4096
	2A_16 = 2*16^1 + 10*16^0 = 42
Octal --> Base = 8 : 0 through 7
	8^x - 1, 8, 64, 512
	451_8 = 4*8^2 + 5*8^1 + 1*8^0 = 297
*/

/*
Numbers base table
Dec		Bin		Hex		Oct
0		0000	0		0
1		0001	1		1
2		0010	2		2
3		0011	3		3
4		0100	4		4
5		0101	5		5
6		0110	6		6
7		0111	7		7
8		1000	8		10
9		1001	9		11
10		1010	a		12
11		1011	b		13
12		1100	c		14
13		1101	d		15
14		1110	e		16
15		1111	f		17
*/


/*
int main() {
	// what does this cout? 4 << 2
	// This shifts every bit left by 2
	// 4 in binary = 00000100_2 --> shift left
	// 00010000_2 = 16
	// Multiply by 2 twice

	// 4 >> 2
	// This shifts every bit right by 2
	// 0100_2 --> shift right --> 0001_2 = 1
	// Divide by 2 twice

	// 10110_2 * 10001_2 = 22 * 17 by long multiplication way inefficient
	// Instead, can break it down into 22 * 16 (2^4) + 22 * 1 (2^0)
	// 22 << 4 + 22 << 0 = 352 + 22 | happens in 2 clock cycles instead of more
	cout << 22 * 17 << " | " << (22 << 4) + (22 << 0) << endl;

	// ANDing used a lot in your computers to manipulate numbers
	// 0 and 0 = 0, 1 and 0 = 0, 0 and 1 = 0, 1 and 1 = 1

	// = is used for assignment, == is used for equality
	// a %= 8; --> a = a % 8;

	// cout << ('A' == 'a') << endl;
	// This prints 0/false because they are two different characters
	// Characters + strings are case sensitive
	// You can also convert everything toupper/tolower and compare
	cout << ('A' == toupper('a')) << endl;

	// The code enclosed between curly brackets is a block of code
	// Blocks of code have their own memory location
	int i = 1;
	while (i < 2) {
		// This variable can only be accessed in the while loop (local var)
		i++;
		int xyz = 123;
		// cout << "Inside" << xyz << endl;

		{
			// This is a different variable from the i defined outside the block
			// Which is why this prints 100 instead
			int i = 100;
			cout << "Inside Inside " << i << endl;
		}
	}
	cout << "Outside " << i << endl;


	// This returns an error because xyz is not defined outside the scope of the while loop
	// cout << "Outside" << xyz << endl;
	// If you make a variable outside of all blocks, that is a global variable (frowned upon)

	// The int x defined in the for loop parentheses is defined in the scope of the loop
	// for (int x = 0; x < 10; x += 2) {	}

	// You can change which base numbers are in, but you must convert back
	cout << "Hex: " << hex << 22 << endl;
	cout << "Oct: " << oct << 22 << endl;
	cout << "Dec: " << dec << 22 << endl;

	// Can do the same with cin
	int zyx;
	cout << "Enter a hexadecimal number: ";
	cin >> hex >> zyx;
	cout << "Your hexadecimal number in decimal: " << zyx << "\n";

	// Can use bitset to represent a binary num
	// Represent 22 using 8 bits
	bitset<8> b(22);
	cout << "Binary of 22 with 8 bits: " << b << endl;

	// Nested for loops runs the inner loop for every iteration of the outer loop.
}
*/