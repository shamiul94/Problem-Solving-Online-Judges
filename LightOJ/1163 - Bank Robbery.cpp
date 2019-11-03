#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);
    while (T--) {
        t++;
        ll n;
        ll d, r, s;
        scanf("%lld", &n);
        d = n;

        s = 0;

        while (d / 10 > 0) {
            s = s + d;
            d = d / 10;
        }

        ll lo = s - 2000, hi = s + 2000;

        printf("Case %lld:", t);
        for (ll i = lo; i <= hi; i++) {
            if (i - i / 10 == n) {
                printf(" %lld", i);
            }
        }

        printf("\n");
    }
    return 0;
}