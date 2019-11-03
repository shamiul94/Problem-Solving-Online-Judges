
// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000
using namespace std;
string s;
ll N;

ll dp[110][110];

ll pal(ll i, ll j) {
    if (i >= j) return dp[i][j] = 0;
    if (i >= N || j >= N) return dp[i][j] = 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == s[j]) return dp[i][j] = pal(i + 1, j - 1);
    else return dp[i][j] = 1 + min(pal(i + 1, j), pal(i, j - 1));
}


int main() {
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        m1(dp);
        t++;
        cin >> s;
        N = s.length();

        printf("Case %lld: %lld\n", t, pal(0, N - 1));
    }
    return 0;
}
 