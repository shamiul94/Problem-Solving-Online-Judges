#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    double w, l, x;
    int test, t = 0;
    cin >> test;

    while (test--) {
        scanf("%lf %lf", &l, &w);
        double x11, x22, vol, x1, x2;

        x1 = ((l + w) + sqrt((l + w) * (l + w) - 3.0 * w * l)) / 6.0;
        x2 = ((l + w) - sqrt((l + w) * (l + w) - 3.0 * w * l)) / 6.0;

        x11 = 24.0 * x1 - 4.0 * l - 4, 0 * w;
        x22 = 24.0 * x2 - 4.0 * l - 4.0 * w;

        x = x22 < 0 ? x2 : x1;


        vol = (l - 2.0 * x) * (w - 2.0 * x) * x;

        printf("Case %d: %.15lf\n", t + 1, vol);
        t++;
    }

    return 0;
}