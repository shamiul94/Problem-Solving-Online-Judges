#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define DEBUG printf("hi\n");
#define DEBUG2 printf("bi\n");
#define di 0.00000001

double L, N, C, Lnew, r;


using namespace std;

int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    double ans;
    scanf("%lld ", &T);

    while (T--) {
        t++;
        scanf("%lf %lf %lf", &L, &N, &C);
        Lnew = (1.0 + N * C) * L;

        r = L / 2.0;

        double hi, lo, mid, s = 0, per, halfang, ang;

        lo = r;
        hi = 100000;
        ll k = 0;

        if (L == Lnew) {
            ans = 0;
        } else {
            while (k < 66) {
                k++;
                mid = (lo + hi) / 2.0;
                per = sqrt(1.0 * mid * mid - r * r);
                ang = 2.0 * asin(r * 1.0 / mid);
                s = mid * ang;

                if (s > Lnew) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            ans = mid - per;

        }


        printf("Case %lld: %.10f\n", t, ans);

    }

    return 0;
}