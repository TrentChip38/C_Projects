#include <iostream>
using namespace std;

//Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.
//For example, given 156, you should return 3.

int LongestBinRun(unsigned int num) {
	cout << num;
	int length_int = 32;
	int i = 0;
	int run1 = 0;
	int run2 = 0;
	bool bin;
	while (i < length_int) {
		bin = (num & 1);
		cout << bin;
		cout << "\n";
		if (bin) {
			cout << "Run: ";
			run1++;
			cout << run1;
			cout << "\n";
			if (run1 > run2) {
				run2 = run1;
			}
		}
		else {
			if (run1 > run2) {
				cout << "Next biggest run is: ";
				cout << run1;
				cout << "\n";
				run2 = run1;
			}
			run1 = 0;
		}
		num = num >> 1;
		i++;
	}
	return run2;
}

int main(int argc, char* argv[]) {
	unsigned int num = 6345;//(unsigned int)argv[1];
	int run = LongestBinRun(num);
	cout << "The longest consecutive run of 1's is: ";
	cout << run;
	cout << "\n";
}