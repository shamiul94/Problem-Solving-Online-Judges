#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

int main() {
    int time, t = 0;
    double r1, r2, r3, s;
    cin >> time;
    while (time--) {
        t++;
        cin >> r1 >> r2 >> r3;

        double a, b, c;

        a = (r1 + r2) * 1.0;
        b = (r2 + r3) * 1.0;
        c = (r3 + r1) * 1.0;

        double A, B, C, s, tot;

        s = (a + b + c) / 2.0;

        tot = sqrt(s * (s - a) * (s - b) * (s - c) * 1.0);

        A = acos((b * b + c * c - a * a) / (2.0 * b * c));
        B = acos((c * c + a * a - b * b) / (2.0 * c * a));
        C = acos((a * a + b * b - c * c) / (2.0 * a * b));

        double aar, bar, car, ans;
        aar = 0.5 * r3 * r3 * A;
        bar = 0.5 * r1 * r1 * B;
        car = 0.5 * r2 * r2 * C;


        ans = tot - ((aar + bar + car) * 1.0);


        printf("Case %d: %.15f\n", t, ans);

    }

    return 0;

}