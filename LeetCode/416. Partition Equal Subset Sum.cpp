#include<bits/stdc++.h>

using namespace std;

/*
 *
1. First, you have to know how you can format it into a DP problem. This playlist helped me understand 'PARTITION IN SUBSETS HAVING GIVEN DIFFERENCE'
2. Once you understand this, this becomes  simple knapsack. I was very familiar with recursive dp. I also implemented here the iterative one. LOOK VERY CAREFULLY IN THE ITERTATIVE SOLUTION.
3. DRAW THE DP TABLE AND UNDERSTAND Memory can be optimized from O(m*n) to O(2*n) to O(1*n).
 This space reduction is explained very well in this comment -
 https://leetcode.com/problems/partition-equal-subset-sum/discuss/1018225/Reducing-Memory-Space-Order-in-DP .
 I have also explanied it here - https://leetcode.com/problems/partition-equal-subset-sum/discuss/1018225/reducing-memory-space-order-in-dp .
 */


// memory further optimized - O(1*n) dp memory
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            // odd
            return false;
        }

        sum = sum / 2;

        bool curr_dp[sum + 1];
        memset(curr_dp, 0, (sum + 1) * sizeof(bool));


        curr_dp[0] = true;

        for (int i = 1; i <= n; i++) {
            int curr = nums[i - 1];
            for (int j = sum; j >= 0; j--) {
                if (j < curr) {
                    curr_dp[j] = curr_dp[j];
                } else {
                    curr_dp[j] = curr_dp[j] || curr_dp[j - curr];
                }
            }
        }

        return curr_dp[sum];

    }
};


// memory optimized - O(2*n) dp memory
class Solution3 {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            // odd
            return false;
        }

        sum = sum / 2;

        bool prev_dp[sum + 1];
        bool curr_dp[sum + 1];
        memset(prev_dp, 0, (sum + 1) * sizeof(bool));
        memset(curr_dp, 0, (sum + 1) * sizeof(bool));


        prev_dp[0] = true;

        for (int i = 1; i <= n; i++) {
            int curr = nums[i - 1];
            for (int j = 0; j <= sum; j++) {
                if (j < curr) {
                    curr_dp[j] = prev_dp[j];
                } else {
                    curr_dp[j] = prev_dp[j] || prev_dp[j - curr];
                }
            }
            for (int j = 0; j <= sum; j++) {
                prev_dp[j] = curr_dp[j];
            }
            cout << endl;
        }

        return curr_dp[sum];

    }
};


// iterative O(mn) time , O(mn) space
class Solution1 {
public:

    bool canPartition(vector<int> &nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            // odd
            return false;
        }

        sum = sum / 2;

        /*
         * using vector was making the code slow.
         * try to use bool array more often.
         *
         */

        // vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        bool dp[n + 1][sum + 1];
        memset(dp, 0, (n + 1) * (sum + 1) * sizeof(bool));


        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            int curr = nums[i - 1];
            for (int j = 0; j <= sum; j++) {
                if (j < curr) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - curr];
                }
            }
        }

        return dp[n][sum];

    }
};

// recursive solution
class Solution2 {
public:
    bool solve(vector<int> &nums, vector<vector<int>> &dp, int i, int sum) {
        if (i == nums.size()) {
            if (sum == 0) return true;

            return false;
        }

        if (sum < 0) return false;
        if (sum == 0) return dp[i][sum] = true;


        if (dp[i][sum] != -1) return dp[i][sum];
        // cout << dp[i][sum] << endl;

        return dp[i][sum] = solve(nums, dp, i + 1, sum - nums[i]) ||
                            solve(nums, dp, i + 1, sum);
    }

    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            // odd 
            return false;
        }

        sum = sum / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return solve(nums, dp, 0, sum);
    }
};


int main() {
//    clock_t begin_time = clock();
    auto t_start = std::chrono::high_resolution_clock::now();

    Solution s;
    vector<int> v{3, 3, 3, 4, 5};
    s.canPartition(v);
//    cout << float(clock() - begin_time) / CLOCKS_PER_SEC << endl;
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();

    cout << "time: " << elapsed_time_ms << endl;

    return 0;

}