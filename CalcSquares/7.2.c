// print squares and break every 24 squares
/* Prints a table of squares using a while statement */
#include <stdio.h>
int main(void)
{
	int i, n;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	i = 1;
	getchar();
	while (i <= n) {
		printf("%10d%10d\n", i, i * i);

		if (((i) % 24) == 0) 
		{
			printf("Press Enter to continue...");
			getchar();
		}
		

		i++;
	}
	return 0;
}