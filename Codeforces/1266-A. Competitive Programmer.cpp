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
        string s;
        cin >> s;
        int sum = 0;

        int len = static_cast<int>(s.size());

        bool hasZ = false;

        for (int j = 0; j < len; j++) {
            if (s[j] == '0') {
                s[j] = '#';
                hasZ = true;
                break;
            }
        }

        bool hasEven = false;
        for (int k = 0; k < len; k++) {
            if (s[k] != '#') {
                sum += (s[k] - '0');
            }
            if (s[k] == '0' || s[k] == '2' || s[k] == '4' || s[k] == '6' || s[k] == '8') {
                hasEven = true;
            }
        }


        if (hasZ && hasEven && sum % 3 == 0) {
            cout << "red" << endl;
        } else {
            cout << "cyan" << endl;
        }
    }
    return 0;
}