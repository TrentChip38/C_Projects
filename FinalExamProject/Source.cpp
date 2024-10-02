#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct student* delete_student(
	struct student* first,
	char* last_name,
	char* first_name);

int main()
{     // Begin 
	struct student {
		char* first_name;
		char* last_name;
		struct student* next;
	};

	

	return 0;
}     // End


/*************************************************
* Function Title: delete_student
*
* Summary: Deletes a node with a specified first and last name
* from a linked list of names
*
* Inputs: pointer to beginning of linked list, last_name, first_name
* Outputs: pointer to the beginning of the linked list
*
**************************************************
* Pseudocode
*
* Begin
*	create struct pointers current and previous
*	make current equal to first
*	loop while nodes continue and node not found
*		check if last name is the one we are looking for
*		if first name is also the one we are looking for
*			delete node
*				make previous node point to next node
*				free this node
*				node is found
*		move to next node
*	return beginning node pointer
* End
*************************************************/
struct student* delete_student(
	struct student* first,
	char* last_name,
	char* first_name) {
	//create struct pointers current and previous
	struct student* cur, * prev;
	//make current equal to first
	cur = first;
	//loop while nodes continue and node not found
	int end = 0;
	while (cur != NULL && end == 0) {
		//check if last name is the one we are looking for
		//if first name is also the one we are looking for
		if ((strcmp(cur->last_name, last_name) == 0) &&
			(strcmp(cur->first_name, first_name)) {
			//delete node
			//make previous node point to next node
			prev->next = cur->next;
				//free this node
				free(cur);
				//node is found
				end = 1;
		}
		//move to next node
		prev = cur;
		cur = cur->next;
	}
	//return beginning node pointer
	return first;
}