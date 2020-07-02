#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>> &board, string &word, int idx, int i, int j, int level) {

        // cout << level << endl;
        if (level == word.length()) {
            return true; // cause possible dekhei tumi ei porjnto ascho. and '''>'' e jabe na kokhono
        }

        int n = board.size();
        int m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m) return false;

        if (board[i][j] == '#') return false;

        if (board[i][j] != word[idx]) return false;

        char tem = board[i][j];

        board[i][j] = '#';

        bool ret = solve(board, word, idx + 1, i - 1, j, level + 1) || solve(board, word, idx + 1, i + 1, j, level + 1) || solve(board, word, idx + 1, i, j + 1, level + 1) || solve(board, word, idx + 1, i, j - 1, level + 1);

        board[i][j] = tem;

        return ret;
    }

    bool exist(vector<vector<char>> &board, string word) {
        bool ans = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                ans = solve(board, word, 0, i, j, 0);
                if (ans) break;
            }
            if (ans) break;
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> v{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    Solution s;
    cout << s.exist(v, "FC") << endl;
    return 0;
}