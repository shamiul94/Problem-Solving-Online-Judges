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

ll a, b, k, len;
ll dp[70][2][70][70];
bool vis[70][2][70][70];

vector<ll> v;

ll solve(ll pos, ll prevSmall, ll numRem, ll remDigit) {
    if (pos >= len) {
        if (numRem == 0 && remDigit == 0) {
            vis[pos][prevSmall][numRem][remDigit] = true;
            return dp[pos][prevSmall][numRem][remDigit] = 1;
        } else {
            vis[pos][prevSmall][numRem][remDigit] = true;
            return dp[pos][prevSmall][numRem][remDigit] = 0;
        }
    }
    if (vis[pos][prevSmall][numRem][remDigit]) {
        return dp[pos][prevSmall][numRem][remDigit];
    }

    ll ret = 0;

    ll bestPossible;
    bestPossible = (prevSmall) ? 9 : v[pos];

    for (ll i = 0; i <= bestPossible; i++) {
        ret += solve(pos + 1, prevSmall | (i < v[pos]), (numRem * 10 + i) % k, (remDigit + i) % k);
    }

    vis[pos][prevSmall][numRem][remDigit] = true;
    return dp[pos][prevSmall][numRem][remDigit] = ret;
}

ll calc(ll N) {
    if (k > 90) return 0;
    for (ll i = 0; i < 70; i++) {
        for (ll j = 0; j < 2; j++) {
            for (ll k = 0; k < 70; k++) {
                for (ll l = 0; l < 70; l++) {
                    vis[i][j][k][l] = false;
                }
            }
        }
    }

    v.clear();

    while (N) {
        ll d;
        d = N % 10;
        v.push_back(d);
        N = N / 10;
    }
    len = v.size();
    reverse(v.begin(), v.end());

    return solve(0, 0, 0, 0);
}

int main() {
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;

        scanf("%lld %lld %lld", &a, &b, &k);

        ll ans;
        ans = calc(b) - calc(a - 1);


        printf("Case %lld: ", t);
        printf("%lld\n", ans);
    }
    return 0;
}
