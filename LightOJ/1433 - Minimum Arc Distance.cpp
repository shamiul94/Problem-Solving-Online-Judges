#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main() {
    int test, t = 0;
    double ox, oy, ax, ay, bx, by, halfsq, radiusq;
    double angle, radius, half, arc, rato;
    cin >> test;
    while (t < test) {
        cin >> ox >> oy >> ax >> ay >> bx >> by;
        radius = sqrt((ox - ax) * (ox - ax) * 1.0 + (oy - ay) * (oy - ay) * 1.0);
        half = sqrt((bx - ax) * (bx - ax) * 1.0 + (by - ay) * (by - ay)) / 2.0;
        angle = asin(half / radius);
        arc = radius * angle * 2.0;
        printf("Case %d: %lf\n", t + 1, arc);
        t++;
    }
    return 0;
}
 