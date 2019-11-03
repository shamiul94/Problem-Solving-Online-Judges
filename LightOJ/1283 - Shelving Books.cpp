/*
*@author - Rumman BUET CSE'15
Problem - 1283 - Shelving Books
Idea -  DP
*/
#include <bits/stdc++.h>
#include <vector>

#define ll                                      long long int
#define ull                                     unsigned long long
#define ld                                      long double

#define ff                                      first
#define ss                                      second

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define pi acos(-1.0)
#define debug                                   printf("yes\n")
#define what_is(x)                              cout << #x << " is " << x << endl
#define pf                                      printf
#define sf                                      scanf

#define pb                                      push_back
#define mp                                      make_pair
#define eb                                      emplace_back
#define pii                                     pair<int, int>
#define piii                                    pair<pii, int>

#define SQR(a)                                  ((a)*(a))
#define QUBE(a)                                 ((a)*(a)*(a))

#define scanI(a)                                scanf("%d",&a)
#define scanI2(a, b)                             scanI(a) , scanI(b)
#define scanI3(a, b, c)                           scanI(a), scanI(b), scanI(c)
#define scanI4(a, b, c, d)                         scanI(a), scanI(b), scanI(c), scanI(d)

#define sll(a)                                scanf("%lld",&a)
#define sll2(a, b)                             sll(a) , sll(b)
#define sll3(a, b, c)                           sll(a), sll(b), sll(c)
#define sll4(a, b, c, d)                         sll(a), sll(b), sll(c), sll(d)

#define pcase(t)                              printf("Case %lld: ",t);
#define pll(a)                                printf("%lld\n",a);
#define pll2(a, b)                             printf("%lld %lld\n",a,b);
#define pll3(a, b, c)                           printf("%lld %lld %lld\n",a,b,c);
#define pll4(a, b, c, d)                         printf("%lld %lld %lld %lld\n",a,b,c,d);

#define inf LLONG_MAX
#define minf LLONG_MIN
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

using namespace std;

ll BigMod(ll B, ll P, ll M) {
    ll R = 1;
    while (P > 0) {
        if (P % 2 == 1) {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}

int Set(int N, int pos) {
    return N = N | (1 << pos);
}

int reset(int N, int pos) {
    return N = N & ~(1 << pos);
}

bool check(int N, int pos) {
    return (bool) (N & (1 << pos));
}

/************************************** END OF INITIALS ****************************************/

ll N;
ll height[105];
ll dp[105][105][105];

ll solve(ll pos, ll left, ll right) {
    if (pos >= N) return 0;
    if (dp[pos][left][right] != -1) return dp[pos][left][right];

    ll ans = 0;
    if (height[pos] >= height[left] && height[pos] <= height[right]) {
        ans = max3(ans, 1 + solve(pos + 1, pos, right), 1 + solve(pos + 1, left, pos));
    }

    ans = max(ans, solve(pos + 1, left, right));

    return dp[pos][left][right] = ans;
}

int main() {
//    fi;
//    fo;
    ll T, t = 0;
    sll(T);

    height[103] = minf;
    height[104] = inf;

    while (T--) {
        t++;
        m1(dp);

        sll(N);
        for (ll i = 0; i < N; i++) {
            sll(height[i]);
        }

        ll ans = solve(0, 103, 104);

        pcase(t);
        pll(ans);
    }

    return 0;
}