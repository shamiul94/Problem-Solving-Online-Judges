#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define DEBUG printf("hi\n");
#define DEBUG2 printf("bi\n");
#define pi acos(-1)
#define d 0.000000001

using namespace std;


ll ar[200][200];
ll N;
vector<ll> v[1200];

ll dp(ll i, ll j) {
    if (i > 2 * N - 2 || j < 0 || j >= v[i].size()) {
        return 0;
    }

    if (ar[i][j] != -1) return ar[i][j];


    if (i < N - 1) {
        return ar[i][j] = max(v[i][j] + dp(i + 1, j), v[i][j] + dp(i + 1, j + 1));
    } else {
        return ar[i][j] = max(v[i][j] + dp(i + 1, j - 1), v[i][j] + dp(i + 1, j));
    }
}

int main() {
//    fi ;
//    fo ;
    ll T, t = 0, a;
    scanf("%lld", &T);
    while (T--) {
        memset(ar, -1, sizeof(ar));
        t++;

        scanf("%lld", &N);

        for (ll i = 0; i < 1200; i++) {
            v[i].clear();
        }

        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j <= i; j++) {
                scanf("%lld", &a);
                v[i].push_back(a);
            }
        }

        for (ll i = 1; i <= N - 1; i++) {
            for (ll j = 0; j < N - i; j++) {
                scanf("%lld", &a);
                v[N + i - 1].push_back(a);
            }
        }

        ll ans;
        ans = dp(0, 0);
//        cout << t << " " << N << endl ;
        printf("Case %lld: %lld\n", t, ans);

    }
    return 0;
}