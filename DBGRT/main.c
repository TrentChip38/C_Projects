/*************************************************************
Function Title: main

Summary: read integers from an input text
file specified on the command line. Sorth the
values, remove duplicates, and print a table
of values with square roots, cube roots,
and fourth roots to an output text file
specified on the command line

Pseudocode:
initialize linked list to NULL
validate command line arguments
open input file; print error message and quit on failure
open output file; print error message and quit on failure
build linked list
print output file
free linked list
close files

Inputs: input text file name, output text file name
Outputs: none



***********************************************************/


#ifdef HEADER
#else
#include"Header.h"
#define HEADER
#endif


int main(int argc, char* argv[])
{
	printf("start of function\n");
	struct node* first = NULL;
	//number of inputs

	 //begin

	FILE* fp, * output;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error");
		exit(1);
	}

	output = fopen(argv[2], "w");
	if (output == NULL)
	{
		printf("Error");
		exit(1);
	}
	printf("opened files\n");

	printf("going to build linked list\n");
	first = buildLinkedList(first, fp);
	printf("built linked list\n");
	printOutputFile(first, output);
	printf("copied linked list\n");

	fclose(fp);
	fclose(output);

	return 0;
}