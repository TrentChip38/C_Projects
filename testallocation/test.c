#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	
	return 0;
}

/*

struct point { int x, y; };
	struct rectangle { struct point upper_left, lower_right; };
	struct rectangle* p;

	p = malloc(sizeof(int)*4);
	//p->upper_left.x = 10;
	(*p).upper_left.x = 10;
	(*p).upper_left.y = 25;
	(*p).lower_right.x = 20;
	(*p).lower_right.y = 15;

	printf("Rectangles corners:(%d, %d) & (%d, %d)\n", 
		(*p).upper_left.x, (*p).upper_left.y, 
		(*p).lower_right.x, (*p).lower_right.y);z

*p = 10;
	p++;
	*p = 25;
	p++;
	*p = 20;
	p++;
	*p = 15;
	p -= 3;

printf("%d", *p);
	printf("%d", *++p);
	printf("%d", *++p);
	printf("%d", *++p);
*/