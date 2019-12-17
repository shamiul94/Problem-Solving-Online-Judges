//
// Created by shamiul93 on 12/17/19.
//


#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

#define pii pair<ll, ll>
#define ll long long
using namespace std;

int main() {
//    fi;
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        if (t < 15) {
            cout << "NO" << endl;
        } else {
            bool yes = false;
            for (ll j = 15; j <= 20; j++) {
                ll tem = t - j;
                if (tem % 14 == 0) {
                    cout << "YES" << endl;
                    yes = true;
                    break;
                }
            }
            if (!yes) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}