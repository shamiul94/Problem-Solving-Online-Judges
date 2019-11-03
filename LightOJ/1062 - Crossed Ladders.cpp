#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define d 0.000000001
#define isprime false

double a, b, c, p, q, w;

double formula() {
    double t1, t2, C;
    t1 = acos(w * 1.0 / a);
    p = a * sin(t1);

    t2 = acos(w * 1.0 / b);
    q = b * sin(t2);

    C = 1.0 / ((1.0 / p) + (1.0 / q));
    return C;
}

int main() {
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;
        scanf("%lf %lf %lf", &a, &b, &c);

        double hi, lo, h;

        lo = d;
        hi = a + b - d;

        while (hi - lo > d) {
            w = (lo + hi) / 2.0;
            h = formula();

            if (h > c) {
                lo = w;
            } else {
                hi = w;
            }
        }

        printf("Case %lld: %.10f\n", t, w);

    }

    return 0;
}
 