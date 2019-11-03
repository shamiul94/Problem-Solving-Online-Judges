#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<cstdio>

using namespace std;

#define PII pair<int,int>
#define ll long long int

int lvlvis[25][25] = {};
char grid[25][25] = {};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
PII h, a, b, c;
int row, colm;

void Input() {
    cin >> row >> colm;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colm; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'h') {
                h = make_pair(i, j);
            } else if (grid[i][j] == 'a') {
                a = make_pair(i, j);
            } else if (grid[i][j] == 'b') {
                b = make_pair(i, j);
            } else if (grid[i][j] == 'c') {
                c = make_pair(i, j);
            }
        }
    }
}


void BFS() {
    queue<PII > q;
    q.push(h);
    lvlvis[h.first][h.second] = 1;

    while (!q.empty()) {
        PII node;
        node = q.front();
        q.pop();

        for (ll i = 0; i < 4; i++) {
            int tx = node.first + dx[i];
            int ty = node.second + dy[i];

            if (tx >= 0 && tx < row && ty >= 0 && ty < colm && grid[tx][ty] != 'm' && grid[tx][ty] != '#') {
                if (lvlvis[tx][ty] == 0) {
                    lvlvis[tx][ty] = lvlvis[node.first][node.second] + 1;
                    q.push(make_pair(tx, ty));
                } else {
                    if (lvlvis[node.first][node.second] + 1 < lvlvis[tx][ty]) {
                        lvlvis[tx][ty] = lvlvis[node.first][node.second] + 1;
                    }
                }

            }
        }
    }
}

int main() {
    int T, t = 0;
    cin >> T;
    ll ans;

    while (T--) {
        Input();
        BFS();
        ans = max(lvlvis[a.first][a.second], max(lvlvis[b.first][b.second], lvlvis[c.first][c.second]));
        printf("Case %d: %lld\n", t + 1, ans - 1);
        for (int i = 0; i < row; i++)
//        {
//            for(int j = 0 ; j< colm ; j++)
//            {
//                cout << lvlvis[i][j] << " ";
//            }
//            cout << endl ;
//        }
            memset(lvlvis, 0, sizeof(lvlvis));
        t++;
    }
    return 0;
}
 