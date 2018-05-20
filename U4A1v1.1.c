/* Matthew Miller - IT2240 - U04A1v1.1 - Part 1
 * 05/1/2018 Rev. 1
 */

// Simple Grade Book, Version 1.1

/* Modify the grade book code from Unit 3 so that it uses heap memory
to store percentage grades in the range from 0 to 100 (inclusive).
The program should allow the user to indicate when he or she is done entering
grades (since the user may not have grades to fill the whole array).
When the user is done entering grades, the program should print out the grades
entered by the user. Be sure to free the heap memory before the program ends.
*/


#include <stdio.h>
// Unit 4, Add std library because of Heap Memory Management.
// Needed for malloc(), sizeof(), free().
#include <stdlib.h>

int main(void)
{
    // Create Variables, all are self explanatory
    // modified variable array to pointer variable, to prepare for heap memory array.
    int *grade, count, i;

    // Console Header
    printf("\n\n\t\t\t   Simple Grade Book!\n\n\n");

    printf("\t\tMuch better then handwriting grades! :)\n\n");

    printf(" 1. The program stores percentage grades in the range from 0 to 100.\n"
           " 2. Next, you will be able to indicate when you are done entering grades.\n"
           " 3. Lastly, when you are done entering grades, they will be sent to your console.\n\n");


    printf("\tEnter your grades as integers 0 through 100.\n");
    printf("\tThe program will also determine the lowest and highest grade.\n\n");

    printf(" Let's Begin!\n\n");

    printf(" \tHow many grades do you have to enter: \n\t");
    scanf(" %d", &count);

    grade = malloc(count * sizeof(int));

    /* If allocation fails, address in grade is 0. Can't fix problem,
       so program needs to exit with error code 1. Error code is arbitrary.
    */
    if(grade == 0)
    {
        printf("\t\t!!Not enough memory!!");
        exit(1);
    }

    // Loop for user input
    for(i = 0; i < count; i++)
    {
        printf("\tEnter grade #%d: \n\t", i + 1);
        scanf("%d", &grade[i]);

        if(grade[i] < -1 || grade[i] > 100)
        {
            printf("\n\n Simple Grade book uses integers between 0 and 100 only!\n\n");
            // Release allocated memory using pointer name
            free(grade);
            exit(1);
        }
    }

    printf("\n The grades entered: \n\n");

    // Loop to print values entered.
    for(i = 0; i < count; i++)
    {
        // Use loop variable as index for array.
        printf("\t%d\n", grade[i]);
    }

    // Console statements to show the user the results.

    printf("\n You entered %d grade(s). \n\n", count);
    printf("\t\t\t !! See you soon !! \n\n");

    // Release allocated memory using pointer name.

    free(grade);

    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */

    return(0);
}

