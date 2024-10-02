// dink around w pointers


void avg_sum(double a[], int n, double* avg, double* sum)
{
	int i;
	*sum = 0.0;
	for (i = 0; i < n; i++)
		*sum += a[i];
	*avg = *sum / n;
}
#include <stdio.h>
int main(void)
{
	double a[] = { 1, 6, 9, 3, 5 };
	double sum, avg;
	avg_sum(a, 5, &avg, &sum);
	printf("%lf\t%lf\n", avg, sum);
	return 0;
}




/*float i = 9, j = 5, * p = &j, * q = &i;
	p = *&q;
	*/