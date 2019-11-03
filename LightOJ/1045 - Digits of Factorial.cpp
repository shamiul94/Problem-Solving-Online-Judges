#include<bits/stdc++.h>


using namespace std;
#define ll long long

int main() {
//    freopen("in.txt","r", stdin);
//
//    freopen("out.txt","w", stdout);

    vector<double> v;
    v.push_back(0);

    for (ll i = 1; i <= 1000000; i++) {
        double s;
        s = log10(i);
        v.push_back(s + v[i - 1]);
    }

    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        ll n, b;
        scanf("%lld %lld", &n, &b);

        double d = 0;

        ll ans;

        if (n == 0) {
            ans = 1;
        } else {
            ans = (v[n] / log10(b)) * 1.0;
            ans++;
        }

        printf("Case %lld: %lld\n", t + 1, ans);

        t++;
    }
    return 0;
}
 