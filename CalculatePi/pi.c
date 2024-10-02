/*************************************************
* Function Title: pi
*
* Summary: Asks for desired value of n and prints pi using n terms
*
* Inputs: n
* Outputs: pi
*
* Compile instructions:  gcc pi.c –o pi.exe
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
* End
*************************************************/
#include <stdio.h>
int main(void) 
{
	//Create ints and a float for pi
	int j = 1;
	float num = 0, i = 1, pi = 0, add = 0;
	//Ask for value n
	printf("Enter an integer n. The value of pi will be ");
	printf("calculated using n terms of an infinite series. n:");
	//get n
	scanf("%f", &num);
	//loop to add desired terms of pi
	for (;i < (num); i++;)
	{
		//find the next fraction to add
		add = (4 / ((i * 2) - 1));
		//printf("%f %f\n", 1/add, add);
		//add or subtract
		j = i;
		if (j % 2 == 0)
		{
			pi -= add;
		}
		else
		{
			pi += add;
		}

		printf("%f\n%f\n", (j % 2) == 0, (j % 2) == 0);
		//if (j % 2 == 1) { pi += add; } else if (j % 2 == 0) { pi -= add; }
		printf("%f\n", pi);
		
	}
	printf("The approximation of pi using %f terms is %f", num, pi);
	return 0;
}