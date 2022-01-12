//
// Name: Janto, Kennedy
// Project: #2
// Due: September 27, 2021
// Course: cs-2560-01-sp21
//
// Description:
// User types in the month and year and the output will generate a text file that represents the calendar of that specific month and year
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <array>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    cout << "Calendar by K. Janto\n" << endl; //program title

    string monthString; //creates string version of month
    string yearString; //creates string version of year
    int month; //creates int version of month   
    int year; //creates int version of year

    //creates an empty array of days in a month that will be updated later
    array<int,42> days = {0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0};
    cout << "Enter month year?";
    cin >> monthString >> yearString; //takes in the month and year in string form

    //converting string version of month and year to int version
    stringstream num1(monthString);
    num1 >> month;
    stringstream num2(yearString);
    num2 >> year;

    //calculates what the first day in the month is using gregorian calendar equation
    int a = (14-month)/12;
    int y = year - a;
    int m = month + (12*a) - 2;
    int firstDay = (1 + y + (y/4) - (y/100) + (y/400) + (31*m/12)) % 7;

    int position = firstDay; //current position of the array
    int numOfDays; //number of days in a month

    //calculates number of days for each month
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){  
        numOfDays = 31; //january, march, may, july, august, object, december all have 31 days
    }
    if(month == 2){ //february
        if((year%4 == 0) && (year%100 != 0) || (year%400 == 0) ){
            numOfDays = 29; //leap year
        }
        else{
            numOfDays = 28; //not leap year
        }
    }
    if(month == 4 || month == 6 || month == 9 || month == 11){
        numOfDays = 30; //april, june, september, november all have 30 days
    }

    //creation of output file for calendar
    ofstream outfile;
    string filename = monthString + "-" + yearString + ".txt";
    outfile.open(filename);
    cout <<"\n"<< filename << " generated.";

    //prints name of month and year above the calendar
    if(month == 1){
        outfile<< "January ";
    }
    if(month == 2){
        outfile<< "February ";
    }
    if(month == 3){
        outfile<< "March ";
    }
    if(month == 4){
        outfile<< "April ";
    }
    if(month == 5){
        outfile<< "May ";
    }
    if(month == 6){
        outfile<< "June ";
    }
    if(month == 7){
        outfile<< "July ";
    }
    if(month == 8){
        outfile<< "August ";
    }
    if(month == 9){
        outfile<< "Septemper ";
    }
    if(month == 10){
        outfile<< "October ";
    }
    if(month == 11){
        outfile<< "November ";
    }
    if(month == 12){
        outfile<< "December ";
    }
    outfile << yearString << endl;

    //updates the array of days
    for(int i = 1; i <= numOfDays; i++){
            days[position] = i;
            position++;
        }

    //prints out the calendar in correct format to the output file
    outfile << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    outfile << "---------------------------------\n";
    
    for(int z = 0; z <= days.size(); z++){
        if((z == 0 || z == 7 || z == 14 || z == 21 || z == 28 || z == 35) && (z >= 7)){
            outfile << "\n";
            if(days[z]==0){
                outfile << "   ";
            }
            else{
                outfile << setw(3) << days[z];
            }
        }
        else if((z == 0 || z == 7 || z == 14 || z == 21 || z == 28 || z == 35)){
            if(days[z]==0){
                outfile << "   ";
            }
            else{
                outfile << setw(3) << days[z];
            }
        }
        else{
            if(days[z]==0){
                outfile << "     ";
            }
            else{
                outfile << setw(5) << days[z];
            }
        }
        if(z > 25 && days[z]==0){
            outfile << "\n";
            break;
        }
    }
}
