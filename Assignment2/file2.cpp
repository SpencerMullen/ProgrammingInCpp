// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 617, exchange = 424
Output : 
"I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

/*
List of changes:
    - Added 'using namespace std;'
    - Added quote to second cout
    - Changed arrow direction for cin
    - Added semicolon for third cout
    - Fixed logic of for loop
    - Deleted extra bracket
    - Deleted extra paren
    - Changed , to <<
    - Deleted digits, and made it so digits are implemented into the for loop
    - Return exit success
    - Moved 'cout << "I am calling to tell you to buy a subscription to Dogs Monthly!\n";'
*/

#include<iostream>

using namespace std;

int main() {
    int areaCode, exchange;
    std::cout << "Hello, I am a telemarketing calling making program.\n";
    std::cout << "Enter a three - digit area code ";
    cin >> exchange;
    std::cout << "Enter a three-digit exchange to call ";
    std::cin >> areaCode;
    cout << "I am calling to tell you to buy a subscription to Dogs Monthly!\n";
    for(int i = 0; i < 10000; i++) {
        cout << areaCode << "-" << exchange << "-";
        cout << i << endl;
        
    }

    std::cout << "\nCalls completed" << endl;
    return EXIT_SUCCESS;
}