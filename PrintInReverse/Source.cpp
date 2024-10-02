#include <stdio.h>
# define N 5

int main()
{
	int i, nums[N];

	printf("Enter %d integers: ", N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &nums[i]);
	}
	for (i = (N - 1); i >= 0; i--)
	{
		printf("%d ", nums[i]);
	}
	return 0;
} 