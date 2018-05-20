/* Matthew Miller - IT2240 - Part 3
 * 04/06/2018 Rev. 1
 */

/* "Integer and Floating Point Arithmetic" Write a single program that
prints the results of two arithmetic expressions using integers
and the results of two floating-point calculations (for a total of
4 calculations). Print out both the arithmetic expressions and the
answers calculated by the code. For this program, it is fine to use
"hard-coded" values (the numbers used in the calculations are provided
in the code) rather than user input. Be sure to format the code correctly
and include relevant comments in the source code (including the comment
at the top of the file with your name and identification of the program*/

// include standard input/output library for printf()

#include <stdio.h>

int main(void)
{
    // Create variables
    int calc1 = 10, calc2 = 20;
    int sum = calc1 + calc2;
    int sum2 = calc1 * calc2;

    // Remember that double is of type float.
    double float1 = 10.10;
    float float2 = 20.0;
    double sum3 = float1 + float2;
    double sum4 = float1 * float2;

    /* commented out debug statements help test code throughout the program.
    This way you ensure a higher probability of your code being completed more
    efficiently and with as little errors as possible.*/
    //printf("%d %d\n", calc1, calc2);
    //printf("%.2f %.3f\n", float1, float2);

    printf("\n\nLets complete 4 calculations, shall we!\n");

    printf("\n\tLets add 2 integer variables %d + %d equals %d.\n\n", calc1, calc2, sum);
    printf("\tLets multiply them now! %d * %d equals %d.\n\n", calc1, calc2, sum2);
    printf("\tLets add 2 float variables. %.2f + %.3f equals %.2f. Remember double is "
           "of type float!\n\n", float1, float2, sum3);
    printf("\tLets multiply them now! %.2f * %.3f equals %.2f\n\n", float1, float2, sum4);
    printf("Thank you for your time! :)\n\n");


    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */

    return(0);

}
