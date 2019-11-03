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


ll dp[70][2][2][70];
ll len;
vector<ll> v;


ll solve(ll pos, ll prevSmall, ll isStart, ll zeroes) {
    if (pos >= len) {
        return zeroes;
    }

    if (dp[pos][prevSmall][isStart][zeroes] != -1) {
        return dp[pos][prevSmall][isStart][zeroes];
    }

    ll bestPossible;

    bestPossible = (prevSmall) ? 9 : v[pos];

    ll ret = 0;

    if (isStart) {
        for (ll i = 1; i <= bestPossible; i++) {
            ret += solve(pos + 1, prevSmall | (i < v[pos]), 0, (i == 0) + zeroes);
        }
        ret += solve(pos + 1, 1, 1, 0);  ///****
    } else {
        for (ll i = 0; i <= bestPossible; i++) {
            ret += solve(pos + 1, prevSmall | (i < v[pos]), 0, (i == 0) + zeroes);
        }
    }

    return dp[pos][prevSmall][isStart][zeroes] = ret;
}

ll calculate(ll a) {
    if (a < 0) {
        return 0;
    }
    if (a <= 9) {
        return 1;
    }

    v.clear();
    m1(dp);
    while (a) {
        ll b;
        b = a % 10;
        v.push_back(b);
        a = a / 10;
    }
    reverse(v.begin(), v.end());
    len = v.size();

    ll ans;

    ans = solve(0, 0, 1, 0) + 1;
    return ans;
}

int main() {
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;

        ll m, n;
        scanf("%lld %lld", &m, &n);

        ll ans;
        ans = calculate(n) - calculate(m - 1);

//        cout << calculate(n) << endl ;
//        cout << calculate(m) << endl ;

        printf("Case %lld: ", t);
        printf("%lld\n", ans);
    }

    return 0;
}
