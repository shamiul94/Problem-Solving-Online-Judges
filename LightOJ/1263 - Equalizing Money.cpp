/*
@author - Rumman BUET CSE'15
*/

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

#define Black 1
#define White 2
#define Grey 3

using namespace std;

vector<ll> v[1002];
ll money[1002];
ll edgeNo, nodeNo;

ll color[1002];
ll K;

ll dfsUtil(ll u) {
//    cout << "u: " << u << endl ;
    color[u] = Black;
    bool isLeft = false;

    ll ret = 0;

    for (ll i = 0; i < v[u].size(); i++) {
        if (color[v[u][i]] == White) {
            isLeft = true;
            ret += dfsUtil(v[u][i]);
            K++;
        }
    }
    ret += money[u];

    color[u] = Black;

    return ret;
}


void dfs() {
    for (ll i = 0; i < 1002; i++) {
        color[i] = White;
    }

    ll sum = 0, ans = -1;

    for (ll i = 1; i <= nodeNo; i++) {
        if (color[i] == White) {
            K = 0;
            sum = dfsUtil(i);

            K++;
//            cout <<sum << "    " <<  K << endl ;

            if (sum % K == 0) {
                if (i == 1) {
                    ans = sum / K;
                } else {
                    ll t;
                    t = sum / K;
                    if (t != ans) {
                        cout << "No" << endl;
                        return;
                    }
                }
            } else {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}


int main() {
//    fi ;
//    fo ;

    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;

        sll2(nodeNo, edgeNo);

        for (ll i = 1; i <= nodeNo; i++) {
            sll(money[i]);
        }

        for (ll i = 0; i < edgeNo; i++) {
            ll u, w;
            sll2(u, w);
            v[u].pb(w);
            v[w].pb(u);
        }

        printf("Case %lld: ", t);

        dfs();

        for (ll i = 0; i < 1002; i++) {
            v[i].clear();
        }
    }

    return 0;
}

