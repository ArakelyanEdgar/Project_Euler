#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int day_of_the_weeks_num(string);
string day_of_the_weeks_string(int);
int next_year_day_of_the_week(int, int, int);


int main(){
	
	//the first dimension will hold the year and the second dimension holds the value for each month
	//e.g. year_with_months[0][1] refers to the first day of february in 1901
	string year_with_months[100][12];
	
	//now we must input the day of the week for each month in year_with_months[0][x] 
	//as knowing the year_with_months[i+1][x] is recursive.
	year_with_months[0][0] = "Tuesday";
	year_with_months[0][1] = "Friday";
	year_with_months[0][2] = "Friday";
	year_with_months[0][3] = "Monday";
	year_with_months[0][4] = "Wednesday";
	year_with_months[0][5] = "Saturday";
	year_with_months[0][6] = "Monday";
	year_with_months[0][7] = "Thursday";
	year_with_months[0][8] = "Sunday";
	year_with_months[0][9] = "Tuesday";
	year_with_months[0][10] = "Friday";
	year_with_months[0][11] = "Sunday";
	
	//now we must use our recursive function to determine the day of the week for year_with_months[i+1][x]
	int counter = 1;
	int day_num;
	for (int i = 1902; i < 2001; i++){
		for (int j = 0; j < 12; j++){
			day_num = day_of_the_weeks_num(year_with_months[counter - 1][j]);
			//we have a function that will convert a day_num to a day_str
			year_with_months[counter][j] = day_of_the_weeks_string(next_year_day_of_the_week(i, day_num, j));
		}
		counter++;
	}
	
	// now our year_with_months holds the days of the week for every 1st of the month of each year between
	//1901 and 2000 inclusive, thus now we must count the total sundays that have occured.
	
	int sum = 0;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 12; j++){
			if (year_with_months[i][j] == "Sunday"){
				sum++;
			}
		}
	}
	
	cout << "The total number of sundays from 1901 to 2000 is " << sum << endl;
	
	return 0;
}

// this function will return an int for each respective day of the week, e.g "Monday" == 0
int day_of_the_weeks_num(string day_of_the_week){
	
	int num;
	
	if (day_of_the_week == "Monday"){
		num = 0;
	}
	else if (day_of_the_week == "Tuesday"){
		num = 1;
	}
	else if (day_of_the_week == "Wednesday"){
		num = 2;
	}
	else if (day_of_the_week == "Thursday"){
		num = 3;
	}
	else if (day_of_the_week == "Friday"){
		num = 4;
	}
	else if (day_of_the_week == "Saturday"){
		num = 5;
	}
	else if (day_of_the_week == "Sunday"){
		num = 6;
	}
	
	return num;
	
}
// this function will convert a num for the day represnted by its string
string day_of_the_weeks_string(int day_of_the_week){
	
	string day;
	
	if (day_of_the_week == 0){
		day = "Monday";
	}
	else if (day_of_the_week == 1){
		day = "Tuesday";
	}
	else if (day_of_the_week == 2){
		day = "Wednesday";
	}
	else if (day_of_the_week == 3){
		day = "Thursday";
	}
	else if (day_of_the_week == 4){
		day = "Friday";
	}
	else if (day_of_the_week == 5){
		day = "Saturday";
	}
	else if (day_of_the_week == 6){
		day = "Sunday";
	}
	
	return day;
	
}
//this function will determines what day of the week it will be a year from now, while 
//accounting for leap years which occur every 4 years except for on centuries unless it is divisible 
//by 400, thus leap years are on 1904, 1960, 2000, etc.

int next_year_day_of_the_week(int year , int day_of_the_week, int month){
	
	int num = day_of_the_week;
	
	//we must check if the year before the current year was a leap year.
	
	// there are two conditions to check for
	// if it january or february then we must check if last year was a leap year
	// if it is a month after february then we must check if the current year is a leap year
	if (month < 2){
		if (((year - 1) % 100 == 0) && ((year - 1) % 400 == 0)){
			num += 2;
		}
		else if (((year - 1) % 100 == 0) && ((year - 1) % 400 != 0)){
			num++;
		}
		else if ((year - 1) % 4 == 0){
			num += 2;
		}
		else {
			num ++;
		}
	}
	else {
		if (((year) % 100 == 0) && ((year) % 400 == 0)){
			num += 2;
		}
		else if (((year) % 100 == 0) && ((year) % 400 != 0)){
			num++;
		}
		else if ((year) % 4 == 0){
			num += 2;
		}
		else {
			num ++;
		}
	}
	
	//this will allow us to use our day_of_the_weeks_num function to convert this to a string
	return num % 7;
	
}