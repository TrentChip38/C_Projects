void pay_amount(int dollars, int* twenties, int* tens,
	int* fives, int* twos, int* ones);

/*************************************************
* Function Title: Main
*
* Summary: determine the smallest total number of $20, $10, $5, $2,
*	and $1 bills necessary to pay an amount specified by the user
*
* Inputs: amount to be payed
* Outputs: amount to pay of each bill
*
* Compile instructions:  gcc paybill.c –o paybill.exe
**************************************************
* Pseudocode
*
* Begin
*   Initialize variables for each bill and total
*	Ask for amount
*	Get amount
*	Call function to find amount of each bill
*	Print amount of each bill
* End
*************************************************/

#include <stdio.h>
int main()
{     // Begin 
	//Initialize variables for each bill and total
	int total, twenties, tens, fives, twos, ones;
	//Ask for amount
	printf("Enter an amount to be broken into bills: $");
		//Get amount
	scanf("%d", &total);
	//Call function to find amount of each bill
	pay_amount(total, &twenties, &tens, &fives, &twos, &ones);
	//Print amount of each bill
	printf("The following numbers of the specified bills are required:\n");
	printf("$20: %d\n$10: %d\n$5: %d\n",twenties, tens, fives);
	printf("$2: %d\n$1: %d\n", twos, ones);
	return 0;
}     // End 

/*************************************************
* Function Title: pay_amount
*
* Summary: calculates smallest amount of each bill for given amount
*
* Inputs: $ amount
* Outputs: Amount of each bill
**************************************************
* Pseudocode
*
* Begin
*   Get amount total and variables address
*	calculate each bill samount from total
*	then minus amount from total
* End
*************************************************/
//Begin
void pay_amount(int dollars, int* twenties, int* tens,
	int* fives, int* twos, int* ones)
	//Get amount total and variables address
{
	*twenties = dollars / 20;//calculate each bill samount from total
	dollars -= *twenties * 20;//then minus amount from total
	*tens = dollars / 10;
	dollars -= *tens * 10;
	*fives = dollars / 5;
	dollars -= *fives * 5;
	*twos = dollars / 2;
	dollars -= *twos * 2;
	*ones = dollars;
	return;
}     // End 