//
// Created by shamiul93 on 6/19/19.

//https://www.codechef.com/problems/CHFPARTY
//

#include "bits/stdc++.h"

#define ll long long

using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    ll T;
    cin >> T;

    while (T--) {
        vector<ll> v;
        ll N;
        cin >> N;
        for (ll i = 0; i < N; i++) {
            ll a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());


        ll tillNowGuests = 0;
        for (ll i = 0; i < v.size(); i++) {
            if (v[i] <= tillNowGuests) {
                tillNowGuests++;
            } else {
                break;
            }
        }
        cout << tillNowGuests << endl ;
    }

}