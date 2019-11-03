#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>

using namespace std;

#define ll long long int

ll BFS() {
    ll u, v, n, t = 0;
    cin >> n;
    queue<ll> q;
    vector<ll> vc[100007];
    int race[100007] = {};
    ll vam = 0, lyk = 0;

    while (t < n) {
        cin >> u >> v;
        vc[u].push_back(v);
        vc[v].push_back(u);
        t++;
    }
    ll ans = 0;

    for (ll idx = 1; idx < 100007; idx++) {
        if (vc[idx].size() != 0 && race[idx] == 0) {
            vam = 0;
            lyk = 0;
            race[idx] = 1;
            vam++;
            q.push(idx);
            while (!q.empty()) {
                ll node;
                node = q.front();
                q.pop();

                for (ll i = 0; i < vc[node].size(); i++) {
                    if (race[vc[node][i]] == 0) {
                        if (race[node] == 1) {
                            race[vc[node][i]] = 2;
                            lyk++;
                        } else if (race[node] == 2) {
                            race[vc[node][i]] = 1;
                            vam++;
                        }
                        q.push(vc[node][i]);
                    }
                }
            }
            ans += max(vam, lyk);
        }
    }

    return ans;
}

int main() {
//    freopen("out.txt","w", stdout);
    int T, t = 0;
    cin >> T;
    ll ans;

    while (T--) {
        ans = BFS();
        printf("Case %d: %lld\n", t + 1, ans);
        t++;
    }
    return 0;
}