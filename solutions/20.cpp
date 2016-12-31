#include <iostream>
#include <cmath>


using namespace std;

int main(){
	int factorial = 1;
	//in order for this factorial to work we need to use a big integer library
	for (int i = 1; i <= 100; i++){
		factorial *= i;
	}
	
	int sum = 0;
	
	//now we must sum the digits of 100!
	
	// this loop will find the value of the least significant digit, add it to sum, and then remove the 
	//least significant digit as factorial is an int
	while (factorial != 0){
		sum = sum + (factorial % 10);
		factorial = factorial/10;
	}
	
	cout << "The sum of the digits in 100! is " << sum << endl;
	
	
	return 0;
}