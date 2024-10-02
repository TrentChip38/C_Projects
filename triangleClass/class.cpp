// classes
#include "Header.h"
using namespace std;
Triangle::Triangle(float b, float h) {
    setvalues(float b, float h);
}
Triangle::Triangle(float b, float h) {
    setvalues(0, 0);
}
void Triangle::setvalues(float b, float h) {
    base = b;
    height = h;
}

double Triangle::area() {
    return base * height;
}