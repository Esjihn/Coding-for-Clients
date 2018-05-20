/* Matthew Miller - IT2240 - U03A1 - Part 2
 * 04/23/2018 Rev. 1
 */

// Guessing Game

/* This program is a guessing game that counts how many tries it takes for a
player to guess a random number in the range from 1 to 20 (inclusive) that
the computer has generated. The program should prompt the user for a guess
and then indicate if the guess was too high, too low, or correct.
When the player guesses correctly, the program should print out how many
guesses the player made.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Create Variables
    int guessed = 0;
    int ctr = 0;

    // srand ensures we get a different random number every time the program is run.
    srand((unsigned)time(0));
    // ensures that the random number is always a number from 1 to 20.
    int random = rand() % 20 + 1;


    // Console Header
    printf("\n\n\t\t\tGuessing Game!?!\n\n\n");

    printf("\t\tTake a chance! If you dare! O_O!\n\n");

    printf("The program counts how many tries it takes for you to guess\n"
           "a random number in the range from 1 to 20 that I, the evil programmer\n"
           "have generated. Fear not! My assistant will let you know if your guess\n"
           "was too high to low or correct. When its is in the mood Bwhahaha!\n\n");
    printf("Let's Begin!\n\n");

    printf("\tGuess my number! Remember any integer values of 1 through 20!\n\t");

    /* Commented out debug statement help tests code throughout the program.
    This way you ensure a higher probability of your code being completed more
    efficiently and with as little errors as possible.*/

    // The below code shows the programmer the "invisible" randomly generated number.
    //printf("\tRandom number generator check %02d \n\t", random);


    /* Guessing Game Logic
    Here, we use a while loop with counter variable to loop until the user guesses
    the correct number. Our if else statements cover different scenarios. If the user
    guesses right, guesses too low, guesses too high, enters an integer higher than the
    allowed 20.

    EDIT: I tried to change this logic to a for loop but I was unable to do it
    successfully. I did manage to implement a correct for loop in part 3.
    */

    while(1)
    {
        ctr++;

        scanf(" %d", &guessed);

        if(guessed == random)
        {
            printf("\t\t Wow! You guessed right! What an animal!\n\n");
            printf("\t\t It only took you %d time(s)\n\n", ctr);
            printf("\t\t\t!!!Congratulations!!! \n\n");
            break;
        } else if (guessed < random)
        {
            printf("\tAwh your guess is too low. :( Try again. You can do it! :)\n\t");
        } else if (guessed > 20)
        {
            printf("\tThe random number is only integers from 1 to 20. Try again!\n\t");
        } else if (guessed > random)
        {
            printf("\tAwh your guess was too high. :( Try again. You can do it! :)\n\t");
        } else
            printf("\tThe system is impervious to hackers, please enter correct values!\n");
    }

    /* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */

	return 0;
}
