/*
Pseudocode:

Initialize random number generator
ask for num cards
get num cards
loop until num cards are dealt
	pick a random card
	if card not alrady dealt
	the
		deal card
		adjust count
	end if
end loop
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define numsuits 4
#define numranks 13
int main() 
{
	int inhand[numsuits][numranks] = {0};
	int numcards;
	char suit, rank;
	const char rankcode[numranks] = {'a', '2', '3', '4', '5', '6', '7', 
										'8', '9', 't', 'j', 'q', 'k'};
	const char suitcode[numsuits] = { 'c','d', 'h', 's'};

	srand(time(NULL));

	printf("How many cards? ");
	scanf_s("%d", &numcards);

	suit = rand() % numsuits;
	rank = rand() % numranks;

	if (inhand[suit][rank] == 1)
	{
		inhand[suit][rank] = 1;
		printf("%i%i", rankcode[rank], suitcode[suit]);
		numcards--;
	}
	return 0;
}