/*
*  Summary: ask for numbers 1-16 in a random order,
* then print them formated in a square,
* then print sums for each row, column, and diagonal
*
* Psuedocode:
* Start
*	Create variables for each spot in 4*4 square
*	Create variables for each sum
*	Ask for numbers 1-16
*	Get numbers
*	Assign each number to each variable in order
*	Calculate rows columns and diagonals.
*	print square and print sums
* End
*
*/

#include <stdio.h>

int main(void)
{
	//create all variables for each spot on square
	int g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0, g6 = 0, g7 = 0, g8 = 0,
		g9 = 0, g10 = 0, g11 = 0, g12 = 0, g13 = 0, g14 = 0, g15 = 0, g16 = 0;
	//create all variables for each sum
	int row1, row2, row3, row4, col1,
		col2, col3, col4, diag1, diag2;

	//ask for numbers
	printf("Ender the numbers from 1 to 16 in any order:");
	//get numbers and set them equal to each variable
	scanf_s("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
		&g1, &g2, &g3, &g4, &g5, &g6,
		&g7, &g8, &g9, &g10, &g11, &g12,
		&g13, &g14, &g15, &g16);

	//calculate rows
	row1 = g1 + g2 + g3 + g4;
	row2 = g5 + g6 + g7 + g8;
	row3 = g9 + g10 + g11 + g12;
	row4 = g13 + g14 + g15 + g16;
	//calculate columns
	col1 = g1 + g5 + g9 + g13;
	col2 = g2 + g6 + g10 + g14;
	col3 = g3 + g7 + g11 + g15;
	col4 = g4 + g8 + g12 + g16;
	//calculate diagonals
	diag1 = g1 + g6 + g11 + g16;
	diag2 = g4 + g7 + g10 + g13;
	//print square
	printf("Square:\n%-2d %-2d %-2d %-2d \n%-2d %-2d %-2d %-2d \n",
		g1, g2, g3, g4, g5, g6, g7, g8);
	printf("%-2d %-2d %-2d %-2d \n%-2d %-2d %-2d %-2d \n\n",
		g9, g10, g11, g12, g13, g14, g15, g16);
	//print sums
	printf("Row1 = %d  Row2 = %d  Row3 = %d  Row4 = %d\n",
		row1, row2, row3, row4);
	printf("Column1 = % d  Column2 = % d  Column3 = % d  Column4 = % d\n",
		col1, col2, col3, col4);
	printf("Diagonal1 = % d  Diagonal2 = % d \n\n\n", diag1, diag2);

	return 0;
}