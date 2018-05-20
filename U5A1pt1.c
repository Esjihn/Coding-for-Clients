/* Matthew Miller - IT2240 - U05A1 - Part 1
 * 05/06/2018 Rev. 1
 */

// Date Calculation

/*Write a program that asks the user for a date in the format mm/dd/yyyy,
use a custom struct to store the date information entered in memory. The
program should call a custom function that adds seven days to the user's
date, passing the data in and out of the custom function using the custom
struct for the dates. The program should then print out the original date
entered and the date one week later. As always, be sure to format your C
code correctly and include meaningful comments to explain what the code
does and how it works.
*/

#include "datecalc.h"
#include <stdio.h>


/*Unfortunately due to the way this program is setup with main() below, I have to
    declare the plusSeven function before it is implemented otherwise the
    program will still run but you get a warning flag. This removes said warning
    and the program runs flawlessly.
*/
struct datecalc plusSeven(struct datecalc plusSev);

struct datecalc plusSeven(struct datecalc plusSev)
{
    /*Our programs result needs 7 days after originalDate. This compound assignment
     operator will keep track of this.
    */
    plusSev.day += 7;

    /*From here things get tricky. Adding 7 days to a random day is simple right? wrong!
    We have to go through and group each month by the amount of days.

    Here we provide 2 sets of logic to take care of this.

    1) Month logic. Separate months into groups of code blocks based on the total number
    of days in the month. Reset (decrement) the day and increment the month if the day
    entered is already passed the number of days in that specific month
    (based on parameters)

    2) Overflow logic. The day entered is on the day that if incremented by 7
    will take us into the next month, then reset (decrement) the day and increment
    into the next month. This way we don't accidentally get a date over the max allowed
    in a month.
    */

    // Following are Months with 31 days.

    if ((plusSev.month == 1 || // January
         plusSev.month == 3 || // March
         plusSev.month == 5 || // May
         plusSev.month == 7 || // July
         plusSev.month == 8 || // August
         plusSev.month == 10|| // October
         plusSev.month == 12) && plusSev.day > 31) // 12 = December
        {
            // Reset the days and increment the month if 7 day counter goes over max days in month.
            plusSev.day -= 31;
            plusSev.month += 1;

            // Following are Months with 30 days.
        } else if ((plusSev.month == 4 || // April
                    plusSev.month == 6 || // June
                    plusSev.month == 9 || // September
                    plusSev.month == 11)  // November
                    && plusSev.day > 30)
        {
            plusSev.day -= 30;
            plusSev.month += 1;
            // Following Month is February (booo)
        } else
        {
            if(plusSev.year % 4 == 0 && plusSev.day > 29) // Every 4 years, 28 days (leap)
            {
                plusSev.day -= 29;
                plusSev.month += 1;
            } else if (plusSev.day > 28)
            {
                plusSev.day -= 28;
                plusSev.month += 1;
            }
        }
    if ((plusSev.day == 25) && plusSev.day > 31)
    {
        plusSev.day -= 31;
        plusSev.month += 1;
    } else if ((plusSev.day == 24) && plusSev.day > 30)
    {
        plusSev.day -= 30;
        plusSev.month += 1;
    } else
    {
        if (plusSev.year % 4 == 0 && plusSev.day > 29) // Every 4 years, 28 days (leap)
        {
            plusSev.day -= 29;
            plusSev.month += 1;
        } else if (plusSev.day > 28)
        {
            plusSev.day -= 28;
            plusSev.month += 1;
        }
    if (plusSev.month > 12) // Happy New Year!
    {
        plusSev.month = 1;
        plusSev.year += 1; // Increment the year
    }
    }
    return plusSev;
}

int main()
{
    struct datecalc originalDate, newDate;

    // Console Header
    printf("\n\n\t\t\t   Date Calculation Time!\n\n\n");

    printf("\t     Let's work with Structures in the C Language!! :)\n\n");

    printf(" 1. The program will ask the user for a date in the format mm/dd/yyyy.\n"
           " 2. Then it will use a custom struct to store the data. (date entered) \n"
           " 3. Lastly, it will call a custom function to calculate a proper date given\n"
           "    different day/month/year parameters and then print the original date\n"
           "    and a date one week later!\n\n");

    printf(" Shall we Begin!\n\n");

    printf("\tEnter date (mm/dd/yyyy or mm-dd-yyyy): \t");
    scanf("%d %*[/-] %d %*[/-] %d", &originalDate.month, &originalDate.day, & originalDate.year);

    newDate = plusSeven(originalDate);

    printf("\tYour original date is: %02d/%02d/%d.\n\n", originalDate.month, originalDate.day, originalDate.year);
    printf("\tSeven (7) days from date: %02d/%02d/%d.\n\n", newDate.month, newDate.day, newDate.year);

    printf("\t\t\t !! See you soon !! \n\n");

    return (0);

}
