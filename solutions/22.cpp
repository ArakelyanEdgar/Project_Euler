#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

int main(){

    ifstream infile;
    string input;
    regex integer("(\w+)");

    infile.open("data.txt");

    infile >> input;

    while (infile){
        if (regex_match(input, integer)){
            cout << input << endl;
        }
        infile >> input;
    }
    
    return 0;
}