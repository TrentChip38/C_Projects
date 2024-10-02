/*************************************************
* Function Title: Main
*
* Summary: Asks user for 5 digits and finds the greatest and lowest
*
* Inputs: num1, num2, num3, num4, num5
* Outputs: Largest, Smallest
*
* Compile instructions:  gcc NewBigSmallToCompile.c �o bigsmall.exe
**************************************************
* Pseudocode
*
* Begin
*   create 5 ints to store the digits
*	ask for 5 digits
*	get the 5 digits
*	compute the greatest
*	compute the smallest
*	print them
* End
*************************************************/

# include <stdio.h>

int main(void)
{
	//create 5 ints to store the digits
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, 
		greatest = 0, smallest = 0;
	//ask for 5 digits
	printf("Enter five integers in any order:");
	//get the 5 digits
	scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

	// compute the greatest
	if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5) 
	{ 
		greatest = num1; 
	}else if (num2 > num3 && num2 > num4 && num2 > num5) {
		greatest = num2;
	}else if (num3 > num4 && num3 > num5) {
		greatest = num3;
	}else if (num4 > num5) {
		greatest = num4;
	}else { greatest = num5; }

	// compute the smallest
	if (num1 < num2 && num1 < num3 && num1 < num4 && num1 < num5)
	{
		smallest = num1;
	}else if (num2 < num3 && num2 < num4 && num2 < num5) {
		smallest = num2;
	}else if (num3 < num4 && num3 < num5) {
		smallest = num3;
	}else if (num4 < num5) {
		smallest = num4;
	}else { smallest = num5; }

	//print them
	printf("Largest integer: %d \nSmallest integer: %d", greatest, smallest);

	return 0;
}