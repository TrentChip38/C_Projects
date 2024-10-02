/*************************************************
* Function Title: pie
*
* Summary: Asks for desired value of n and prints pi using n terms
*
* Inputs: n
* Outputs: pi
*
* Compile instructions:  gcc pie.c –o pie.exe
**************************************************
* Pseudocode
*
* Begin
*   Create ints and a float for pi
*	Ask for value n
*	get n
*	loop to add desired terms of pi
*		find the next fraction to add
*		add or subtract
*	print pi
* End
*************************************************/

#include <stdio.h>
int main(void) 
{
	//Create ints and a float for pi
	int num = 0, i = 1;
	float pi = 0, add = 0;
	//Ask for value n
	printf("Enter an integer n. The value of pi will be ");
	printf("calculated using n terms of an infinite series. n:");
	//get n
	scanf("%d", &num);
	//loop to add desired terms of pi
	while (i < (num + 1))
	{
		//find the next fraction to add
		add = (4 / ((i * (float)(2)) - 1));
		//add or subtract
		if ((i % 2) == 1) { pi += add; }
		else { pi -= add; }
		i++;
	}
	//print pi
	printf("The approximation of pi using %d terms is %f", num, pi);
	return 0;
}