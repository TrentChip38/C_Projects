/*************************************************
* Function Title: Main
*
* Summary: Reverse the 2 digits in a number
*
* Inputs: num
* Outputs: digit1, digit2
*
* Compile instructions:  gcc spell.c �o spell.exe
**************************************************
* Pseudocode
*
* Begin
*		create ints
*		ask for number
*		get number
*		calculate digit 1
*		calculate digit 2
*		find words for digits and print
* End
*************************************************/
#include <stdio.h>
int main(void)
{
	//create ints
	int num, digit1 = 0, digit2 = 0;
	//ask for number
	printf("Enter a number between 1 and 99:");
	//get number
	scanf_s("%d", &num);
	//calculate digit 1
	digit1 = num / 10;
	//calculate digit 2
	digit2 = num % 10;

	//find words for digits and print
	if (num < 20 && num > 9) {
		switch (num) {
		case 10:  printf("ten");
			break;
		case 11:  printf("eleven");
			break;
		case 12:  printf("twelve");
			break;
		case 13:  printf("thirteen");
			break;
		case 14:  printf("fourteen");
			break;
		case 15:  printf("fifteen");
			break;
		case 16: printf("sixteen");
			break;
		case 17:  printf("seventeen");
			break;
		case 18:  printf("eighteen");
			break;
		case 19:  printf("nineteen");
			break;
		default: printf("Number not recognized");
			break;
		}
	}
	else {
		if (num > 19) {

			switch (digit1) {
			case 2:  printf("twenty");
				break;
			case 3:  printf("thirty");
				break;
			case 4:  printf("forty");
				break;
			case 5:  printf("fifty");
				break;
			case 6:  printf("sixty");
				break;
			case 7:  printf("seventy");
				break;
			case 8: printf("eighty");
				break;
			case 9:  printf("ninety");
				break;
			default: printf("Number not recognized");
				break;
			}
			if (digit2 > 0){
				printf("-");
			}
		}
	}


	if (digit2 > 0 && (num > 20 || num < 10)) {
		switch (digit2) {
		case 1:  printf("one");
			break;
		case 2:  printf("two");
			break;
		case 3:  printf("three");
			break;
		case 4:  printf("four");
			break;
		case 5:  printf("five");
			break;
		case 6:  printf("six");
			break;
		case 7:  printf("seven");
			break;
		case 8:  printf("eight");
			break;
		case 9:  printf("nine");
			break;
		default: printf("Number not recognized");
			break;
		}
	}

	//print two digits
	//printf("%1d%1d\n", digit1, digit2);
	return 0;
}