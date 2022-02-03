/*  This program should determine if a number is a prime or composite number 
    The program should ask user for a number 'num'
    If 'num' is 0 or 1, print "num is not prime or composite"
    For any value > 1, print "num is a prime number" or "num is a composite number" depending on the number */

// Check for possible logical errors and rectify them 

/*
List of changes:
    - Added 'using namespace std;'
    - Changed iosteam --> iostream
    - Removed void
    - Changed False --> false
    - Removed ':' in while loop and used brackets
    - Added semicolon for cout statement
    - Changed && to ||
    - Fixed logic for for loop
    - Fixed logic for if statements
    - Corrected if statement inside for loop
    - Corrected logic and syntax for final if statements and prints
*/

#include<iostream>

using namespace std;

int main(){
    int num, i;
    bool factor_found = false;
    cout<<"Enter Number:\n";
    cin>>num;
    if (num == 0 || num == 1) {
        cout << num << " is not prime or composite";
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            factor_found = true;
            break;
        }
    }
    if (factor_found)
        cout << "is a composite number\n";
    else
        cout << "is a prime number\n";
}