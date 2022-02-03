// Program to check if the given number is a palindrome
// Number of errors/bugs = 15

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.
/*
#include<iostream>

// use namespace std
using namespace std;

// return type changed to bool, parameter changed to int
bool func(int x);

// main should return int
int main() {
        // change variable name
        // return type changed to int
        int palindrome = 1001;        

        // renamed func4 to func
        // initialized return_value_function
        // passed in palindrome instead of return_value_function
        bool return_value_function = func(palindrome);
        // fixed return values
        if (!return_value_function){
                cout<<"It is not a palindrome"<<endl;
        }
        else{
                cout<<"It is a palindrome"<<endl;
        }
		// no semicolon
        return 0;
}
// removed random number

//the return value of your func should be true / false only
// changed return type to bool
// removed char w parameter
bool func(int n)
{             
    // declared given number to be n
    int given_number = n;
    int remainder;
    // initialize temp
    int temp = 0;
    // fixed while loop by changing = to >
    while (n > 0) {
        // fixed remainder value using modulus
		remainder = n % 10;
        // changed -= to /=
		n /= 10;
        // changed + to *
        temp = temp * 10 + remainder;
    }

    // fixed returns
    if (given_number == temp)
    {
            return true;
    }
    else
    {
            return false;
        }
}

*/