//
// Created by heisenberg on 3/29/20.
//

#include <bits/stdc++.h>

#define PII pair<int, int>
#define EMPTY 0
#define GOOD 1
#define ROTTEN 2

using namespace std;

class Solution {
public:
    int getScore(vector<vector<pair<int, int>>> &gridState) {
        int minTime = INT_MIN;
        for (int i = 0; i < gridState.size(); i++) {
            for (int j = 0; j < gridState[i].size(); j++) {
                if (gridState[i][j].first == GOOD) {
                    return -1;
                }
                minTime = max(minTime, gridState[i][j].second);
            }
        }
        return minTime;
    }

    void bfs(vector<vector<pair<int, int>>> &gridState, int initI, int initJ) {
        int maxX, maxY;
        maxY = gridState.size();
        maxX = gridState[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        queue<PII > q;
        q.push(make_pair(initI, initJ));

        while (!q.empty()) {
            PII u = q.front();
            int ux = u.first;
            int uy = u.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int vx, vy;
                vx = ux + dx[i];
                vy = uy + dy[i];

                if (vx < 0 || vx >= maxY || vy < 0 || vy >= maxX) {
                    continue;
                }

                PII v = make_pair(vx, vy);

                if (gridState[vx][vy].first == GOOD) {
                    gridState[vx][vy].first = ROTTEN;
                    gridState[vx][vy].second = gridState[ux][uy].second + 1;
                    q.push(v);
                } else if (gridState[vx][vy].first == ROTTEN) {
                    if (gridState[vx][vy].second != 0) {
                        if (gridState[vx][vy].second > gridState[ux][uy].second + 1) {
                            gridState[vx][vy].second = gridState[ux][uy].second + 1;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>> &grid) {
        vector<pair<int, int>> initialRottens;

        vector<vector<pair<int, int>>> gridState;
        for (int i = 0; i < grid.size(); i++) {
            gridState.emplace_back();
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    initialRottens.emplace_back(i, j);
                }
                gridState[i].push_back(make_pair(grid[i][j], 0));
            }
        }

        for (int i = 0; i < initialRottens.size(); i++) {
            bfs(gridState, initialRottens[i].first, initialRottens[i].second);
        }

        return getScore(gridState);
    }
};


int main() {
    Solution s;
    vector<vector<int>> grid{{2, 1, 1},
                             {1, 2, 0},
                             {1, 1, 1}};
    cout << s.orangesRotting(grid) << endl;
    return 0;
}
//{{2,1,1},{1,1,0},{0,1,1}}