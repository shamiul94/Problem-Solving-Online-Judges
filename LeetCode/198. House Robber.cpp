class Solution1 {
public:
    int n;

    int solve(vector<int> &nums, vector<int> &dp, int idx) {
        if (idx >= n) {
            return 0;
        }
        if (dp[idx] != -1) return dp[idx];

        return dp[idx] = max(solve(nums, dp, idx + 1), nums[idx] + solve(nums, dp, idx + 2));
    }

    int rob(vector<int> &nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, 0);
    }
};

////////////////


class Solution2 {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, -1);
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = max(nums[n - 1], nums[n - 2]);
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }
};

/////////////


class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // you can either take nums[0] and ignore nums[1]
        // or you can ignore nums[0] and ask nums[1] to give the result
        // which will be nums[1] as there are no elements after that.
        if (n == 2) return max(nums[0], nums[1]);

        // we can see that at a time you need just dp[n-1] and dp[n-2].
        // other elements are not needed.
        // you can just save them in a variable and that'll do the job.
        // this type of dp is called N-variable dp which is very memory efficient.
        // vector<int> dp(n,-1);

        int dp_2nd = nums[n - 1]; //dp[n-1] = nums[n-1]; ==> last element of dp array
        // second last element of dp array
        // it is max(nums[n - 1], nums[n - 2]) , because -
        // you can either take nums[n-2] and ignore nums[n-1]
        // or you can ignore nums[n-2] and ask nums[n-1] to give the result
        // which will be nums[n-1] as there are no elements after that.

        int dp_1st = max(nums[n - 1], nums[n - 2]); //dp[n-2] = max(nums[n - 1], nums[n - 2]);
        int dp_curr;

        for (int i = n - 3; i >= 0; i--) {
            // dp_curr, dp_1st, dp_2nd ---> sequence
            dp_curr = max(dp_1st, nums[i] + dp_2nd);
            //dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
            dp_2nd = dp_1st;
            dp_1st = dp_curr;
        }
        return dp_curr;
    }
};
