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

ll m, n;
ll arr[20] = {};
ll dp[20][20][20] = {};

//ll m , n ;

ll solve(ll pos, ll digitTillNow, ll prevDigit) {


    if (digitTillNow > n) return 0;

    if (abs(arr[pos] - prevDigit) > 2) return 0;
    if (digitTillNow == n && abs(arr[pos] - prevDigit) <= 2) return 1;

    if (dp[pos][digitTillNow][prevDigit] != -1) return dp[pos][digitTillNow][prevDigit];


    ll ret = 0;

    for (ll i = 0; i < m; i++) {
        ret += solve(i, digitTillNow + 1, arr[pos]);
    }

    return dp[pos][digitTillNow][prevDigit] = ret;
}

int main() {
//    fi ;
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;
        m1(dp);

        scanf("%lld %lld", &m, &n);

        for (ll i = 0; i < m; i++) {
            scanf("%lld", &arr[i]);
        }

        ll ans = 0;

        for (ll i = 0; i < m; i++) {
            m1(dp);
            ans += solve(i, 1, arr[i]);
        }

//        ll ans = solve(0 , 0 , arr[0]) ;

        printf("Case %lld: ", t);
        printf("%lld\n", ans);
    }
    return 0;
}