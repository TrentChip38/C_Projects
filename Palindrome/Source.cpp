/*************************************************
* Function Title: Main
*
* Summary: Takes words/phrases and checks whether palindrome or not
*
* Inputs: words/phrase
* Outputs: If palindrome or not
*
* Compile instructions:  gcc palindrome.c –o palindrome.exe
**************************************************
* Pseudocode
*
* Begin
*	initialize variables and array
*	initialize pointer to first array value
*	explain and ask for input from user
*	store input in array
*		calculate size of input without spaces
*		set all upercase to lowercase
*		store next letter in next position of array using pointers
*	check if palindrome
*		loop
*			check first and last
*			print if not palindrome
*			then decrease and increase to next in line
*		if even length and reach neighboring position then palindrome
*		if odd length and reach same position then palindrome
*		print if palindrome
* End
*************************************************/

#include <stdio.h> 
#include <ctype.h>
#include <stdbool.h>

int main(void)
{     // Begin 
	//initialize variables and array
	char array[200];
	char letter;
	int length = 0;
	//initialize pointer to first array value
	char* pointer = array;
	char* pointerbottom = pointer;
	char* pointertop;
	//explain and ask for input from user
	printf("Enter a word/phrase: ");
	while(true)//store input in array
	{
		letter = getchar();
		if (islower(letter)) {
			//store next letter in next position of array using pointers
			*pointer = letter;
			pointer++;
			length++;//calculate size of input without spaces
		}
		else if (isupper(letter)) {
			//store next letter in next position of array using pointers
			*pointer = tolower(letter);//set all upercase to lowercase
			pointer++;
			length++;//calculate size of input without spaces
		}
		else if (letter == 10) {
			pointer--;
			break;
		}
	}
	
	pointertop = pointerbottom + length -1;
	//check if palindrome
	//loop
	while (true) {
		//check first and last
		if(*pointertop != *pointerbottom){
			//print if not palindrome
			printf("The word/phrase is not a palindrome.\n");
			break;
		}
		//if even length and reach neighboring position then palindrome
		if ((length %2) == 0) {
			if (pointertop == (pointerbottom + 1)) {
				//print if palindrome
				printf("The word/phrase is a palindrome.\n");
				break;
			}
		}
		//if odd length and reach same position then palindrome
		if ((length %2) == 1) {
			if (pointertop == pointerbottom) {
				//print if palindrome
				printf("The word/phrase is a palindrome.\n");
				break;
			}
		}
		
		pointertop--;
		pointerbottom++;//then decrease and increase to next in line
	}
	/*pointerbottom = &array[0];
	int i = 0;
	while (i < length) {
		printf("%c", *(pointerbottom+i));
		i++;
	}*/
	return 0;
}     // End 