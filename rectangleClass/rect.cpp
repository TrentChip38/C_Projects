// Example program
#include <iostream>
#include <string>
using namespace std;
//int main()
//{
  //std::string name;
  //std::cout << "What is your name? ";
  //getline (std::cin, name);
  //std::cout << "test ";
//}

// classes example
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
public:
    void set_values(int, int);
    int area() { return width * height; }
};

void Rectangle::set_values(int x, int y) {
    width = x;
    height = y;
}

int main() {
    Rectangle rect;
    Rectangle square;
    rect.set_values(3, 4);
    square.set_values(5, 5);
    cout << "area: " << rect.area() << '\n';
    cout << "area: " << square.area() << '\n';
    return 0;
}