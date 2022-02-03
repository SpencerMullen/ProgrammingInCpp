// Program to read 3-dimensional matrix and display the elements as 1x27 matrix
// TODO
// User may specify any number of rows, columns and depth. Use those to create matrix
// initize matrix using update_ed method
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops
// 

#include <iostream>
#define SIZE 3

// include namespace std
using namespace std;

void update_3d(double Matrix_3d[][SIZE][SIZE],int size); 
void display_1d(double Matrix_3d[][SIZE][SIZE],int size); 

int main(void) {
	//prompt the use to enter appropriate dimensions and initializ the matrix accordingly
	double Matrix_3d[SIZE][SIZE][SIZE] = {};
	//initialize the array to non-zero values (use scanf or random numbers generator)
	update_3d(Matrix_3d, SIZE);
	//display the values
	display_1d(Matrix_3d, SIZE);
	return 0;
}

// fixed parameters
void update_3d(double Matrix_3d[][SIZE][SIZE], int size) {
	cout<<"Enter 27 elements of the matrix:"<<endl;
	int i=0;
	for (; i < SIZE; i++)
    {
      int j = 0;
      for (; j < SIZE; j++)
	  {
	      int k = 0;
	      for (; k < SIZE; k++)
		  {
			// fixed cin statement
			  cin >> Matrix_3d[i][j][k];
	      }
      }
    }
}

//update as needed. 1 'for' loop only with 1 iterator to print all values with addresses
//must not be able to update the array.
//Share any observations.

// Fixed parameters
void display_1d(double Matrix_3d[][SIZE][SIZE], int size) {
	
	int i;
	size *= size * size;
	// Updated for loop
	for (i= 0; i < size; i++) {
		// fixed cout statement
       	cout<< Matrix_3d[i / 9][i / 3 % 3][i % 3];
		if (i != size - 1)
			cout << ", ";
    }
}