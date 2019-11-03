#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

#define ll long long

ll k, n, m;
vector<ll> vp;
vector<ll> vec[1010];


ll bfs() {
    int reached[1010];

    memset(reached, 0, sizeof(reached));

    for (ll i = 0; i < k; i++) {
        int vis[1010] = {};
        ll src;
        queue<ll> q;
        src = vp[i];
        q.push(src);
        vis[src] = 1;
        reached[src]++;

        while (!q.empty()) {
            ll node;
            node = q.front();
            q.pop();

            for (ll i = 0; i < vec[node].size(); i++) {
                ll now;
                now = vec[node][i];

                if (vis[now] == 0) {
                    vis[now] = 1;
                    reached[now]++;
                    q.push(now);
                }
            }
        }

    }

    ll tem = 0;
    for (ll i = 0; i < 1001; i++) {
//        cout << reached[i] << " ";
        if (reached[i] == k) {
            tem++;
        }

    }
//    cout << endl ;

    return tem;
}


int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w" , stdout);
    ll T, t = 0, a;
    cin >> T;

    ll ans;
    while (T--) {
        t++;
        cin >> k >> n >> m;
        for (ll i = 0; i < k; i++) {
            cin >> a;
            vp.push_back(a);
        }

        for (ll i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            vec[u].push_back(v);
        }


        ans = bfs();

        printf("Case %lld: %lld\n", t, ans);

        vp.clear();
        for (ll i = 0; i < 1010; i++) {
            vec[i].clear();
        }
    }

    return 0;
}