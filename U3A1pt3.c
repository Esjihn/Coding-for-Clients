/* Matthew Miller - IT2240 - U03A1 - Part 3
 * 04/23/2018 Rev. 1
 */

// Simple Grade Book

/*This program should use an array to store percentage grades
in the range from 0 to 100 (inclusive). The program should allow
the user to indicate when he or she is done entering grades.
When the user is done entering grades, the program should print
out the grades entered.
*/


#include <stdio.h>
// Create modularized code. Cleaner looking and global variables can be modified easily.
// Here Max array size keeps the array only as large as we need, and -1 stops user input.
#define MAX_ARRAY_SIZE 100
#define STOP_VALUE -1


int main(void)
{
    // Create Variables, all are self explanatory
    int grade[MAX_ARRAY_SIZE];
    int entryCount = 0;
    int highestGrade = 0;
    int lowestGrade = 0;

    // Console Header
    printf("\n\n\t\t\t   Simple Grade Book!\n\n\n");

    printf("\t\tMuch better then handwriting grades! :)\n\n");

    printf(" 1. The program stores percentage grades in the range from 0 to 100.\n"
           " 2. Next, you will be able to indicate when you are done entering grades.\n"
           " 3. Lastly, when you are done entering grades, they will be sent to your console.\n\n");


    printf("\tEnter your grades as integers 0 through 100.\n");
    printf("\tEnter a maximum of %d grades. \n", MAX_ARRAY_SIZE);
    printf("\tThe program will also determine the lowest and highest grade.\n\n");

    printf(" Let's Begin!\n\n");

    /* Here create the i variable, and put it in the for loop that will loop as long
    as the counter is less than the maximum array size. I put in 100 because that is
    the maximum amount of grades I have ever seen a professor use.

    I also added an if statement to halt the program if the user put in an integer
    less than the stop code (-1) and higher than the maximum grade int allowed (100).

    entryCount here also keeps track how many grades were entered and stored in the
    array.

    Lastly, -1 stops the loop, when the user is done entering in grades and then
    proceeds to the next code block
    */
    int i;

    for(i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        printf(" Enter grade (%d to quit): ", STOP_VALUE);
        scanf("%d", &grade[i]);
        if(grade[i] < -1 || grade[i] > 100)
        {
            printf(" Simple Grade book uses integers between 0 and 100 only!\n\n");
            printf(" Because I am a kind programmer I will still show your results.\n\n");
            break;
        }

        if(grade[i] == STOP_VALUE)
        {
            printf("\t\n Thank you for using the Simple Grade Book!\n\n");
            printf(" Calculating...");
            break;
        }

        entryCount++;

    }

    /* This code block runs a for loop based on the entryCount increment above.
    which then shows the user how many grades were entered.

    For a bonus I added the lowest and highest grade entered and stored into the
    array.

    */
    printf(" The grades entered: \n");

    for(i = 0; i < entryCount; i++)
    {
        printf("\t%d\n", grade[i]);

        if(grade[i] < lowestGrade || lowestGrade == 0)
        {
            lowestGrade = grade[i];
        }

        if(grade[i] > highestGrade || highestGrade == 0)
        {
            highestGrade = grade[i];
        }
    }

    // Console statements to show the user the results.

    printf(" You entered %d grades. \n", entryCount);
    printf(" The lowest grade entered is:  %d.\n", lowestGrade);
    printf(" The highest grade entered is: %d.\n\n", highestGrade);
    printf("\t\t\t !! See you soon !! \n\n");


    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */
    return(0);
}

