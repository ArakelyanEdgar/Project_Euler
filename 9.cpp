#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	for (int a = 1; a <= 1000/3; a++){
		for (int b = a + 1; b <= 1000/2; b++){
			int c = 1000 - a - b;
			if ((a*a+b*b == c*c) && (a + b + c == 1000)){
				cout << "The answer is a = " << a << ", b = " << b << ", c = " << c << endl;
			}
		}
	}
	
	return 0;
}