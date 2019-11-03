// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

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

#define inf LLONG_MAX
#define minf LLONG_MIN
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

#include<string.h>

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

ll N, Q, D, M;
ll dp[201][11][21]; /// n , d , m
vector<ll> v, u;

ll solve(ll n, ll m, ll prevSum) {
    if (n > N) return 0;
    if (m > M) return 0;

    if (m == M) {
        if ((prevSum % D) == 0) return 1;
        else return 0;
    }

    if (dp[n][m][prevSum] != -1) return dp[n][m][prevSum];

    ll ret = 0;

    ret = solve(n + 1, m, prevSum) + solve(n + 1, m + 1, (prevSum % D + u[n] % D) % D);

    return dp[n][m][prevSum] = ret;
}


int main() {
//    fi ;
//    fo ;

    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        m1(dp);
        t++;
        scanf("%lld %lld", &N, &Q);

        for (ll i = 0; i < N; i++) {
            ll a;
            scanf("%lld", &a);
            v.push_back(a);
        }

        printf("Case %lld:\n", t);

        while (Q--) {
            m1(dp);
            scanf("%lld %lld", &D, &M);

            u = v;

            for (ll i = 0; i < u.size(); i++) {
                u[i] = u[i] % D;

                if (u[i] < 0) {
                    u[i] = (u[i] + D) % D;
                }
            }

            ll ans = 0;

            ans = solve(0, 0, 0);

            printf("%lld\n", ans);
            u.clear();
        }
        v.clear();
    }

    return 0;
}
