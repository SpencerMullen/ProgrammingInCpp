/*
Spencer Mullen
Date: 10/3/2021
This file represents my work done for question 2, parts a through c.
*/

/*
a) The twos complement representation of -17 in 8 bits can be calculated as follows:

17 in binary --> 00010001
Flip the bits -> 11101110
Add 1 to this -> 11101111

b) Converting the hexadecimal number 5A1 to binary, octal, and decimal can be calulated
as follows:

Hexadecimal: 5A1

To convert to binary, we can represent each number in their own set of 4 bits
5 --> 0101, A --> 1010, 1 --> 0001
Connect these numbers and that is our binary representation
Binary: 010110100001

To convert to decimal, we use the following calculation
5 * (16^2) + 10 * (16^1) + 1 * (16^0) = 1441
Decimal: 1441

To convert to octal, we take our decimal reprsentation and use the following calculation
1441 / 8 = 180 Remainder 1
180 / 8 = 22 Remainder 4
22 / 8 = 2 Remainder 6
2 / 8 = 0 Remainder 2
Then, we take the remainders and connect them giving us
Octal: 2641

c) Computing the sum of the two numbers in hex, binary, octal, and decimal format can be done as follows:

Calculation: 1F0A_16 + 10050_10

Hexadecimal: 1F0A already in form
10050 = 2 * (16^3) + 4 * (16^2) + 7 * (16^1) + 2 * (16^0)
10050_10 = 2472_16
1F0A + 2472 = (4)(3 Carry 1)(7)(C) = 437C

Decimal: 10050 already in form
1F0A = 1 * (16^3) + 15 * (16^2) + 0 * (16^1) + 10 * (16^0)
1F0A_16 = 7946_10
10050 + 7946 = 17996

Binary: Convert both to binary
1F0A --> split up digits and connect afterwards
1 = 0001, F = 1111, 0 = 0000, A = 1010
1F0A_16 = 0001111100001010_2

10050 = 1 * (2^13) + 0 * (2^12) + 0 * (2^11) + 1 * (2^10) + 1 * (2^9) + 1 * (2^8) + 
0 * (2^7) + 1 * (2^6) + 0 * (2^5) + 0 * (2^4) + 0 * (2^3) + 0 * (2^2) + 1 * (2^1) + 0 * (2^0)
= 10011101000010_2

Line up and add:
 0001111100001010
+0010011101000010

Binary sum = 100011001001100

Octal: Convert both to octal

10500 = 2 * (8^4) + 4 * (8^3) + 4 * (8^2) + 0 * (8^1) + 4 * (8^0)
= 24404
1F0A = 7946 = 17412

Octal = 24404 + 17412 = 41816
*/