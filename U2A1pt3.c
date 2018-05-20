/* Matthew Miller - IT2240 - U02A1 - Part 3
 * 04/16/2018 Rev. 1
 */

 // Cab Fare Calculator

 /* This program should calculate the fare for a cab ride based on the
 rates provided below. Ask user to input distance (measured to 1/10 of mile),
 number of passengers, and if going to/coming from the airport. Calculate fare
 for trip using these rates:

    1. Minimum fare: $5.00 (fares less than this rounded up to $5.00).
    2. $1.80 per mile (charged by 1/10 of mile. 2.1 miles = $3.78).
    3. 1st additional passenger, if more than 1 rider: $1.00.
    4. Each additional passenger (after 1st additional passenger): $0.50.
    5. Airport surcharge: $2.00.
*/

#include <stdio.h>
// Create modularized code. Cleaner looking and global variables can be modified easily.

#define MINIMUM_FARE 5.00
#define CAB_RATE 1.80
#define TWOORMORE_SURCHARGE .50
#define AIRPORT_SURCHARGE 2.00


int main(void)
{
    // Create Variables
    char airportVerify;
    int passengers;
    float surCharge, riderDistance;
    float totalCharge = 0;

    // Console Header
    printf("\n\n\t\t\tCab Fare Calculator!\n\n\n");

    printf("\tDetails of your fare calculation are listed below\n\n");

    printf("1. Minimum fare: $5.00 (fares less than this rounded up to $5.00).\n"
    "2. $1.80 per mile (charged by 1/10 of mile. 2.1 miles = $3.78).\n"
    "3. 1st additional passenger, if more than 1 rider: $1.00.\n"
    "4. Each additional passenger (after 1st additional passenger): $0.50.\n"
    "5. Airport surcharge: $2.00.\n\n");

    /* Commented out debug statements help test code throughout the program.
    This way you ensure a higher probability of your code being completed more
    efficiently and with as little errors as possible.*/

    //printf("\tFirst please enter distance in miles per 1/10 mile: \n\t");
    //scanf(" %f", &riderDistance);
    //printf("\tthe user entered %.1f as an input!\n\n", riderDistance);

    // Let the User know that its time to give C input!

    printf("\tFirst, please enter distance in miles per 1/10 mile: \n\t");
    scanf(" %f", &riderDistance);

    // Also make sure the user knows information entered has been stored.
    printf("\t%.1f, 1/10 rounded rider distance stored. Thank you.\n\n", riderDistance);

    printf("\tSecond, how many passengers? (pets and small children are \n\tconsidered "
           "passengers): ");
    scanf(" %d", &passengers);
    printf("\t%d passenger(s) stored!\n\n", passengers);

    printf("\tLastly, will you be going to the airport? (Y/N): ");
    scanf(" %c", &airportVerify);
    printf("\t%c, stored!\n\n", airportVerify);

    // Humanistic code that buys the program the users time in case of a slower machine.
    printf("Calculating...\n\n");

    // Cab Fare Calculator Logic

    /* If else statements are needed to check for all user input possibilities i.e
    what if a rider is going to the airport alone, or if a rider isn't going to the
    airport but is also riding with multiple passengers, or if rider is alone and
    isn't traveling very far.*/
    if (airportVerify == 'Y' || airportVerify == 'y')
    {
        if (passengers > 1)
        {
        printf("Airport Surcharge applies...\n");
        surCharge = passengers * TWOORMORE_SURCHARGE;
        totalCharge = (riderDistance * CAB_RATE) + surCharge + AIRPORT_SURCHARGE;
        }
    } else if ((airportVerify == 'N' || airportVerify == 'n') && (passengers > 1))
    {
        surCharge = passengers * TWOORMORE_SURCHARGE;
        totalCharge = (riderDistance * CAB_RATE) + surCharge;
    } else
        totalCharge = riderDistance * CAB_RATE;

    if (totalCharge < MINIMUM_FARE)
    {
        printf("Minimum Fare Applied!\n\n");
        totalCharge = MINIMUM_FARE;
    }

    printf("The total charge: $%.2f.\n\n", totalCharge);

    printf("Thank you for using Cab Fare Services! :)\n\n");

    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */

    return(0);
}
