/**
@author - Rumman BUET CSE'15
Problem - 1231 - Coin Change (I)

Concept -

    DP. Coin Change.

    ** I solved this with recursion + loop.
    ** It consumes less memory. And very efficient.
    ** It's my first problem on Limited coin change.

    # Here we are running the recursion till Atmost[i] times. This helps us to find
    out how many ways we can make the target amount.
    # We use  -  rec( i+1 , n-coinValue[i]*k )
    # Look , when the value of k is '0' , then it becomes rec( i+1 , n ) - remember something?
    # Yes. When we don't take i th element , and take the i+1 th element.
    # But if we take the i th one, then to take i+1 th , the n will be reduced.
    # So , now we can get the result by recursion.
    # it takes less memory than 3 state dp.
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

using namespace std;

ll N, K;
ll CoinValue[100];
ll AtMost[100];
int dp[51][1011];


int rec(ll i, ll n)   /// i == index , n == requirement theke komte komte koto hoise...
{

    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if (i >= N && n > 0) {
        return 0;
    }


    if (dp[i][n] != -1)
        return dp[i][n];

    int res = 0;
    for (ll k = 0; k <= AtMost[i]; k++) {
        res = (res % m + rec(i + 1, n - CoinValue[i] * k) % m) % m;
    }


    dp[i][n] = res;
    return dp[i][n];

}

int main() {
//    fi ;
//    fo ;

    ll T, t = 0;
    scanf("%lld", &T);
    while (T--) {

        memset(dp, -1, sizeof(dp));
        t++;

        scanf("%lld %lld", &N, &K);

        for (ll i = 0; i < N; i++) {
            scanf("%lld", &CoinValue[i]);
        }
        for (ll i = 0; i < N; i++) {
            scanf("%lld", &AtMost[i]);
        }

        ll ans;
        ans = rec(0, K);

        printf("Case %lld: %lld\n", t, ans);
    }

    return 0;
}
