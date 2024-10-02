/*Trent Chipman
Project 7.14

Complete Chapter 7 Programming Project 14 using Cygwin and gcc.  Submit a .c file.
Remember the 80-character line limit in your .c file.
Example of program running:
Enter a positive number: 3
Square root: 1.73205

Make sure that you display the exact prompts and spacing as the example provided.

Use newton's method

X is users num
Guess y = 1
Next guess is avg of y and num/y


Enter a positive number: 3
Square root: 1.73205
*/

/*************************************************
* Function Title: Main
*
* Summary: Uses newtons method to calculate square root of a number from user
*
* Inputs: num
* Outputs: sqrt
*
* Compile instructions:  gcc newton.c –o newton.exe
**************************************************
* Pseudocode
*
* Begin
*   create num and sqrt doubles
*	Ask for num
*	Get num
*	Loop to repeat newtons method
*	Print the square root
* End
*************************************************/

#include <stdio.h> 
#include <math.h>

int main()
{     // Begin 
	//create numand sqrt doubles
	double num, sqrt = 1, sqrtold;
	//Ask for num
	printf("Enter a positive number: ");
	//Get num
	scanf_s("%lf", &num);
	//Loop to repeat newtons method
	do {
		sqrtold = sqrt;
		sqrt = (((num / sqrt) + sqrt) / 2);
	} while (fabs(sqrtold - sqrt) > (0.00001 * sqrt));

	printf("Square root: %lf\n", sqrt); //   Print the square root 

	return 0;
}     // End 