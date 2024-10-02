/*************************************************
* Function Title: Main
*
* Summary: Asks user for 5 digits and finds the greatest and lowest
*
* Inputs: num1, num2, num3, num4, num5
* Outputs: Largest integer, Smallest integer
*
* Compile instructions:  gcc hello.c –o hello.exe
**************************************************
* Pseudocode
*
* Begin
*   create 5 ints to store the digits
*	ask for 5 digits
*	get the 5 digits
*	compute the greates
*	compute the smallest
*	print them
* End
*************************************************/

#include <stdio.h> 

int main()
{
	//create 5 ints to store the digits
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, greatest = 0, smallest = 0;
	//ask for 5 digits
	printf("Enter five integers in any order:");
	//get the 5 digits
	scanf("%d %d %d %d %d", num1, num2, num3, num4, num5);

	greatest = num1;
	smallest = num2;

	printf("Largest integer: %d \nSmallest integer: %d", greatest, smallest);

	return 0;
}