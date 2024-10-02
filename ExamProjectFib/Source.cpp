/*************************************************
* Function Title: Main
*
* Summary: Stores N terms of fibonacci sequence in an array
*
* Inputs: N
* Outputs: none
*
* Compile instructions:  gcc fib.c –o fib.exe
**************************************************
* Pseudocode
*
* Begin
*	define N
*   declare an array of size N
*	declare ints i and Num
*	stop if N isnt between 2 and 9
*	store first two numbers
*	loop
*		store next numer in array
*		find next number
* End
*************************************************/
#include <stdio.h>
#define N 9 //define N
int main(void)
{
	short int array[N];  //declare an array of size N
	//declare ints i and Num
	short int i = 2;
	short int Num = 2;
	if (N >= 2 && N <= 9) {//stop if N isnt between 2 and 9
		array[0] = { 1 };//store first two numbers
		array[1] = { 1 };
		while (i < N) {//loop
			array[i] = { Num }; //store next numer in array
			Num += array[i - 1]; //find next number
			i++;
		}
	}
	i = 0;
	while (i < N) { printf("%d\n", array[i]); i++; }
	//printf("%d", array[0]);
	return 0;
}