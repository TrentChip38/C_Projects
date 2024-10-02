/*************************************************
* Function Title: Main
*
* Summary: Uses newtons method to calculate square root of a number from user
*
* Inputs: num
* Outputs: sqrt
*
* Compile instructions:  gcc sqrt.c –o sqrt.exe
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
	//create num and sqrt doubles
	double num, sqrt = 1, sqrtold;
	//Ask for num
	printf("Enter a positive number: ");
	//Get num
	scanf("%lf", &num);
	//Loop to repeat newtons method
	do {
		sqrtold = sqrt;
		sqrt = (((num/sqrt)+sqrt) / 2);
	} while (fabs(sqrtold - sqrt) > (0.00001 * sqrt));

	printf("Square root: %.5lf\n", sqrt); //   Print the square root 

	return 0;
}     // End 