// Unit 2 Assignment 1 IT3348 May 14, 2018

/*Write a C++ console application that asks the user to enter
the hourly wage and number of hours worked for each week in a
4-week pay period. Create a custom function with appropriate
input parameters and return type that calculates the total gross
pay based on the values entered by the user. Use suitable loops
for the user input and the processing of data entered by the user.
The program should print out the gross pay for the pay period for
the employee.
*/


#include <iostream>
#define REGULAR_HOURS 40
#define OVERTIME_FACTOR 1.5

using namespace std;

float getGrossP(float hourlyWage, float hoursArray[]);
float getTimeP(float arr[]);

int main()
{
    float hourlyWage;
    float hoursInAWeek[4];

    cout << " Please enter your hourly wage: ";
    cin >> hourlyWage;

    for(int i = 0; i < 4; i++)
    {
        cout << " Please enter number of hours worked in week " << i + 1 << ": ";
        cin >> hoursInAWeek[i];
    }

    cout << " Your gross pay is: " << getGrossP(hourlyWage, hoursInAWeek) << endl;
    cout << " Total hours worked for 4 weeks: " << getTimeP(hoursInAWeek) << endl;

    return(0);
}

float getGrossP(float hourlyWage, float hoursArray[])
{
    float gP = 0;

    for (int i = 0; i < 4; i++)
    {
        gP += (hoursArray[i] - REGULAR_HOURS) * hourlyWage * OVERTIME_FACTOR + REGULAR_HOURS * hourlyWage;
    }
    return gP;
}

float getTimeP(float arr[])
{
    float tP = 0;

    for(int i = 0; i < 4; i++)
    {
        tP += arr[i];
    }
    return tP;
}

