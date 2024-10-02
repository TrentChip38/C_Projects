/*************************************************
* Function Title: Main
*
* Summary: reads natural numbers from an input text file
* and writes a table of integers and each integer’s corresponding square
* root, cube root, and fourth root to an output text file
*
* Inputs: two file names
* (name of file with integers, and name of file to copy final table to)
* Outputs: none
*
* Compile instructions:  make
**************************************************
* Pseudocode
*
* Begin
*	Get command line arguements
*	Check command line arguments
*	Create variables and file pointers
*	Create node structure
*	Create pointers for first node, current, previous, last, and new
*	Open files and check validity
*	Create first node
*	Create nodes
*		get rid of enter
*		check that file continues
*		get next number from file
*		loop to place in correct spot of linked list
*				If end of linked list put at end
*					allocate, store, and point nodes
*				if its int is same delete it
*							leave loop
*				if cur int is greater, place before
*					allocate, store, and point nodes
*					first time through prev doesn't exist, so use first
*				if cur less than int check next node
*					move up cur and prev
*	Calculate all roots for each value
*	Write all linked list integers and roots to specified text file
*	Free all memory alocation for the linked list
*	Close files
* End
*************************************************/
#ifdef HEADER
#else 
#include "header.h"
#define HEADER
#endif

int main(int argc, char* argv[])//Get command line arguements
{//Begin
	//Check command line arguments
	if (argc != 3) {
		printf("Command line doesnt have 3 arguements\n");
		exit(1);
	}
	//Create variables and file pointers
	FILE* input, * output;
	int num, currentnum;
	char c;
	int bool = 1, fool = 1;
	double Sqrt, Cbrt, Fthrt;
	//Create node structure
	struct node {
		int num;
		struct node* next;
	};
	//Create pointers for first node, current, previous, last, and new
	struct node* cur, * prev, * first, * last = NULL, * newnode;
	//Open files and check validity
	input = fopen(argv[1], "r");
	if (input == NULL) {
		printf("Illegal input file.\n");
		exit(1);
	}
	output = fopen(argv[2], "w");
	if (output == NULL) {
		printf("Illegal output file.\n");
		exit(1);
	}

	//Create first node
	prev = cur = newnode = first = malloc(sizeof(struct node));
	fscanf(input, "%d", &first->num);
	first->next = last;
	//Create nodes
	c = fgetc(input);//get rid of enter
	//check that file continues
	//get next number from file
	while ((fscanf(input, "%d", &num) == 1) && (c != EOF)) {
		cur = first;
		bool = 1;
		fool = 1;
		//loop to place in correct spot of linked list
		while (bool == 1) {
			currentnum = cur->num;
			//If end of linked list put at end
			if ((cur->next == NULL) && (num > cur->num)) {
				//allocate, store, and point nodes
				newnode = malloc(sizeof(struct node));
				newnode->num = num;
				cur->next = newnode;
				newnode->next = last;
				bool = 0;
			}
			else if (num == currentnum) {
				//if its int is same delete it
				bool = 0;//leave loop
			}
			else if (num < currentnum) {
				//if cur int is greater, place before
				//allocate, store, and point nodes
				newnode = malloc(sizeof(struct node));
				newnode->num = num;
				if (fool == 1) {
					//first time through prev doesn't exist, so use first
					fool == 0;
					first = newnode;
				}
				else {
					prev->next = newnode;
				}
				newnode->next = cur;
				bool = 0;
			}
			else if (num > currentnum) {
				//if cur less than int check next node
				//move up cur and prev
				prev = cur;
				cur = cur->next;
			}
			else { printf("Number comparison failure\n"); }
			fool = 0;
		}
		c = fgetc(input);
	}
	cur = first;
	while (cur != NULL) {
		//Calculate all roots for each value
		Sqrt = (double)sqrt(cur->num);
		Cbrt = (double)cbrt(cur->num);
		Fthrt = (double)sqrt(sqrt(cur->num));
		//Write all linked list integers and roots to specified text file
		fprintf(output, "%d\t", cur->num);
		fprintf(output, "%.4lf\t", Sqrt);
		fprintf(output, "%.4lf\t", Cbrt);
		fprintf(output, "%.4lf\n", Fthrt);
		prev = cur;
		cur = cur->next;
		//Free all memory alocation for the linked list
		free(prev);
	}
	//Close files
	fclose(input);
	fclose(output);
	return 0;
}//End