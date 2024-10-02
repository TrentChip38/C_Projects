/*************************************************************
Function Title: buildLinkedList

Summary: read values from input file, store in a
sorted linked list with duplicates removed

Inputs: pointer to head of list, pointer to input file
Outputs: pointer to head of list


Pseudocode:

begin
loop until end of input file
read a number from input file
for(cur = first, prev = NULL; cur != NULL && cur -> n > number;
prev = cur, cur->next)
end loop
if curr-> != number
then
new_node = create a struct node and store number
new_node -> next = cur;
if prev = NULL
first = new_node;
else
prev->next = new_node;
endif

return first

end
***********************************************************/

#ifdef HEADER
#else
#include"Header.h"
#define HEADER
#endif

struct node* buildLinkedList(struct node* first, FILE* fp)
{
	struct node* cur, * prev, * new_node;
	int number;

	while (!feof(fp))
	{
		if (fscanf(fp, "%d", &number) > 0)
		{
			new_node = malloc(sizeof(struct node));
			if (new_node == NULL)
			{
				printf("Error: malloc failed to add to linked list\n");
				exit(1);
			}

			new_node->n = number;
			for (cur = first, prev = NULL;
				cur != NULL && cur->n < new_node->n;
				prev = cur, cur = cur->next);

			if (cur != NULL && cur->n == new_node->n)
			{
				free(new_node);
			}
			else
			{

				new_node->next = cur;

				if (prev = NULL)
				{
					first = new_node;
				}
				else
				{
					prev->next = new_node;
				}
			}
			return first;
		}
	}
}


/*************************************************************
Function Title: printOutputFile

Summary: print integers and roots to output file

Inputs: pointer to head of list
pointer to output file

Outputs: none


Pseudocode:

begin
initialize ptr to start of list
loop until end of list
print ptr->n + roots to output file
fprintf(fp, "%d\t%f\t%f\t%f\t%f", ptr->n,
sqrt(ptr->n), cbrt(ptr->n), sqrt(sqrt(ptr->n)));
ptr = ptr -> next;
endloop
end
***********************************************************/

void printOutputFile(struct node* first, FILE* fp)
{
	struct node* ptr = first;

	while (ptr != NULL)
	{
		fprintf(fp, "%d\t%f\t%f\t%f\n", ptr->n, sqrt(ptr->n),
			cbrt(ptr->n), sqrt(sqrt(ptr->n)));
		ptr = ptr->next;
	}
}

/*************************************************************
Function Title: freelinkedlist

Summary: progress through each value and free it to the main function

Inputs: pointer to head of list
pointer to output file

Outputs: none


Pseudocode:

begin
initialize ptr to start of list
loop until end of list
print ptr->n + roots to output file
fprintf(fp, "%d\t%f\t%f\t%f\t%f", ptr->n,
sqrt(ptr->n), cbrt(ptr->n), sqrt(sqrt(ptr->n)));
ptr = ptr -> next;
endloop
end
***********************************************************/