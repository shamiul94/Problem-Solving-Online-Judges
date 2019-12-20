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
    fi;
//    fo;
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll r, c;

    cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> row;
    vector<ll> colm;

    if (r <= c) {
        for (ll i = 1; i <= r; i++) {
            row.push_back(i);
        }

        for (ll i = r + 1; i <= r + c; i++) {
            colm.push_back(i);
        }
    } else {
        for (ll i = 1; i <= c; i++) {
            colm.push_back(i);
        }

        for (ll i = c + 1; i <= c + r; i++) {
            row.push_back(i);
        }
    }


    for (ll i = 0; i < row.size(); i++) {
        for (ll j = 0; j < colm.size(); j++) {
            cout << row[i] * colm[j] << " ";
        }
        cout << endl;
    }
    return 0;
}