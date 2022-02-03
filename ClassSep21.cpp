/*
Spencer Mullen
Date: 9/21/2021
Notes for class.
*/

#include <iostream>
using namespace std;

/*
int main()
{
    // operators: >, <, >=, <=, ==, !=
    // 1 = true, 0 = false

    // conditional statements
    // tip: always add braces
    if (5 > 0) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    // ignores the if statement because of the semicolon
    if (2 > 3); {
        cout << "2 is greater than 3" << endl;
    } // else {
    // this else would throw an error beacuse it is not attached
    // to an if statement (since the above one got resolved).
    //}
    //cout << (5 > 0) << endl;

    // Logical operators
    // NOT (!), AND (&&), OR (||)
    cout << "Not of 0 is: " << !0 << endl;

    // This doesn't work in java
    // In C++, any number other than 0 is true
    if (50) {
        cout << "Success 50" << endl;
    } else {
        cout << "Failed 50" << endl;
    }
    // !!50 --> !(!50) --> !(0) --> 1
    
    // Bitwise operators
    // Bitwise AND (&), Bitwise OR/inclusive OR (|), Bitwise XOR/exclusive OR (^)
    // (56 && 40) --> true, (56 & 40) --> true
    // Bitwise operators compare the each of the two bits in the numbers with eachother
    
    // This returns 56 because it is just comparing 56 to 0xff (all 1s) using AND, returning itself
    cout << (56 & 0xff) << endl;

    // Comparing strings checks if their sizes are the same and if each member of
    // in location i in one string equals location i of the other string.
    string str1 = "Hello";
    string str2 = "ZZ";
    if (str1 > str2) {
        cout << "str1 Greater Than str2" << '\n';
    } else if (str1 < str2) {
        cout << "str1 Less Than str2" << '\n';
    } else {
        cout << "str1 Equals str2" << '\n';
    }

    // Ternary operators: condition ? true : false
    int val = 10;
    (val > 10) ? cout << "val > 10" << endl : cout << "val <= 10" << endl;

    // Switch statements
    // Without break statements, code "falls through" and continues running
    // Ex. vvv lowercase cases
    char grade = 'b';
    switch (grade) {
    case 'a':
    case 'A':
        cout << "Grade: A" << '\n';
        break;
    case 'b':
    case 'B':
        cout << "Grade: B" << '\n';
        break;
    case 'c':
    case 'C':
        cout << "Grade: C" << '\n';
        break;
    case 'd':
    case 'D':
        cout << "Grade: D" << '\n';
        break;
    default:
        cout << "Grade: F" << '\n';
        break; // break for the default is optional
    }

    // Increment/Decrement operators
    // int a = 100;
    // Prints 100 and then increments a because this is a post increment
    // cout << a++ << endl;
    // Increments a and then prints 101 because this is a pre increment
    // cout << ++a << endl;
    // Throws an error because post increment executes first, so compiler gets confused
    // cout << ++a++ << endl;
    // same with --

    // Loops
    // while (condition) { execute block }
    // do { execute block } while (condition);
    // for (statement1; statement2; statement3;) { execute block }

    // While loop checks condition and runs
    int i = 1;
    while (i < 10) {
        i++;
        cout << i << " ";
    }
    cout << '\n';

    // Do while loop runs once first then checks the condition
    int ii = 1;
    do {
        ii++;
        cout << ii << " ";
    } while (ii < 10);
    cout << '\n';

    // For loop defines int i, condition i < 10, and runs i every iteration.
    for (int i = 1; i < 10; i) {
        cout << ++i << " ";
    }
    cout << '\n';

    // This prints nothing and infinitely loops because i is always < 20.
    // This is due to the semicolon after the while loop.
    //int i = 1;
    // while (i < 10); {
    //     i++;
    //    cout << "i: " << i <<'\n';
    //}

    // These are infinite loops
    // while (1);
    // for (;;);
}
*/