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

vector<ll> v;
ll len;

ll dp[40][2][2][70];

ll solve(ll pos, ll prevSmall, ll PrevBit, ll adjacent) {
    if (pos >= len) {
        return adjacent;
    }
    if (dp[pos][prevSmall][PrevBit][adjacent] != -1) {
        return dp[pos][prevSmall][PrevBit][adjacent];
    }

    ll bestPossible;

    bestPossible = (prevSmall) ? 1 : v[pos];

    ll ret = 0;

    for (ll i = 0; i <= bestPossible; i++) {
        ret += solve(pos + 1, prevSmall | (i < v[pos]), i, (i == PrevBit && i == 1) + adjacent);
    }

    return dp[pos][prevSmall][PrevBit][adjacent] = ret;

}

int main() {
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;

        m1(dp);
        v.clear();

        ll N;
        scanf("%lld", &N);

        while (N) {
            ll d;
            d = N % 2;
            v.push_back(d);
            N = N / 2;
        }
        len = v.size();
        reverse(v.begin(), v.end());


        printf("Case %lld: ", t);
        printf("%lld\n", solve(0, 0, 0, 0));
    }
    return 0;
}
