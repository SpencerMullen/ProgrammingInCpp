#include <iostream>
#include <string>
using namespace std;

/*
int main()
{
    // How to print a characters ASCII value and an integers character value?
    // Answer: Type Casting
    char myChar = 'A';
    //cout << myChar << endl;
    int myInt = 75;
    //cout << myInt << endl;

    cout << "Case " << static_cast<char>(myInt) << endl;
    cout << "Case " << static_cast<int>(myChar) << endl;

    // cin stops reading after a space or an enter.
    // entering "hello world howdy" with cin only takes the first two strings.
    // "howdy" is then send into the input stream and remains there.
    // to remove it, we need to use ignore or terminate the program.
    cout << "Please enter two strings:\t";
    string my_str_1, my_str_2, my_str_3;
    //cin >> my_str_1 >> my_str_2;
    cin >> my_str_1;
    // getline (string library) gets the entire line
    // Therefore, entering "Hello World Howdy Whatever" returns "Hello, " then the rest.
    getline(cin, my_str_2);
    cout << "Please enter another string:\t";
    cin >> my_str_3;
    cout << "Your strings are: " << my_str_1 << "," << my_str_2 << ", " << my_str_3;
    
    // Google cpp limit.h to find type limit values.
    // Note: if you are using a supercomputer your int may be larger and able to handle this.
    // Printing int a gives you -294967296 because of overflow.
    int a = 4000000000;
    // unsigned int forces the integer to be positive.
    // Printing unsigned int b gives you 705032704 because of overflow.
    unsigned int b = 5000000000;

    // Without 'using namespace std; we would need to do this vvv
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    int int1 = 0, int2(100), int3{ 200 };
    // Google c++ Operator Precedence
    // To find out what operations happen in what order
    // Google c++ math
    // To find out what is available in the math library
    cout << int1 << "," << int2 << "," << int3 << endl;
    string sa = "", sb("10000000"), sc{ "20000000" };
    cout << sa << "," << sb << "," << sc << endl;

    return EXIT_SUCCESS; //0 = success, EXIT_FAILURE
}
*/