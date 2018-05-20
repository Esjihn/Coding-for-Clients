/* Matthew Miller - IT2240 - U05A1 - Part 2
 * 05/06/2018 Rev. 1
 */

// Simple Grade Book, Version 3.0

/*Modify the grade book program from Unit 3 to use a custom struct to
hold the student's ID number and the percentage score for each item in
the grade book. The program should accept the entry of ID numbers and
percentage grades (0-100) until the user signals that he or she is done
entering grades. The program should then print out the ID numbers and
grades entered by the user, sorted by ID number. Again, be sure to format
the code properly and provide comments in the C code.
*/

/*Unit 5 Header includes structure information. User can simply edit the
header without risk of altering program code.
*/
#include "student.h"
#include <stdio.h>
#include <stdlib.h>

// Create modularized code. Cleaner looking and global variables can be modified easily.
// Here Max array size keeps the array only as large as we need.
#define MAX_COUNT 100

// Unit 5, declaration of sort function
void sort(struct person *, int);

int main(void)
{
    // Create Variables
    // Unit 5, pointer to heap memory allocated.
    struct person *id;
    // Unit 5, struct variable to hold data before adding to heap.
    struct person studentID;
    // Unit 5, variable to count entries.
    int entryCount = 0;
    // Unit 5, variable for Y/N response from user. Replaces -1 from U03A1.
    char response;
    // Unit 5, loop counter variable.
    int i;

    // Console Header
    printf("\n\n\t\t\t   Simple Grade Book!\n\n\n");

    printf("\t\tMuch better then handwriting grades! :)\n\n");

    printf(" 1. The program stores percentage grades in the range from 0 to 100.\n"
           " 2. First, you will be able to enter student name/ID and their grade.\n"
           " 3. Next, keep entering student IDs and grades when finished follow prompt.\n"
           " 4. Lastly, when you are done entering grades, they will be sent to your console.\n\n");


    printf("\tEnter your grades as integers 0 through 100.\n");
    printf("\tEnter a maximum of %d grades. \n", MAX_COUNT);
    printf("\tThe program will also determine the lowest and highest grade.\n\n");

    printf(" Let's Begin!\n\n");

    /* Unit 5, Allocate heap memory for data. sizeof()
       calculates size of a person struct
    */

    id = malloc(MAX_COUNT * sizeof(struct person));
    // Unit 5, If error allocating memory, exit with error code 1
    if (id == 0)
    {
        exit(1);
    }

    // Unit 5, Input loop limited to size of allocated space
    for(i = 0; i < MAX_COUNT; i++)
    {
        printf(" Enter Student's Grade (0-100): ");
        // Unit 5, student member of struct is an array, no Ampersand isn't needed.
        scanf("%s", studentID.studentGrade);

        printf(" Enter Student Name or ID: ");
        // Unit 5, studentGrade member of struct is an int, so Ampersand IS needed.
        scanf("%d", &studentID.student);
        entryCount++;

        // Unit 5, save studentID to heap using array
        id[i] = studentID;

        /* Unit 5, modified 0 through 100 inclusive if statement. Frees memory heap
        allocation and exits.
        */


        printf(" Continue? (Y/N): ");
        scanf(" %c", &response);

        if(response == 'N' || response == 'n')
        {
            printf("\n\t\t!! End Data Entry !!\n");
            break;
        }

    }

    /* Unit 5, Debug statement to show list prior to proper sorting.

    printf("\nUnsorted list: \n");
    for (i = 0; i < entryCount; i++)
    {
        printf("\t%d: %s\n", (id + i) -> student, (id + i) -> studentGrade);
    }
    */

    /* Call sort function. No value returned. Sorting is
       done in place on the heap. */

    sort(id, entryCount);

    // Console statements to show the user the results.

    printf("\nSorted by Student ID: \n");
    for(i = 0; i < entryCount; i++)
    {
        // Unit 5, Use dot notation to access struct using array
        printf("\t%d Student ID: Student Grade: %s\n", id[i].student, id[i].studentGrade);
    }
    // free heap memory allocation
    free(id);

    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */

    return (0);
}

    // Unit 5, function to sort students by studentID.
void sort(struct person id[], int cnt)
{
    int inner;
    int outer;
    struct person temp;

    // Nested loop in loop for sort.
    for(outer = 0; outer < cnt - 1; ++outer)
    {
        for(inner = outer + 1; inner < cnt; ++inner)
        {
            // Note arrow -> notation to access struct via pointer
            // Uses < to sort ages in ascending order

            // Unit 5, Bonus: If you change.student to .studentGrade
            // the program will sort by the grade.
            if(id[inner].student < id[outer].student)
            {
                temp = id[inner];
                id[inner] = id[outer];
                id[outer] = temp;
            }
        }
    }
    // no value returned for void
    return;
}


