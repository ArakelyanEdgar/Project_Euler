#include <iostream>
#include <cmath>

using namespace std;

int count_divisors(int);
int triangular_sum(int);


int main(){
	
	//counter for the while loop
	int counter = 1; 
	//hold the value of the current triangular_sum
	int triangular_sum_num;
	//number of factors
	int factors;
	
	//when true the loop will end
	bool sentinel = false;
	
	
	while (!(sentinel)){
		triangular_sum_num = triangular_sum(counter);
		factors = count_divisors(triangular_sum_num);
		
		if (factors > 500){
			cout << "The first triangular number to have over 500 divisors is " << triangular_sum_num;
			sentinel = true;
			break;
			
		}
		counter++;
	}
	

	
	
	return 0;
}

//count the number of divisors of a number.
int count_divisors(int k){
	
	int divisors = 0;
	
	if (k == 1){
		return 1;
	}
	else {
		for (int i = 2; i <= k/2; i++ ){
			if (k % i == 0){
				divisors++;
		}
	}
		//we count 1 and k as a divisor for every k, and the loop skips 1 and never reaches k.
		divisors += 2;
		return divisors;
	}
	
}

//this will count the triangular sums for the nth triangular sum, for example the 2nd triangular sum is
//1 + 2 = 3
int triangular_sum(int n){
	
	int k = 1;
	int triangular_sum = 0;
	
	while (k <= n){
		triangular_sum += k;
		k++;
	}
	
	return triangular_sum;
}