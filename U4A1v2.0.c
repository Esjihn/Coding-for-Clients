/* Matthew Miller - IT2240 - U04A1v2.0 - Part 2
 * 05/1/2018 Rev. 1
 */

// Simple Grade Book, Version 2.0

/* Modify the grade book code from Unit 3 so that it uses 3 custom functions
to calculate the average grade (arithmetic mean, not letter grade), report
the highest grade, and find the lowest grade entered. This version of the
program does not need to use heap memory, though you are welcome to do so.
The program should allow the user to indicate when he or she is done entering
grades (since the user may not have grades to fill the whole array).
When the user is done entering grades, the program should print out the grades
entered by the user. The program should also display the average grade,
highest grade, and lowest grade.
*/


#include <stdio.h>
// Create modularized code. Cleaner looking and global variables can be modified easily.
// Here Max array size keeps the array only as large as we need, and -1 stops user input.
#define MAX_ARRAY_SIZE 100

/* Unit 4 EDIT, function declaration. Full definition below main(). Each function
   will take an array of integers (grades) & an integer (count of grade entries) as
   parameters & returns their values based on function name (i.e. lowestGrade does just
                                                            that).
*/

int highestGrade(int[], int);
int lowestGrade(int[], int);

int main(void)
{
    // Create Variables, all are self explanatory
    int grade[MAX_ARRAY_SIZE];
    int entryCount = 0;
    // Unit 4 EDIT: created variables that will be used for custom functions.
    int highest = 0;
    int lowest = 0;
    int averageGrade;

    // New Variables for Unit 4 V2.0
    float total = 0;
    char continueResponse;

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
    proceeds to the next code block.

    Unit 4 EDIT: Replaced -1 and stop code with the much cleaner and easier to use
    char continueResponse. continues with any character ends with 'n' or 'N'.

    */
    int i;

    for(i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        printf(" Enter grade: ");
        scanf("%d", &grade[i]);

        // Unit 4 EDIT. moved total out of the old 2nd for loop that was replaced
        // with the 2 custom functions. Variable is used later to solve for average.
        total += grade[i];

        if(grade[i] < -1 || grade[i] > 100)
        {
            printf(" Simple Grade book uses integers between 0 and 100 only!\n\n");
            break;
        }

        printf(" Continue? (y/n): \n\t");

        scanf(" %c", &continueResponse);

        entryCount++;

        if(continueResponse == 'n' || continueResponse == 'N')
        {
            printf(" == End of Data Entry ==\n\n");
            break;
        }

    }

    printf(" The grades entered: \n");

    // Console statements to show the user the results.

    /* Unit 4 V2.0 - added grade average which takes the total or sum of all grades
    entered and then divides the sum by the amount of entries I.E. if you wanted to
    find the average of say 1 2 3 you would add all of those numbers (total) and then
    divide them by how many numbers there are (1 2 3: 3 numbers) Therefore, average grade
    is the sum total of grades entered, divided by number of grades entered.
    */


    averageGrade = (total / entryCount);

    printf(" You entered %d grades. \n", entryCount);

    /* Unit 4 EDIT, call function to get lowest. Pass in array & count of
       entries as parameters. Array passed by name without the square brackets.
    */
    lowest = lowestGrade(grade, entryCount);
    printf(" The lowest grade entered is:  %d.\n", lowest);

    /* Unit 4 EDIT, call function to get highest. Pass in array & count of
       entries as parameters. Array passed by name without the square brackets.
    */

    highest = highestGrade(grade, entryCount);
    printf(" The highest grade entered is: %d.\n", highest);

    printf(" The average grade entered is: %d.\n\n", averageGrade);

    printf("\t\t\t !! See you soon !! \n\n");


    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */
    return(0);
}

int highestGrade(int gradeData[], int cnt)
{
    // initialize highest to 0
    int highest = 0;
    // loop variable
    int c;
    // go through array looking for highest
    for (c = 0; c < cnt; c++)
    {
        /* if item in gradeData is greater than highest,
           the replace highest with gradeData[c]
        */
        if(gradeData[c] > highest)
        {
            highest = gradeData[c];
        }
    }
    return highest;
}

int lowestGrade(int gradeData[], int cnt)
{
    // initialize lowest to 0
    int lowest = 0;
    // loop variable
    int c;
    // go through array looking for lowest
    for (c = 0; c < cnt; c++)
    {
        /* if item in gradeData is lower than lowest,
           the replace lowest with gradeData[c]
        */
        if(gradeData[c] < lowest || lowest == 0)
        {
            lowest = gradeData[c];
        }
    }
    return lowest;
}

