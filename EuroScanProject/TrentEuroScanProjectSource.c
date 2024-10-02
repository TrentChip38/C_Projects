/*************************************************
* Function Title: Main
*
* Summary: Use the method to chech an EAN code and print the digit to check
*
* Inputs: none
* Outputs: none
*
* Compile instructions:  gcc hello.c –o hello.exe
**************************************************
* Pseudocode
*
* Begin
*   Create variables for 12 integers the two summs and a total
*	Ask for the first 12 of EAN
*	Get first 12 digits and store each in a variable
*	calculate first sum
*	calculate second sum
*	multiply the first by 3 and add the other sum. This is the total so far.
*	print final computation
* End
*************************************************/ 
#include <stdio.h>

int main(void)
{  // Create variables for 12 integers the two summs and a total
	int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12,
		first_sum, second_sum, total;
	//Ask for the first 12 of EAN
	printf("Enter the first 12 digits of an EAN:");
	//Get first 12 digits and store each in a variable
	scanf_s("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", 
		&i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);
	//calculate first sum
	first_sum = i2 + i4 + i6 + i8 + i10 + i12;
	//calculate second sum
	second_sum = i1 + i3 + i5 + i7 + i9 + i11;
	//multiply the first by 3 and add the other sum. This is the total so far.
	total = 3 * first_sum + second_sum;
	
	//print final computation
	
	printf("Check digit: %d\n", 9 - ((total - 1) % 10));

	return 0;
}