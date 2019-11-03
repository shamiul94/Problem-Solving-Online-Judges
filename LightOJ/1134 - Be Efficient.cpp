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


using namespace std;

ll N, M;
ll arr[100009] = {};

ll cumsum[100002];
map<ll, ll> Map;

int main() {
//    fi;
//    fo ;

    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;

        m0(cumsum);
        scanf("%lld %lld", &N, &M);

        for (ll i = 0; i < N; i++) {
            scanf("%lld", &arr[i]);
        }

        ll ans = 0;
        cumsum[0] = arr[0] % M;
        for (ll i = 0; i < N; i++) {
            cumsum[i] = (cumsum[i - 1] % M + arr[i] % M) % M;

            if (cumsum[i] == 0) {
                ans++;
            }

            if (Map.find(cumsum[i]) == Map.end()) {
                Map[cumsum[i]] = 1;
            } else {
                Map[cumsum[i]]++;
            }
        }

        map<ll, ll>::iterator it;

        for (it = Map.begin(); it != Map.end(); it++) {
            ll a, b;
            a = it->first;
            b = it->second;

            ans += (b * (b - 1) / 2);
        }


        printf("Case %lld: %lld\n", t, ans);
        Map.clear();
    }
    return 0;
}
