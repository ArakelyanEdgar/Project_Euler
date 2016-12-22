#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void inputting_array(ifstream& , int array[][20]);

int right_check(int array[][20], int, int);
int left_check(int array[][20], int i, int j);
int up_check(int array[][20], int i, int j);
int down_check(int array[][20], int i, int j);
int diagonal_up_right_check(int array[][20], int i, int j);
int diagonal_up_left_check(int array[][20], int i, int j);
int diagonal_down_right_check(int array[][20], int i, int j);
int diagonal_down_left_check(int array[][20], int i, int j);





int main(){

	//this array will hold the values of the file that holds the grid, making it easier to 
	//perform operations on the file's grid
	int array[20][20];
	//this will hold the value of the largest number
	int large_num = 0;
	ifstream infile;
	//receiving the input stream from the file, thus the grid.
	infile.open("problem_11.txt");
	//placing the grid into the array
	inputting_array(infile, array);
	
	//now we must determine what produces the largest number on the array.
	
	for (int x = 0; x < 20; x++){
		for (int y = 0; y < 20; y++){
			cout << array[x][y] << " "; 
		}
		cout << endl;
	}
	
	//these variables hold the value of the adjactent multiples in every direction.
	int right, left, up, down;
	int diagonal_up_right, diagonal_up_left, diagonal_down_left, diagonal_down_right;
	
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			//computing the multiple for each direction
			right = right_check(array, i, j);
			left = left_check(array, i, j);
			up = up_check(array, i, j);
			down = down_check(array, i, j);
			diagonal_up_left = diagonal_up_left_check(array, i, j);
			diagonal_up_right = diagonal_up_right_check(array, i, j);
			diagonal_down_left = diagonal_down_left_check(array, i, j);
			diagonal_down_right = diagonal_down_right_check(array, i, j);
			
			//now we must check if any of these values is greater than largest num
			
			if (right > large_num){
				large_num = right;
			}
			if (left > large_num){
				large_num = left;
			}
			if (up > large_num){
				large_num = up;
			}
			if (down > large_num){
				large_num = down;
			}
			if (diagonal_up_left > large_num){
				large_num = diagonal_up_left;
			}
			if (diagonal_up_right > large_num){
				large_num = diagonal_up_right;
			}
			if (diagonal_down_left > large_num){
				large_num = diagonal_down_left;
			}
			if (diagonal_down_right > large_num){
				large_num = diagonal_down_right;
			}
				
		}
	}

	cout << "The largest product of adjacent numbers is " << large_num << endl;
	
	return 0;
	
}

//a function to take from the infile and place the corresponding values into the array.
void inputting_array(ifstream& infile, int array[][20]){
	
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				infile >> array[i][j];
			}
		}
}


//functions that will return the multiple of each array's direction
//for each function we must check if there are at least 4 neighbors in that direction
int right_check(int array[][20], int i, int j){
	int right;
	
	if (( j == 17) || (j == 18) || (j == 19)){
		right = 0;
	}
	else {
		right = array[i][j]*array[i][j+1]*array[i][j+2]*array[i][j+3];
	}
	return right;
}
int left_check(int array[][20], int i, int j){
	int left;
	
	if (( j == 0) || (j == 1) || (j == 2)){
		left = 0;
	}
	else{
		left = array[i][j]*array[i][j-1]*array[i][j-2]*array[i][j-3];
	}
	return left;
}

int up_check(int array[][20], int i, int j){
	int up;
	
	if ((i == 0) || (i == 1) || (i == 2)){
		up = 0;
	}
	else {
		up = array[i][j]*array[i-1][j]*array[i-2][j]*array[i-3][j];
	}
	return up;
}

int down_check(int array[][20], int i, int j){
	int down;
	
	if ((i == 19)||(i == 18)||(i == 17)){
		down = 0;
	}
	else {
		down = array[i][j]*array[i+1][j]*array[i+2][j]*array[i+3][j];
	}
	return down;
}

int diagonal_up_right_check(int array[][20], int i, int j){
	int diagonal_up_right;
	
	if ((i == 0) || (i == 1) || (i == 2) || ( j == 17) || (j == 18) || (j == 19)){
		diagonal_up_right = 0;
	}
	else {
		diagonal_up_right = array[i][j]*array[i-1][j+1]*array[i-2][j+2]*array[i-3][j+3];
	}
	
	return diagonal_up_right;
	
}

int diagonal_up_left_check(int array[][20], int i, int j){
	int diagonal_up_left;
	
	if ((i == 0) || (i == 1) || (i == 2) || ( j == 0) || (j == 1) || (j == 2))
	{
		diagonal_up_left = 0;
	}
	else{
		diagonal_up_left = array[i][j]*array[i-1][j-1]*array[i-2][j-2]*array[i-3][j-3];
	}
	return diagonal_up_left;
}

int diagonal_down_right_check(int array[][20], int i, int j){
	int diagonal_down_right;
	
	if ((i == 19)||(i == 18)||(i == 17)|| ( j == 17) || (j == 18) || (j == 19)){
		diagonal_down_right = 0;
	}
	else {
		diagonal_down_right = array[i][j]*array[i+1][j+1]*array[i+2][j+2]*array[i+3][j+3];
	}
	return diagonal_down_right;
}

int diagonal_down_left_check(int array[][20], int i, int j){
	int diagonal_down_left;
	
	if ((i == 19)||(i == 18)||(i == 17)|| ( j == 0) || (j == 1) || (j == 2)){
		diagonal_down_left = 0;
	}
	else {
		diagonal_down_left = array[i][j]*array[i+1][j-1]*array[i+2][j-2]*array[i+3][j-3];
	}
	
	return diagonal_down_left;
}