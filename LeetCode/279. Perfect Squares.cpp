// My full explanation - https://leetcode.com/problems/perfect-squares/discuss/705531/5-to-91-Step-By-Step-Explanation%3A-Improving-A-Dumb-Recursive-Coin-Change-DP-Solution

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int solve(vector<int> &sqrs, vector<vector<int>> &dp, int idx, int target) {
        if (target == 0) {
            return dp[idx][target] = 0;
        }

        if (idx >= sqrs.size()) {

            /* 10000 is just a huge number to ensure that it never gets saved in the DP array 
			as DP[target] = min(ret1, ret2). That means 10000 won't be selected because of min() function
			A common question arises that if ret2 == 10000, how do you know that ret1 will not be more
			than 10000 thus returning the value 10000 itself? Answer: We do because there is a formula named Legendre's 3-square 
			formula* stating that 'A natural number can be represented as the sum 
			of three squares of integers'. So, 10000 will be far more than enough for us as a 
			higher boundary value. */

            return 10000;
        }

        // avoiding repeated calculation

        if (dp[idx][target] != -1) return dp[idx][target];

        /* If no value is assigned to the ret1 because of the if() condition, 
		   we want it to be a high value so that it's not returned 
		*/
        int ret1 = 10000, ret2 = 10000; // this line costed me 7 hours. ret1 was previously set at 0. If the below
                                        // IF() block is skipped, that 0 was being chosen everytime as it's the most minimum value.

        if (target - sqrs[idx] >= 0) {

            // If we can take this value, we will take it and that means,
            // 1. we have added a value (we added 1 for this reason)
            // 2. our target decreases (target - sqrs[idx])
            ret1 = 1 + solve(sqrs, dp, idx, target - sqrs[idx]);
        }

        // If we don't take the current index value, we can just ignore it and go to the next value.

        ret2 = solve(sqrs, dp, idx + 1, target);

        dp[idx][target] = min(ret1, ret2);

        return dp[idx][target];
    }

    int numSquares(int n) {
        vector<int> sqrs;
        int s = 1;
        while (s * s <= n) {
            sqrs.push_back(s * s);
            s++;
        }

        vector<vector<int>> dp(sqrs.size(), vector<int>(n + 1, -1));
        int x = solve(sqrs, dp, 0, n);

        return x;
    }
};

///////////////

class Solution2 {
public:
    int solve(vector<int> &sqrs, vector<int> &dp, int idx, int target) {
        if (target == 0) {
            return dp[target] = 0;
        }

        if (idx >= sqrs.size()) {
            return 10000;
        }

        if (dp[target] != INT_MAX) return dp[target];

        int ret1 = 10000, ret2 = 10000;

        if (target - sqrs[idx] >= 0) {
            ret1 = 1 + solve(sqrs, dp, idx, target - sqrs[idx]);
        }

        ret2 = solve(sqrs, dp, idx + 1, target);

        dp[target] = min(dp[target], min(ret1, ret2));

        return dp[target];
    }

    int numSquares(int n) {
        vector<int> sqrs;
        int s = 1;
        while (s * s <= n) {
            sqrs.push_back(s * s);
            s++;
        }

        vector<int> dp(n + 1, INT_MAX);

        int x = solve(sqrs, dp, 0, n);

        return x;
    }
};

//////////////////

class Solution {
public:
    int solve(vector<int> &sqrs, vector<int> &dp, int idx, int target) {
        if (target == 0) {
            return dp[target] = 0;
        }

        if (idx >= sqrs.size()) {
            return 10000;
        }

        if (dp[target] != INT_MAX) return dp[target];

        int ret1 = 10000, ret2 = 10000;

        if (target - sqrs[idx] >= 0) {
            ret1 = 1 + solve(sqrs, dp, idx, target - sqrs[idx]);
        }

        ret2 = solve(sqrs, dp, idx + 1, target);

        dp[target] = min(dp[target], min(ret1, ret2));

        return dp[target];
    }

    int numSquares(int n) {
        vector<int> sqrs;
        int s = 1;
        while (s * s <= n) {
            sqrs.push_back(s * s);
            s++;
        }

        static vector<int> dp(n + 1, INT_MAX);

        int a = n + 1 - dp.size();
        for (int i = 1; i <= a; i++) {
            dp.push_back(INT_MAX);
        }

        int x = solve(sqrs, dp, 0, n);

        return x;
    }
};

int main() {
    Solution1 s;
    cout << s.numSquares(12) << endl;
    cout << s.numSquares(13) << endl;
    cout << s.numSquares(52) << endl;
    cout << s.numSquares(12) << endl;
    cout << s.numSquares(13) << endl;
    return 0;
}
