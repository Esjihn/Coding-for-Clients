/* Matthew Miller - IT2240 - Part 4
 * 04/06/2018 Rev. 1
 */

/* "User Input" Write a program that prompts the user to enter a character,
an integer, and floating point number. After reading the input, the program
should print out the values entered. Be sure to format the code correctly
and include relevant comments.*/

// include standard input/output library for printf() and scanf()

#include <stdio.h>

int main(void)
{
    // Create variables
    int intInput;
    double doubleInput;
    float floatInput;

    // Console Header
    printf("\n\nLet's showcase some of that good ole' fashioned Input/Output in C!\n\n");

    // Let the User know that its time to give C input!
    // Grab User input by use of Ampersand and scanf()

    printf("\tEnter an integer: \n\t");
    scanf(" %d", &intInput);
    printf("\tYou entered %d as an integer. Good Job!\n\n", intInput);

    printf("\tNow enter a double! (Remember a decimal and two spaces! X.XX!)\n\t");
    scanf(" %lf", &doubleInput);
    printf("\tYou entered %.2f as a double. Good Job!\n\n", doubleInput);

    printf("\tNow enter a float! (Remember a decimal and one space! X.X!)\n\t");
    scanf(" %f", &floatInput);
    printf("\tYou entered %.1f as a float. Good Job!\n\n", floatInput);
    printf("Thank you for your time! :)\n\n");



    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */

    return(0);
}
