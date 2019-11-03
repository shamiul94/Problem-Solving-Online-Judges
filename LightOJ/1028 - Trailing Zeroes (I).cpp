#include <bits/stdc++.h>

#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

#define sz 1000010

vector<ll> v;

int main() {
//    fi;
//    fo;

    bool arr[1000010] = {};
//    cout << "hi" << endl ;
    memset(arr, true, sizeof(arr));
    arr[0] = false;
    arr[1] = false;


    v.push_back(2);

    for (ll i = 3; i < sz; i += 2) {
        if (arr[i] == true) {
            v.push_back(i);
            for (ll j = 2 * i; j < sz; j += i) {
                arr[j] = false;
            }
        }
    }

    ll T, t = 0;

    scanf("%lld", &T);

    while (T--) {
        t++;
        ll n;
        scanf("%lld", &n);

        ll a = n;
        ll ans = 1;
        for (ll i = 0; i < v.size(), a > 1, v[i] * v[i] <= a; i++) {

            ll oc = 0;

            ll r = 0;
            while (r == 0 && a > 1) {
                r = a % v[i];

                if (r == 0) {
                    oc++;
                    a = a / v[i];
                }

            }
            if (oc > 0) {
                ans = ans * (oc + 1);
            }
        }


        if (a > 1) {
            ans *= (1 + 1);
        }


        printf("Case %lld: %lld\n", t, ans - 1);

    }

    return 0;
}
 
 