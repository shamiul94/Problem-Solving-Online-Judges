#include<iostream>
#include<vector>

using namespace std;

#define ll long long

ll dp[100] = {};

ll fact(ll n) {
    if (n == 1) {
        dp[1] = 1;
        return dp[1];
    }
    return dp[n] = n * fact(n - 1);
}

int main() {
    ll n, test, t = 0;
    cin >> test;
    vector<ll> vec;
    fact(20);
    dp[0] = 1;
//
//    for(int i = 1 ; i<=20 ; i++)
//    {
//        cout << dp[i] << " " ;
//    }
//    cout << endl ;

    while (test--) {
        t++;
        cin >> n;

        for (int i = 20; i >= 0; i--) {
            if (n >= dp[i]) {
                n -= dp[i];
                vec.push_back(i);
            }
        }
        cout << "Case " << t << ": ";

        if (n == 0) {
            for (int i = vec.size() - 1; i >= 0; i--) {
                if (i != 0) {
                    cout << vec[i] << "!+";
                } else {
                    cout << vec[i] << "!" << endl;
                }
            }
        } else {
            cout << "impossible" << endl;
        }

        vec.clear();

    }

    return 0;
}
 