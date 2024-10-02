/*
Program Reverse2digitnumber
susmmary -  Reverse the 2 digits in a number

Pseudocode:
	Begin
		create ints
		ask for number
		get number
		calculate digit 2
		calculate digit 1
		print two digits
	End
*/
#include <stdio.h>
int main(void)
{
	//create ints
	int num, digit1, digit2;
	//ask for number
	printf("Enter a two digit number:");
	//get number
	scanf_s("%d", &num);
	//calculate digit 2
	digit2 = num / 10;
	//calculate digit 1
	digit1 = num % 10;
	//print two digits
	printf("%1d%1d\n", digit1, digit2);
	return 0;
}