/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

/*
List of changes:
    - Added 'using namespace std;' to be able to use things from the standard namespace
    - Set int limit to 10 instead of 0 and set the products to 1 instead of 0
    - Fixed logic for the first for loop
    - Fixed logic with the if statement, using modulus instead
    - Used *= instead of +=/= for the products
    - For the first for loop"
        - Changed 'i = 0' to 'int i = 0'
        - Changed colons into semicolons
        - Added an additional equals sign for 'i / 2 == 0'
        - Removed asterisk in 'if(i ** 2 == 1)'
    - Relocated the '\n' in the cout statement
    - Changed 'i' to 'c'
    - Added a parentheses to '("%d", sum)'
    - Corrected the logic for the second for loop
 */

#include <iostream>

using namespace std;


int main(){
    int limit = 10, even_product = 1, odd_product = 1, sum;
    char c;
    cout<<"The value of limit is "<< limit<<endl;
    for (int i = 1; i <= limit; ++i) {
       if(i % 2 == 0){
           even_product *= i;
       } else {
           odd_product *= i;
       }
        sum = even_product + odd_product;
    }
    cout<<"The Sum = "<< ("%d", sum) << '\n';
    for(c = 'Z'; c >= 'A'; c -= 2){
    	cout<<" "<< c;
    }
    
    return 0;
}

