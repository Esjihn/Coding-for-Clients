/* Matthew Miller - IT2240 - U03A1 - Part 1
 * 04/23/2018 Rev. 1
 */

// Commenting code

/*You should add at least 5 comments to the code provided. Be sure to recompile
and test the code after you have added your comments to make sure you have not
introduced any syntax errors.
*/

#include <stdio.h>

// Create modularized code. Cleaner looking and global variables can be modified easily.
// Here DAYS, which will soon become an array, is defined 7. (number of days in a week)
#define DAYS 7

int main(void) {

    // Let the User know that its time to give C input!
	printf("Enter hourly wage: ");
	// Create a floating point variable X.X or XX.XX then store users wage input inside.
	float wage;
	scanf("%f", &wage);

    // Let the User know that its time to give C input!
	printf("Enter hours for each day in the week: ");
	/* This block of code is a for loop, "for(initialization; condition; iteration).
	Which means it will loop until the condition is satisfied i.e. no longer true.
	Which also declares a counter variable "i" and creates an Array that grabs the
	users input (hours worked for the day) and stores them into the array. */
	int i = 0;
	float hours[DAYS];
	for(i = 0; i < DAYS; i++) {
		printf("Day %d: ", i + 1);
		scanf("%f", &hours[i]);
	}
    /* This block of code is a for loop, "for(initialization; condition; iteration).
    Which means it will loop until the condition is satisfied i.e. no longer true.
	Which also creates an Array that counts (the sum total of hours the user entered)
	and stores them into the array. Then it uses a compound assignment operator +=
	+= means to increment. Here totalHours is being incremented by the sum of total
	of hours. Note that this time the variable created "totalHours" is not a counter
	variable like above, it is used in this capacity to store exactly what it is named.*/
	float totalHours = 0;
	for(i = 0; i < DAYS; i++) {
		totalHours += hours[i];
	}
    /* This block of code creates a variable grossPay that stores grossPay, with an if-else
    statement that checks if certain conditions are occurring and then changes grossPay
    depending on what is happening.
    Situation 1: If the sum of the hours array stored as totalHours is over 40, then
    create variable overtimeHours which subtracts the hours OVER 40 by 40 (non overtime)
    and then use two compound assignment operators (+=) to increment (add) grossPay over
    2 formulas. The first formula is the hours over 40 (overtime) multiplied by normal
    wage rate multiplied by 1.5 (overtime) hourly rate.

    Situation 2: ELSE, If totalHours, which the variable that is the sum of hours entered
    into the previous array, is less than 40 then just calculate a strictly normal grossPay
    which is just totalHours multiplied by the users rate.
    */
    float grossPay = 0;
	if(totalHours > 40) {
		float overtimeHours = totalHours - 40;
		grossPay += overtimeHours * wage * 1.5;
		grossPay += wage * 40;
	}
	else {
		grossPay = totalHours * wage;
	}
    /* Well we have to show the user the results of all of our amazing coding right?
    This statement prints out the result of the logic above. $ Gives us a readable
    format for the user. %.2f gives us a nice recognizable 2 decimal place float that
    is readable as an amount that can be tangibly paid out.*/
	printf("Gross pay: $%.2f", grossPay);

	/* return 0, A macro defined in stdlib as EXIT_SUCCESS program execution complete
    and program terminated AS EXPECTED. */
	return 0;
}

