#ifndef MY_CODE
#define MY_CODE

#include<string>
#include<vector>

using namespace std;

// Determines if a class is full
bool classFull(int seats[20][7], char seat);

// Gets the seat number
int getSeatNum(string seat);

// Gets a seat given seatNum
string getSeat(int seatNum);

// Gets class given seatNum
string getLevel(int seatNum);

// Assigns a random seat
void assignSeat(char seat, int seats[20][7], vector<vector<string>> &names);

#endif