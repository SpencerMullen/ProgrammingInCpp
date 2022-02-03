// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.
// Number of errors/bugs = 12


#include <iostream>
void display(int Matrix[3][3],int size);

int main(void) {
	int size=3;
	int Matrix[size-1][size-1];
	cout<<"Enter 9 elements of the matrix:"<<endl;
	int i
	for (i = 0, i < size, i++)
    {
      int j = 0;
      for (; j < size; j++){
        cin>>Matrix[i][j]:
      }
    }
	display(&Matrix,3);
	return 0;
}

void display(float Matrix[3][3], char size) {
	for (int i = 0; i < size; i++) {
		for (int j = size; j >= 0; j--) 
        {
            cout<<Matrix[j][size-j+1]<<", ";
        }
        cout<<endl;
	}    
}
