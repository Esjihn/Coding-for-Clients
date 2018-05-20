/* Matthew Miller - IT2240 - U02A1 - Part 2
 * 04/13/2018 Rev. 1
 */

// Pay Calculator

/* Write a program that requests the user to enter hours worked in a week and the
hourly wage. The program should then print the gross pay, the taxes, and the next pay.
Assume the following:

    1. Overtime (in excess of 40 hours for week) = time and a half
    2. Tax rate: 15% of the first $600, 20% of the rest
*/

#include <stdio.h>
// Create modularized code. Cleaner looking and global variables can be modified easily.
#define REGULAR_HOURS 40
#define TAX_RATE15 0.15
#define TAX_RATE20 0.20
#define TAX_THRESHOLD 600
#define OVERTIME_FACTOR 1.5


int main(void)
{
    // Create variables
    double hoursWorked, payRate;

    // Console Header
    printf("\n\n\t\t\tPay Calculator Program!\n\n");
    printf("This program calculates gross pay, tax rate, net pay, and overtime.\n");
    // Don't forget the second Modulus for percentage string statements
    printf("Your tax rate is 15%% of the first $600, 20%% of the rest.\n");
    printf("Overtime is paid time and a half for any time worked over 40 hours.\n\n");

    /* Commented out debug statements help test code throughout the program.
    This way you ensure a higher probability of your code being completed more
    efficiently and with as little errors as possible.*/
    //printf("\tFirst please enter your hours worked: \n\t");
    //scanf(" %lf", &hoursWorked);
    //printf("\tthe user entered %.2lf as an input!\n\n", hoursWorked);

    // Let the User know that its time to give C input!

    // Collecting User input and storing in variables.

    printf("\tFirst please enter your hours worked (X.XX or XX.XX format): \n\t");
    scanf(" %lf", &hoursWorked);

    // Also make sure the user knows information entered has been stored.
    printf("\t%.2lf hours worked stored. Thank you.\n\n", hoursWorked);

    printf("\tSecond please enter your hourly wage (X.XX or XX.XX format): \n\t");
    scanf(" %lf", &payRate);
    printf("\t%.2lf hourly wage stored. Thank you.\n\n", payRate);

    // Humanistic code that buys the program the users time in case of a slower machine.
    printf("Calculating...\n\n");

    // Pay Calculator logic
    double grossPay = (hoursWorked - REGULAR_HOURS) * payRate * OVERTIME_FACTOR + REGULAR_HOURS *
                        payRate;
    double taxPaid = 0.00;

    if (grossPay > TAX_THRESHOLD)
    {
        taxPaid = (grossPay - TAX_THRESHOLD) * TAX_RATE20 + TAX_THRESHOLD * TAX_RATE15;
    }
    else
        taxPaid = grossPay * TAX_RATE15;

    double netPay = grossPay - taxPaid;

    // Display results to user at console.
    printf("Your Gross Pay: %.2lf\n", grossPay); // Gross Pay Holder
    printf("Taxes paid: %.2lf\n", taxPaid); // Tax Holder
    printf("Your Net Pay: %.2lf\n\n", netPay); // Net Pay Holder

    printf("Thank you for your time! :)\n\n");

    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */

    return(0);
}
