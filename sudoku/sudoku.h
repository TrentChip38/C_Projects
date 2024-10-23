//sudoku class
#ifndef Sudokuh
#define Sudokuh

//things to include and declare
#include <iostream>
#include <cstdlib>
using namespace std;

//create struct to hold num and identifier
struct num{
    char c;
    int p;
};

//class for Rational numbers
class sudoku {
private:
    struct num array[9][9];
    int noerror(int x, int y, int num);
public:
    sudoku(int n);
    int solve();
    void print();
};
#endif