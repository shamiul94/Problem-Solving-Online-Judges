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
#define mod 10056

using namespace std;

ll N, K, Max;
ll dp[60][60][60];


ll solve(ll n, ll k, ll M) {
    if (n == 0 && k == 0) return 1;
    if (n <= 0 || k <= 0) return 0;

    if (dp[n][k][M] != -1) return dp[n][k][M];

    ll ans = 0;

    for (ll i = 1; i <= M; i++) {
        ans += solve(n - i, k - 1, M);
    }

    dp[n][k][M] = ans;
    return dp[n][k][M];

}

int main() {
//    fi;
//    fo;
    m1(dp);
    ll T, t = 0;
    scanf("%lld", &T);
    while (T--) {
        t++;
        scanf("%lld %lld %lld", &N, &K, &Max);
        printf("Case %lld: ", t);

        ll ans;
        ans = solve(N, K, Max);
        printf("%lld\n", ans);
    }
    return 0;
}
