/* Matthew Miller - IT2240 - Part 2
 * 04/06/2018 Rev. 1
 */

/* "About You" Create a program that prints three lines of text about
yourself. Be sure to include appropriate spacing and new line characters
to make the output in the terminal window readable. As with all programming
code, but sure to format the program correctly and include comments and a header
for the file, such as shown above. */

// include standard input/output library for printf()


#include <stdio.h>

int main(void)
{
    /* Create proper printf with \n new line syntax. Also in order to
    make the console print more readable, one should add two \n\n to the
    beginning and end of the ENTIRE printf statement BLOCK (not individual).*/

    printf("\n\nMy name is Matthew D. Miller.\n");
    printf("I work in I.T. repair at Geek Squad as an"
           " Advanced Repair Agent.\n");
    printf("My major is Software Development; Program"
           " Application Development Emphasis.\n\n");


    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */

    return(0);
}
