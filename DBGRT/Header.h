/*************************************************************
Function Title: linked list header file

Summary: define program functions

Inputs: none
Outputs: none

Pseudocode:
Begin
define integers
End
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct node
{
	int n;
	struct node* next;
};

struct node* buildLinkedList(struct node* first, FILE* fp);

void printOutputFile(struct node* first, FILE* fp);
