// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define ull                                     unsigned long long
#define ld                                      long double

#define ff                                      first
#define ss                                      second

#define pll pair<ll,ll>

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

char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                   'U', 'V', 'W', 'X', 'Y', 'Z'};

char arr[20][20];
bool vis[20][20] = {};
ll dist[20][20];
ll N, K;


ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, -1, 1};

ll sum = 0;

ll bfs(pll strt, char target) {
    ll k, ans = 0;
    queue<pll > q;
    pll p;
    p = strt;
    k = 0;

    vis[p.first][p.second] = true;

    q.push(p);

    while (!q.empty()) {
        pll u;
        u = q.front();
        q.pop();

        for (ll i = 0; i < 4; i++) {
            ll newX, newY;
            newX = u.first + dx[i];
            newY = u.second + dy[i];


            if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
                if (arr[newX][newY] != '#' && vis[newX][newY] == false) {
                    if (arr[newX][newY] == target) {
                        arr[newX][newY] = '.';
                        dist[newX][newY] = dist[u.first][u.second] + 1;
                        return dist[newX][newY];
                    } else if (arr[newX][newY] == '.') {
                        dist[newX][newY] = dist[u.first][u.second] + 1;
                        vis[newX][newY] = true;
                        q.push(make_pair(newX, newY));
                    }
                }
            }
        }
    }
    return -1;
}


map<char, pll > M;

int main() {
//    fi ;
//    fo ;

    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        M.clear();

        K = 0;
        t++;
        sll(N);
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                cin >> arr[i][j];

                if (arr[i][j] >= 'A' && arr[i][j] <= 'Z') {
                    M[arr[i][j]] = make_pair(i, j);
                    K++;
                }
            }
        }

        ll ans = 0;
        pll strt;
        strt = M['A'];
        arr[strt.first][strt.second] = '.';
        bool chk = true;

        for (ll i = 0; i < K - 1; i++) {
            m0(vis);
            m0(dist);
            ll tt;
            tt = bfs(M[alphabet[i]], alphabet[i + 1]);
            if (tt == -1) {
                chk = false;
                break;
            }


            ans += tt;
        }


        printf("Case %lld: ", t);
        if (chk) {
            cout << ans << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
