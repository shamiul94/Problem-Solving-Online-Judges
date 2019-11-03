
// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define inf LLONG_MAX
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask) /// __builtin_popcount : it's a built in function of GCC. Finds out the numbers of 1 in binary representation.
#define mx 150000

using namespace std;


ll N, w, k, len;
vector<ll> v;
ll dp[102][102];

ll solve(ll pos, ll moves) {
    if (pos >= len) {
        return 0;
    }
    if (moves == 0) {
        return 0;
    }
    if (dp[pos][moves] != -1) {
        return dp[pos][moves];
    }

    ll t = 0, i;
    for (i = 0; i < v.size() - pos; i++) {
        if (abs(v[pos + i] - v[pos]) <= w) {
            t++;
        } else {
            break;
        }
    }

    return dp[pos][moves] = max(t + solve(pos + i, moves - 1), solve(pos + 1, moves));
}

int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        v.clear();
        m1(dp);
        t++;
        cin >> N >> w >> k;
        ll x, y;

        for (ll i = 0; i < N; i++) {
            cin >> x >> y;
            v.push_back(y);
        }

        sort(v.begin(), v.end());
        len = v.size();

        printf("Case %lld: ", t);
        cout << solve(0, k) << endl;
    }
    return 0;
}
 