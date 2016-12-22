#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	//a must be a natural number therefore it must start at 1.
	//furthermore a < b < c and a + b + c = 1000 therefore a must be between 1 and 333.
	for (int a = 1; a < 1000/3; a++){
		//because a < b < c, therefore b must be between a + 1 and c and in no case can b be greater
		//than 500 because that would imply that c is greater than 500.
		for (int b = a + 1; b < 1000/2; b++){
			//a + b + c = 1000 <=> c = 1000 - a - b 
			int c = 1000 - a - b;
			//here we are not using pow() because it casts the identifier to floating values and
			//thus it may find some equality issues.
			if ((a*a+b*b == c*c) && (a + b + c == 1000)){
				cout << "The answer is a = " << a << ", b = " << b << ", c = " << c << endl;
			}
		}
	}
	
	return 0;
}