#include <iostream>
#include <cmath>

using namespace std;

int main(){

    //making an array that will hold all terms, distinct or not, given an 
    //arbitrarily large size
    int non_distinct_powers[1000];
    //We must find the integer combinations of a^b
    //where a_0 <= a <= a_1 and b_0 <= b <= b_1
    int a_1, b_1 = 5;

    //counter will be the index for the array
    int counter = 0;
    int power_term;

    for (int a_0; a_0 <= a_1; a_0++){
        for (int b_0 = 2; b_0 <= b_1; b_0++){
            power_term = pow(a_0, b_0);
            non_distinct_powers[counter] = power_term;
            counter++;
        }
    }

    cout << counter << endl;
    //now we have an array that holds nondistinct powers, which we must separate
    //into distinct terms
    for (int i = 0; i <= counter; i++){
        for (int j = 0; j <= counter; j++){
            if (j == i){
                continue;
            }
            else {
                if (non_distinct_powers[i] == non_distinct_powers[j]){
                    non_distinct_powers[j] = 0;
                }
            }
        }
    }
    //now the non_distinct_powers array has distinct terms as well as
    //formerly distinct terms equal to 0. Thus we must create an array that
    //does not include the 0s.

    int distinct_powers[counter + 1];
    int new_counter = 0;

    for (int k = 0; k <= counter; k++){
        if (non_distinct_powers[k] > 0){
            distinct_powers[new_counter] = non_distinct_powers[k];
            new_counter++; 
        }
    }

    cout << "The number of distinct terms in the sequence a^b is " 
         << new_counter + 1 << endl;



    return 0;
}