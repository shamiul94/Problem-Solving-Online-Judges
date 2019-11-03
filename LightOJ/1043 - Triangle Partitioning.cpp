#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define d 0.00000001

int main() {
    double AB, AC, BC, r;
    ll T, t = 0;

    scanf("%lld", &T);

    while (T--) {
        t++;
        scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &r);
//        cout << AB << " " << AC << " " << BC << " " << r << endl ;
        double s, ADE, ABC;
        s = 0.5 * (AB + AC + BC);
        ABC = sqrt(1.0 * s * (s - AB) * (s - AC) * (s - BC));

        double hi, lo, mid, AD, DE, AE, trap, R;

        hi = AB - d;
        lo = d;
        ll k = 0;
        while (hi - lo > d) {
            AD = (hi + lo) / 2.0; /// mid == AD
            DE = AD * 1.0 * BC / AB;
            AE = AD * 1.0 * AC / AB;
            s = 0.5 * (AD + DE + AE);
            ADE = sqrt(1.0 * s * (s - AD) * (s - DE) * (s - AE));
            trap = ABC - ADE;
            R = ADE * 1.0 / trap;

            if (R > r) {
                hi = AD;
//                cout << "hi " << hi << endl  ;
            } else {
                lo = AD;
//                cout << "lo " << lo << endl ;
            }
        }

        printf("Case %lld: %.11f\n", t, AD);

    }

    return 0;

}
 