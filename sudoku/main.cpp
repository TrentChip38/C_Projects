/*************************************************
* Function Title: main
*
* Summary: Uses sudoku class to generate sudoku with n numbers and solve
*
* Inputs: None
* Outputs: None
*
**************************************************
* @name main
* @brief Uses sudoku class to generate sudoku with n numbers and solve
* @param None
* @retval None
*************************************************/
//include sudoku class and necesary library and namespace ceclarations
#include "sudoku.h" 

int main()
{
	int n;

	cout << "Welcome to SudokuSolver!!" << endl;
	cout << "Enter number of squares to prepopulate: ";
	cin >> n;

	sudoku s(n);
	s.print();
	cout << "Solving... ..." << endl;
	if (s.solve()) {
		cout << "Solved!" << endl;
		s.print();
	}
	else {
		cout << "Sorry, unsolvable..." << endl;
	}
	return 0;
}