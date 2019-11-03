#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

#define ll long long

#define PII pair<int,int>

ll BFS() {
    ll ans = 1;
    int colm, row;
    cin >> colm >> row;
    char Grid[21][21] = {};
    int visited[21][21];
    memset(visited, 0, sizeof(visited));
    queue<PII > q;
    PII pos;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colm; j++) {
            cin >> Grid[i][j];
            if (Grid[i][j] == '@') {
                pos = make_pair(i, j);
                visited[i][j] = 1;
                q.push(pos);
            }
        }
    }

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};

    while (!q.empty()) {
        PII p;
        p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx, ty;
            tx = p.first + dx[i];
            ty = p.second + dy[i];

            if (tx >= 0 && tx < row && ty >= 0 && ty < colm && Grid[tx][ty] != '#') {
                if (visited[tx][ty] == 0) {
                    ans++;
                    visited[tx][ty] = 1;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }

    return ans;

}

int main() {
    int Test, t = 0;
    ll ans;
    cin >> Test;
    while (Test--) {
        t++;
        ans = BFS();
        printf("Case %d: %lld\n", t, ans);
    }

}