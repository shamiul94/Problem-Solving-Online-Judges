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


#define FOR(i, L, U) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD(i, U, L) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))


#define SQR(a)                                  ((a)*(a))
#define QUBE(a)                                 ((a)*(a)*(a))

#define scanI(a)                                scanf("%d",&a)
#define scanI2(a, b)                             scanI(a) , scanI(b)
#define scanI3(a, b, c)                           scanI(a), scanI(b), scanI(c)
#define scanI4(a, b, c, d)                         scanI(a), scanI(b), scanI(c), scanI(d)

#define scanLL(a)                                scanf("%lld",&a)
#define scanLL2(a, b)                             scanLL(a) , scanLL(b)
#define scanLL3(a, b, c)                           scanLL(a), scanLL(b), scanLL(c)
#define scanLL4(a, b, c, d)                         scanLL(a), scanLL(b), scanLL(c), scanLL(d)

#define inf LLONG_MAX
#define minf LLONG_MIN
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

using namespace std;


map<pii, ll> M;

ll w1[30009], w[30009];
ll N;

vector<ll> v[30010];
ll farth1, farth2;

bool vis[30010] = {};

ll bfs(ll s) {
    ll maxi = -10;
    m0(vis);
    m0(w);
    ll source;
    source = s;

    queue<ll> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty()) {
        ll u;
        u = q.front();
        q.pop();

        for (ll i = 0; i < v[u].size(); i++) {
            ll curr;
            curr = v[u][i];

            if (!vis[curr]) {
                vis[curr] = true;
                w[curr] = w[u] + M[make_pair(u, curr)];
                q.push(curr);
            }
        }
    }

    ll md = -1;

//    cout << "baabgjyyjaaaal" << endl ;
    for (ll i = 0; i < N; i++) {
        if (md < w[i]) {
            md = w[i];
//            cout << i << " " << w[i] << endl  ;
            farth1 = i;
        }
    }
//    cout << "challljsd" << endl ;

    return farth1;
}


ll bfs2(ll f) {
    m0(vis);
    m0(w1);

    ll source;
    source = f;

    queue<ll> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty()) {
        ll u;
        u = q.front();
        q.pop();

        for (ll i = 0; i < v[u].size(); i++) {
            ll curr;
            curr = v[u][i];

            if (!vis[curr]) {
                vis[curr] = true;
                w1[curr] = w1[u] + M[make_pair(u, curr)];
                q.push(curr);
            }
        }
    }

//    cout << "ygtairf" << endl ;
    ll md = -1;
    for (ll i = 0; i < N; i++) {
        if (md < w1[i]) {
            md = w1[i];
//            cout << i << " " << w1[i] << endl  ;
            farth2 = i;
        }
    }

//    cout << "iuhsiur" << endl ;
    return farth2;
}


int main() {
//    fi ;
//    fo ;

    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;

        scanLL(N);

        for (ll i = 0; i < N - 1; i++) {
            ll a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            v[a].push_back(b);
            v[b].push_back(a);

            pii p;
            p = make_pair(a, b);
            M[p] = c;
            p = make_pair(b, a);
            M[p] = c;
        }

        ll fr1, fr2;

        fr1 = bfs(0);
        fr2 = bfs(fr1);
//cout << "FR@@@@@@@2 : " << fr2 << endl ;
        bfs2(fr2);


        printf("Case %lld:\n", t);

//        cout << "fr:   " << fr1 << " " << fr2 << endl ;

        for (ll i = 0; i < N; i++) {
            printf("%lld\n", max(w1[i], w[i]));

//cout << w1[i] << " " << w[i] << endl ;
        }

        for (ll i = 0; i < 30009; i++) {
            v[i].clear();
        }
        m0(vis);
        M.clear();
    }

    return 0;
}
