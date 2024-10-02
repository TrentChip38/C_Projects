// Example program
#include <iostream>
#include <string>
#include "class.cpp"
using namespace std;


int main() {
    Triangle t(5.4, 5.3);
    Triangle b(4.3, 6.9);
    //b.setvalues(3, 4);
    //t.setvalues(5, 5);
    cout << "area: " << t.area() << endl;
    cout << "area: " << b.area() << endl;
    return 0;
}