/*
Airline Reservations System Pseudocode

The program will prompt the user for an option. Depending on the response from the user,
we will execute a different command.

Names represented using a 2d Vector.

Seats represented using a 2d Array.
20 rows (outer arrays), 7 seats each (inner arrays).
	Seat columns labeled A, B, D, E, F, H, I
	Aisle columns labeled C, G
	Rows labeled 1-20
		First class rows labeled 1-3
		Business class rows labeled 4-7
		Economy class rows labeled 8-20

Seat numbers would be the number of the seat (A1 = 0, A2 = 7, A3 = 14, etc)

Function to check whether a class is full
	Given a specific class type, goes through the possible values of that class and determines if the class is full

Function to get seat number
	Returns an integer of the array value of the seat
Function to get seat
	Returns a string of the letter and number of the seat
Function to get level
	Returns a string of the class of the given seat

Function to assign a seat
	Generates a random seat using random number generator
	Checks if that seat in the class is taken
	If it's not taken, prompt the user for an upgrade/downgrade
	After upgrading/downgrading, ask for the name
	Enter the name into the vector for names
	Modify seats variables to represent change
	 

If the user enters:
	1 - read line by line the text file labeled system.txt
		set the seats and passenger values given the first set of values
		set the manifest given the set of strings

	2 - write line by line to text file labeled system.txt
		write the seat assignment and passenger names first
		write the manifest second

	3 - call on assign a seat function given a class

	4 - cancels a seat given the seat
		removes the entry from the seats and names

	5 - prints a boarding pass for the passenger at that seat
		if there is none, print that seat is empty

	6 - display the seating map going through the array of seats
		and indicating whether or not a seat is empty or full

	7 - prints the passenger manifest using the names vector and
		seats array
		if the user wants it in alphabetical order, sort the manifest
		vector

	8 - quit and exit the program.
*/