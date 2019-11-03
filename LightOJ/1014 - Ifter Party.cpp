#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<cstdlib>

using namespace std;
#define ll long long

int main() {
//    freopen("out.txt","w", stdout);
    vector<ll> v;
    ll t, p, l, k = 0;
    cin >> t;
    while (t--) {
        cin >> p >> l;
        ll b;
        b = p - l;
        k++;
        cout << "Case " << k << ": ";
        if (!p && !l) {
            cout << "1";
        } else if (b < l) {
            cout << "impossible";
        } else {
            int u = 0;
            for (ll i = 1; i * i <= b; i++) {
                if (b % i == 0) {
                    if (i != b / i) {
                        v.push_back(i);
                        v.push_back(b / i);
                    } else
                        v.push_back(i);
                }
            }

            sort(v.begin(), v.end());


            for (ll i = 0; i < v.size(); i++) {
                if (v[i] > l) {
                    u = 1;
                    cout << v[i];
                    if (i != v.size() - 1) {
                        cout << " ";
                    }
                }
            }
            if (u == 0) {
                cout << "impossible";
            }
        }
        cout << endl;
        v.clear();
    }


    return 0;
}