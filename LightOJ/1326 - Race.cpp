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

ll N;
ll dp[1005];
ll combination[1005][1005];

ll comb() {
    for (ll i = 0; i < 1005; i++) {
        combination[i][0] = 1;
        combination[i][i] = 1;
        combination[i][1] = i;
    }

    for (ll n = 3; n < 1005; n++) {
        for (ll r = 2; r < n; r++) {
            combination[n][r] = (combination[n - 1][r] % mod + combination[n - 1][r - 1] % mod) % mod;
        }
    }
}


//ll solve(ll pos, ll remaining)
//{
//    if(pos == N) return 1 ;
//    if(remaining == 0) return 1 ;
//
//    if(dp[remaining] != -1) return dp[remaining] ;
//
//    ll ans1, ans = 0 ;
//
//    for(ll myUse = remaining ; myUse >= 1 ; myUse--)
//    {
//        ll next = remaining - myUse ;
//
//        ans1 = ( (combination[remaining][myUse]) * (solve(pos+1, next) % mod) )  % mod ;
//
//        ans = (ans % mod + ans1 % mod) % mod;
//    }
//
//    return dp[remaining] = ans ;
//}



ll solve(ll remaining) {
    if (remaining == 0)
        return 1;

    if (dp[remaining] != -1)
        return dp[remaining];

    ll ans1, ans = 0;


    for (ll myUse = 1; myUse <= remaining; myUse++) {
        ll next = remaining - myUse;

        ans1 = ((combination[remaining][myUse]) * (solve(next) % mod)) % mod;

        ans = (ans % mod + ans1 % mod) % mod;
    }

    return dp[remaining] = ans;
}

int main() {
//    fi;
//    fo;
    m1(combination);
    comb();
    ll T, t = 0;
    scanf("%lld", &T);

    m1(dp);

    while (T--) {
        t++;
        cin >> N;
        printf("Case %lld: ", t);
        ll ans;
        ans = solve(N);
        cout << ans << endl;
    }
    return 0;
}




/*

3
1
2
3

*/
