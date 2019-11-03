/**

@author - Rumman BUET CSE'15
Problem - 1175 - Jane and the Frost Giants

Concept - BFS

Speciality - A lot of corner cases. Tedious. BFS 2 times.

There may be as many F as they want. So, you have to put the shortest value in the grid by comparing them.

Tedious and lengthy. Easy one though.

*/



// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000
#define pll pair<ll,ll>

using namespace std;

ll dx[] = {0, 0, 1, -1};
ll dy[] = {-1, 1, 0, 0};

char grid[210][210] = {};
ll fireGrid[210][210] = {};
ll janeGrid[210][210] = {};

pll jane, fire;
ll r, c;

void printgrid() {
    cout << "Main Grid: " << endl;
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl << endl;


    cout << "Fire Grid: " << endl;
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            cout << fireGrid[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl << endl;
    cout << "Jane Grid:" << endl;

    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            cout << janeGrid[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

void FireBFS() {
    queue<pll > q;
    pll pos;

    q.push(fire);
    fireGrid[fire.first][fire.second] = 1;

    while (!q.empty()) {
        pll p;
        p = q.front();
        q.pop();

        for (ll i = 0; i < 4; i++) {
            ll tx, ty;
            tx = p.first + dx[i];
            ty = p.second + dy[i];

            if (tx >= 0 && tx < r && ty >= 0 && ty < c && grid[tx][ty] != '#') {
                if (fireGrid[tx][ty] == -1) {
                    fireGrid[tx][ty] = fireGrid[p.first][p.second] + 1;
                    q.push(make_pair(tx, ty));
                } else {
                    if (fireGrid[tx][ty] > fireGrid[p.first][p.second] + 1) {
                        fireGrid[tx][ty] = fireGrid[p.first][p.second] + 1;
                        q.push(make_pair(tx, ty));
                    }
                }
            }
        }
    }
    return;
}

void JaneBFS() {
    if (jane.first == 0 || jane.first == r - 1 || jane.second == 0 || jane.second == c - 1) {
        printf("1\n");
        return;
    }

    queue<pll > q;

    q.push(jane);
    janeGrid[jane.first][jane.second] = 1;

    while (!q.empty()) {
        pll p;
        p = q.front();
        q.pop();

        bool dead = true;

        for (ll i = 0; i < 4; i++) {
            ll tx, ty;
            tx = p.first + dx[i];
            ty = p.second + dy[i];

            if (tx >= 0 && tx < r && ty >= 0 && ty < c && grid[tx][ty] != '#') {
                if (janeGrid[tx][ty] == -1) {
                    janeGrid[tx][ty] = janeGrid[p.first][p.second] + 1;
                    q.push(make_pair(tx, ty));

                    if (tx == r - 1 || tx == 0 || ty == 0 || ty == c - 1) {
                        if (fireGrid[tx][ty] > janeGrid[tx][ty] || fireGrid[tx][ty] == -1) {
                            printf("%lld\n", janeGrid[tx][ty]);
                            return;
                        }
                    }
                }
            }
        }
    }

    printf("IMPOSSIBLE\n");
    return;
}


void BFS() {
    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            if (grid[i][j] == 'F') {
                fire = make_pair(i, j);
                FireBFS();
            }
        }
    }

    JaneBFS();
    return;
}


int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);
    while (T--) {
        for (ll i = 0; i < 210; i++) {
            for (ll j = 0; j < 210; j++) {
                grid[i][j] = '\0';
                fireGrid[i][j] = -1;
                janeGrid[i][j] = -1;
            }
        }

        t++;
        scanf("%lld %lld", &r, &c);
//        cout << r << " " << c << endl ;

        for (ll i = 0; i < r; i++) {
            for (ll j = 0; j < c; j++) {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == 'J') {
                    jane = make_pair(i, j);
                }
            }
        }

        printf("Case %lld: ", t);
        BFS();
//        printgrid() ;
    }
    return 0;
}
