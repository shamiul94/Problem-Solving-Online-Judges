#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, i;
    double pi = acos(-1);
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        double r;
        scanf("%lf", &r);
        double a, b;
        a = pi * r * r;
        b = 4 * r * r;
        printf("Case %d: %.2f\n", i, b - a);
    }
    return 0;
}