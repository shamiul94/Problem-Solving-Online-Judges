
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

ll N, W, remWeight;
ll price[110], compulsory[110], weight[110];

ll dp[101][10001];


ll solve(ll pos, ll takenWeight) {
    if (pos >= N) return 0;
    if (dp[pos][takenWeight] != -1) return dp[pos][takenWeight];

    ll profit1 = 0;
    ll profit2 = 0;
    ll profit3 = 0;

    if (takenWeight + weight[pos] <= remWeight) {
        profit1 = price[pos] + solve(pos, takenWeight + weight[pos]);
        profit2 = price[pos] + solve(pos + 1, takenWeight + weight[pos]);
    }

    profit3 = solve(pos + 1, takenWeight);

    dp[pos][takenWeight] = max3(profit1, profit2, profit3);
    return dp[pos][takenWeight];
}

int main() {

    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;

        scanf("%lld %lld", &N, &W);

        m1(dp);

        ll n = 0, w = 0;
        while (n < N) {
            scanf("%lld %lld %lld", &price[n], &compulsory[n], &weight[n]);
            w += (weight[n] * compulsory[n]);
            n++;
        }

        printf("Case %lld: ", t);

        if (w > W) {
            printf("Impossible\n");
        } else {
            remWeight = W - w;
            ll ans = solve(0, 0);
            printf("%lld\n", ans);
        }
    }
    return 0;
}