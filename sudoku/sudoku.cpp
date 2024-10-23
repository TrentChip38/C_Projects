//sudoku class functions
#include "sudoku.h" 
/**************************************************
* @name sudoku
* @brief initial creation of a sudoku with n numbers filled in
* @param number of initial spots to fill
* @retval None
*************************************************/
sudoku::sudoku(int n) {
	//create sudoku with n spaces populated and no obvious contradictions
	//assign default as * character of type impermanent
	int i = 0, j = 0;
	while (i < 9) {
		j = 0;
		while (j < 9) {
			array[i][j] = {'*', 0};
			j++;
		}
		i++;
	}
	//set loop variables
	i = j = 0;
	//initialize time
	srand(time(NULL));
	//create amount and num
	int amount = 0;
	int num;
	//loop through n times to populate n random numbers
	while (amount < n) {
		//find random spot 0-8
		i = (rand() % 9);
		j = (rand() % 9);
		//choose random number 1-9
		num = ((rand() % 9) + 1);
		//if spot is free and doesn't conflict with other numbers
		if ((array[j][i].p == 0) && noerror(j, i, num)) {
			//assign that number as permanent
			array[j][i].c = (num + 48);
			array[j][i].p = 1;
			amount++;
		}
	}
}
/**************************************************
* @name print
* @brief prints sudoku array stylized
* @param None
* @retval None+
*************************************************/
//define space and bigspace to be used for standard spacing in my array style
#define sp "	"
#define bsp "				"
#define sbsp "-------------------------------"
void sudoku::print() {
	//print sudoku
	int i = 0, j = 0;
	//print first three rows
	while (i < 3) {
		j = 0;
		cout << sp;
		while (j < 3) {
			cout << array[j][i].c << sp;
			j++;
		}//print first three of row
		cout << "|" << sp;//print line
		while (j < 6) {
			cout << array[j][i].c << sp;
			j++;
		}//print next three of row
		cout << "|" << sp;//print line
		while (j < 9) {
			cout << array[j][i].c << sp;
			j++;
		}//print last three of row
		//end row
		cout << endl;
		cout << bsp << "|" << bsp << "|" <<bsp;
		cout << endl;
		i++;
	}
	cout << sbsp << "-+" << sbsp << "+" << sbsp << endl;
	//print next three rows
	while (i < 6) {
		j = 0;
		cout << sp;
		while (j < 3) {
			cout << array[j][i].c << sp;
			j++;
		}//print first three of row
		cout << "|" << sp;//print line
		while (j < 6) {
			cout << array[j][i].c << sp;
			j++;
		}//print next three of row
		cout << "|" << sp;//print line
		while (j < 9) {
			cout << array[j][i].c << sp;
			j++;
		}//print last three of row
		//end row
		cout << endl;
		cout << bsp << "|" << bsp << "|" << bsp;
		cout << endl;
		i++;
	}
	cout << sbsp << "-+" << sbsp << "+" << sbsp << endl;
	//print next three rows
	while (i < 9) {
		j = 0;
		cout << sp;
		while (j < 3) {
			cout << array[j][i].c << sp;
			j++;
		}//print first three of row
		cout << "|" << sp;//print line
		while (j < 6) {
			cout << array[j][i].c << sp;
			j++;
		}//print next three of row
		cout << "|" << sp;//print line
		while (j < 9) {
			cout << array[j][i].c << sp;
			j++;
		}//print last three of row
		//end row
		cout << endl;
		cout << bsp << "|" << bsp << "|" << bsp;
		cout << endl;
		i++;
	}
}
/**************************************************
* @name solve
* @brief Solves the created sudoku if solvable 
* or prints if unsolvable
* @param None
* @retval int 1 or 0 for weather solved or unsolvable
*************************************************/
int sudoku::solve() {
	//solve sudoku if solvable

	int j = 0, i = 0, num;
	//find first changeable spot
	while (array[j][i].p == 1) {
		//go to next spot
		i++;
		//if reached end of row go to beggining of next row
		if (i == 9) {
			j++;
			i = 0;
		}
		cout << "+";
	}//loop through all spots of array skipping the permanent numbers
	while (j < 9 && i < 9) {
		//if asterisk
		if (array[j][i].c == 42) {
			//start at 0 if empty
			array[j][i].c = 48;
		}
		//keep track of num to check
		num = array[j][i].c - 48;
		num++;
		//check that number can be changed, and valid number
		if ((num <= 9) && noerror(j, i, num) && (array[j][i].p == 0)) {
			//if number works make that the number
			array[j][i].c = (num + 48);
			//move to next valid spot
			do {
				//go to next spot
				i++;
				//if reached end of row go to beggining of next row
				if (i == 9) {
					j++;
					i = 0;
				}
				//if reached end of array end with solved
				if (j == 9) {
					return 1;
				}
			} while ((array[j][i].p == 1));
		}
		else if ((num < 9) && (array[j][i].p == 0)) {
			//to start at this number and increment next time through
			array[j][i].c = (num + 48);
		}//ifbacktracked to initial spot, and incremented to 9
		else if (i == 0 && j == 0) {
			//not solvable
			return 0;
		}
		else
		{//if reached 9 and not valid and not beggining, backtrack
			do {
				//if you backtrack to beggining, end
				if (i == 0 && j == 0) {
					return 0;
				}
				//set used spaces passed, back to 0
				if (array[j][i].p == 0) {
					array[j][i].c = 48;
				}
				//if going back to previous row
				//(trying to decrement i less than 0)
				if (i == 0) {
					//go back a row and set i to 9
					j--;
					i = 9;
				}
				//decrement i normally
				i--;
			} while ((array[j][i].p == 1) && (i > 0) && (j > 0));
			//go back untill a changing spot is found
		}
	}
	//if solved return 1
	return 1;
}
/**************************************************
* @name noerror
* @brief Checks if a number in this spot is a valid placement
* @param int x (x coordinate), y (y coordinate), num (to check for validity)
* @retval int 1 or 0 for valid or not valid respectively
*************************************************/
#define arr array[j][i].c
int sudoku::noerror(int x, int y, int num) {
	//check for errors
	if (num < 0 || num > 9) {
		//check for error of a number not between 0-9
		cout << "# outside bounds" << endl;
	}
	try
	{
		if (x > 8) {
			throw x;
			cout << "x" << endl;
		}
		if (y > 8) {
			throw y;
			cout << "y" << endl;
		}
	}
	catch (int s)
	{
		cout << "An exception occurred"<<endl<< s << "outside array" << endl;
		exit(0);
	}
	//given a number and coordinates, determin if valid
	//check the new numbers column for same number
	int i = 0;
	while (i < 9) {//loop through all spots in column of x value
		if (array[x][i].c == (num + 48)) {
			return 0;
		}
		i++;
	}
	//check row of y for repeats of num
	int j = 0;
	while (j < 9) {//loop through all spots in row y
		if (array[j][y].c == (num + 48)) {
			return 0;
		}
		j++;
	}
	//check group boxes for that number
	//if cases for each of the 9 boxes
	if (x < 3 && y < 3) {
		//check first 3 in first 3 rows
		int j = 0, i = 0;
		while (j < 3) {
			i = 0;
			while (i < 3) {
				if (arr == (num + 48)) {
					//if any are the same as the number 
					//return 0 means invalid position
					return 0;
				}
				i++;
			}
			j++;
		}
	}
	else if (x < 6 && y < 3) {
		//check middle 3 in first 3 rows
		int j = 3, i = 0;
		while (j < 6) {//loop through spots 4-6
			i = 0;
			while (i < 3) {// of each of first 3 rows
				if (arr == (num + 48)) {
					return 0;//invalid
				}
				i++;
			}
			j++;
		}
	}
	else if (x < 9 && y < 3) {
		//check last 3 in first 3 rows
		int j = 6, i = 0;
		while (j < 9) {//loop through spots 7-9
			i = 0;
			while (i < 3) {// of each of first 3 rows
				if (arr == (num + 48)) {
					return 0;//invalid
				}
				i++;
			}
			j++;
		}
	}
	else if (x < 3 && y < 6) {
		//check first 3 in middle 3 rows
		int j = 0, i = 3;
		while (j < 3) {//loop through spots 1-3 again
			i = 3;
			while (i < 6) {//of each of the middle 3 rows
				if (arr == (num + 48)) {
					//invalid number here
					return 0;
				}
				i++;
			}
			j++;
		}
	}
	else if (x < 6 && y < 6) {
		//check middle 3 in middle 3 rows
		int j = 3, i = 3;
		while (j < 6) {//loop through spots 4-6 again
			i = 3;
			while (i < 6) {//of each of the middle 3 rows
				if (arr == (num + 48)) {
					return 0;//invalid number here
				}
				i++;
			}
			j++;
		}
	}
	else if (x < 9 && y < 6) {
		//check last 3 in middle 3 rows
		int j = 6, i = 3;
		while (j < 9) {//loop through spots 7-9 again
			i = 3;
			while (i < 6) {//of each of the middle 3 rows
				if (arr == (num + 48)) {
					return 0;//invalid number here
				}
				i++;
			}
			j++;
		}
	}
	else if (x < 3 && y < 9) {
		//check first 3 in last 3 rows
		int j = 0, i = 6;
		while (j < 3) {//loop through spots 1-3
			i = 6;
			while (i < 9) {//of each of the last 3 rows
				if (arr == (num + 48)) {
					return 0;//invalid number here
				}
				i++;
			}
			j++;
		}
	}
	else if (x < 6 && y < 9) {
		//check middle 3 in last 3 rows
		int j = 3, i = 6;
		while (j < 6) {//loop through spots 4-6
			i = 6;
			while (i < 9) {//of each of the last 3 rows
				if (arr == (num + 48)) {
					return 0;//invalid number here
				}
				i++;
			}
			j++;
		}
	}
	else if (x < 9 && y < 9) {
		//check last 3 in last 3 rows
		int j = 6, i = 6;
		while (j < 9) {//loop through spots 7-9
			i = 6;
			while (i < 9) {//of each of last 3 rows
				if (arr == (num + 48)) {
					return 0;//invalid number here
				}
				i++;
			}
			j++;
		}
	}
	//if no errors found 
	//then every number in the row, column, and box 
	//has been checked for this number
	//return 1 meaning valid placement
	return 1;
}