#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int amt;
    static int N;

    int solve(vector<vector<int>> &dp, vector<int> &coins, int i, int amount) {
        if (i >= N) {
            if (amount == 0) return 0;
            else return INT_MAX;
        }

        if (dp[i][amount] != -1) return dp[i][amount];

        int ret1 = INT_MAX, ret2 = INT_MAX;

        if (amount - coins[i] >= 0) {
            ret1 = 1 + solve(dp, coins, i + 1, amount - coins[i]);
        }
        ret2 = solve(dp, coins, i + 1, amount);

        return dp[i][amount] = min(ret1, ret2);
    }


    int coinChange(vector<int> &coins, int amount) {
        amt = amount;
        N = coins.size();
        vector<vector<int>> dp(N, vector<int>(amount, -1));
        return solve(dp, coins, 0, amount);
    }
};
