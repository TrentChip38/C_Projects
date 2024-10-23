#include <iostream>
using namespace std;
void main() {
	int list[10] = { 5, 6, 7 };
	int k;
	int length = 3;
	int i = 0;
	int j = 0;
	int num1;
	int num2;
	cout << "Enter a number: ";
	cin >> k;
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
