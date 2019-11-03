
// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000
#define palin true ;
using namespace std;
int pal[1010][1010] = {};
string s;
ll N;
ll dp[1010];


int isPalin(ll i, ll j) {
    if (i >= j) {
        return pal[i][j] = 1;
    }

    if (pal[i][j] != -1) {
        return pal[i][j];
    }

    if (s[i] == s[j]) {
        int t;
        t = isPalin(i + 1, j - 1);

        if (t == 1) {
            return pal[i][j] = 1;
        } else if (t == 0) {
            return pal[i][j] = 0;
        }
    } else {
        return pal[i][j] = 0;
    }
}


ll solve(ll start) {
    if (start >= N) {
        return 0;
    }

    if (dp[start] != -1) {
        return dp[start];
    }

    ll best = LLONG_MAX;

    for (ll i = start; i < N; i++) {
        if (isPalin(start, i) == 1) {
            best = min(best, 1 + solve(i + 1));
        }
    }
    return dp[start] = best;
}

int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);
    while (T--) {
        m1(pal);
        m1(dp);

        t++;
        cin >> s;
        N = s.size();

        printf("Case %lld: %lld\n", t, solve(0));
    }
    return 0;
}
 