
/**
@author - Rumman BUET CSE'15
problem -
 
concept -
*/


#include<bits/stdc++.h>

#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define DEBUG printf("hi\n");
#define DEBUG2 printf("bi\n");
#define pi acos(-1)
#define m 100000007
#define d 0.000000001
#define Min(a, b, c) min( a , min(b,c) )

using namespace std;

ll rgb[25][4];
ll dp[25][25];
ll n;

ll func(ll i, ll j) {
    if (i >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (j == 0) {
        dp[i][j] = min(rgb[i][j] + func(i + 1, j + 1), rgb[i][j] + func(i + 1, j + 2));
        return dp[i][j];
    } else if (j == 1) {
        dp[i][j] = min(rgb[i][j] + func(i + 1, j - 1), rgb[i][j] + func(i + 1, j + 1));
        return dp[i][j];
    } else if (j == 2) {
        dp[i][j] = min(rgb[i][j] + func(i + 1, j - 1), rgb[i][j] + func(i + 1, j - 2));
        return dp[i][j];
    }
}

int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        memset(dp, -1, sizeof(dp));
        memset(rgb, 0, sizeof(rgb));
        t++;
        scanf("%lld", &n);

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < 3; j++) {
                scanf("%lld", &rgb[i][j]);
            }
        }

        ll ans;
        ans = Min(func(0, 0), func(0, 1), func(0, 2));

        printf("Case %lld: %lld\n", t, ans);
    }
}