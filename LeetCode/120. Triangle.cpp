
#include<bits/stdc++.h>

using namespace std;

int dp[500][500] = {};


// recursive solution - O(n^2) space
class Solution {
public:
    vector<vector<int>> arr;
    int row, colm;

    int solve(int i, int j) {
        colm = i + 1;
        if (i < 0 || j < 0 || i > row - 1 || j > colm - 1) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        mini = min(mini, arr[i][j] + solve(i + 1, j));
        mini = min(mini, arr[i][j] + solve(i + 1, j + 1));
        return dp[i][j] = mini;
    }

    int minimumTotal(vector<vector<int>> &triangle) {
        memset(dp, -1, sizeof(dp));
        row = triangle.size();
        arr = triangle;
        int ans = solve(0, 0);
        return ans;
    }
};

// Iterative Solution - O(n) space
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n-1]);
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = 0 ; j <= i ; j++){
                dp[j] = triangle[i][j] + min(dp[j] , dp[j+1]);
            }
        }
        return dp[0];
    }
};


int main() {
    vector<vector<int>> v
            {
                    {2},
                    {3, 4},
                    {6, 5, 7},
                    {4, 1, 8, 3}
            };

    Solution s = Solution();
    cout << s.minimumTotal(v) << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

