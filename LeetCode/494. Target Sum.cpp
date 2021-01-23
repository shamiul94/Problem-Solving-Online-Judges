#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSum(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }

    int getValue(vector<int> &dp, int i, int len)
    {
        if (i < 0 || i >= len)
        {
            return 0;
        }
        else
        {
            return dp[i];
        }
    }

    // O(2n) space
    int solve(vector<int> &nums, int target)
    {
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        vector<int> dp1(target + 1, 0);
        vector<int> dp2(target + 1, 0);
        int row = nums.size() + 1;
        // int colm = target+1;
        dp1[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            dp1[i] = 0;
        }

        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= target + 1; j++)
            {
                // dp2[i] = dp1[i] + dp1[i - nums[i]];
                dp2[i] = getValue(dp1, j, target + 1) + getValue(dp1, j - nums[i], target + 1);
            }

            for (int j = 1; j <= target + 1; j++)
            {
                dp1[j] = dp2[j];
            }
        }

        return dp2[target];

        // getValue(dp, 0, target + 1);
    }

    int
    findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = getSum(nums);
        // s1 - s2 = S
        // s1 + s2 = sum
        // so, s1 = (S + sum)/ 2
        // and, s2 = sum - s1

        if ((S + sum) % 2 != 0)
        {
            return 0;
        }

        int target = (S + sum) / 2;

        solve(nums, target);
    }
};