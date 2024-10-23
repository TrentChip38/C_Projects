#include <iostream>
using namespace std;
//unfinished
//with any number of steps, taking two or one, how many combinations?
void main() {
	int steps = 10;
	int comb = 0; //combinations
	int pairs = 0;
	if (steps % 1 == 0) {
		comb += 2;
	}
	if (steps >= 4) {
		pairs = (steps - (steps % 1));
		if (pairs >= 2) {
			comb += 3;
		}
		if (pairs >= 3) {

		}
	}

	//loop through list
	while (i < length) {
		//check each number against all in front of it
		num1 = list[i];
		j = i + 1;
		//loop through rest of list to check with first number
		while (j < length) {
			num2 = list[j];
			if ((num1 + num2) == k) {
				cout << "True" << endl;
				return;
			}
			j++;
		}
		i++;
	}
	cout << "False" << endl;
	return;
}
