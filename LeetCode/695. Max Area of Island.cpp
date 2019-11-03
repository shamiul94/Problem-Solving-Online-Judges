#include<bits/stdc++.h>

using namespace std;


int vis[60][60] = {0};

class Solution {
public:
    vector<vector<int>> arr;
    int row, colm;
    int NOT_VISITED = 0;
    int VISITED = 1;

    // i = rows, j == colms
    int dfs(int i, int j) {
        if (i < 0 || i > row - 1 || j < 0 || j > colm - 1) {
            return 0;
        }
        if (arr[i][j] == 0) return 0;

        if (vis[i][j] == VISITED) return 0;
        int ret = 0;
        if (vis[i][j] == NOT_VISITED) {
            vis[i][j] = VISITED;
            ret = 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
//            cout << "------------------" << endl;
//            cout << i << " " << j << endl;
//            cout << i + 1 << " " << j << endl;
//            cout << i - 1 << " " << j << endl;
//            cout << i << " " << j + 1 << endl;
//            cout << i << " " << j - 1 << endl;
//            cout << ret << endl;
        }
        return ret;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        memset(vis, 0, sizeof(vis));
        int maximum = 0;
        arr = grid;
        row = static_cast<int>(arr.size());
        colm = static_cast<int>(arr[0].size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && vis[i][j] == NOT_VISITED) {
                    int u = dfs(i, j);
                    if (maximum < u) {
                        maximum = u;
                    }
                }
            }
        }
        return maximum;
    }
};

int main() {
//    vector<vector<int>> grid{
//            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
//            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
//            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
//            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
//            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
//            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
//    };
//    vector<vector<int>> grid{
//            {1, 1, 0, 1, 1},
//            {1, 0, 0, 0, 0},
//            {0, 0, 0, 0, 1},
//            {1, 1, 0, 1, 1}
//    };

    vector<vector<int>> grid{{0}};
    Solution s = Solution();
//    s.maxAreaOfIsland(grid);
    cout << s.maxAreaOfIsland(grid) << endl;

//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 5; j++) {
//            cout << vis[i][j] << " ";
//        }
//        cout << endl;
//    }
}