#include <iostream>
#include <cmath>

using namespace std;

void drawLine(double x, double y, double length, double depth) {
    if (depth == 0) {
        return;
    }

    cout << "depth: " << depth << endl;
    cout << "p3 :" << x - length / 2 << " " << y + length / 2 << endl;
    cout << "p4 :" << x + length / 2 << " " << y + length / 2 << endl;
    cout << "p5 :" << x - length / 2 << " " << y - length / 2 << endl;
    cout << "p6 :" << x + length / 2 << " " << y - length / 2 << endl;


    drawLine(x - length / 2, y + length / 2, length / sqrt(2), depth - 1); // p3
    drawLine(x + length / 2, y + length / 2, length / sqrt(2), depth - 1); // p4
    drawLine(x - length / 2, y - length / 2, length / sqrt(2), depth - 1); // p5
    drawLine(x + length / 2, y - length / 2, length / sqrt(2), depth - 1); // p6
}

int main() {
    drawLine(4, 4, 4, 2);
    //std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
}

/*
p3(x-l/2, y+l/2)                                p4(x+length/2, y+length/2)
|                                               |
|p1(x-length/2, y)___(x,y)____(x+lenght/2, y) p2|
|                                               |
|                                               | 
p5 (x-l/2, y-l/2)                              p6(x+length/2, y-length/2)

*/