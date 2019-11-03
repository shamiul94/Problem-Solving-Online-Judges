
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    int t = 0, test, ax, ay, bx, by, cx, cy, dx, dy;
    int area;
    cin >> test;
    while (t < test) {
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        dx = cx - (bx - ax);
        dy = ay + (cy - by);
        //area = abs(0.5*(17)-0.5*(13));
        //cout<<endl<< "RUMMAN"<< area << endl << endl ;
        area = abs(0.5 * (ax * by + bx * cy + cx * dy + dx * ay) - 0.5 * (ay * bx + by * cx + cy * dx + dy * ax));
        cout << "Case " << t + 1 << ": " << dx << " " << dy << " " << area << endl;
        t++;
    }
}
 