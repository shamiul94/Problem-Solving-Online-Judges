
class Solution
{
public:
    void print(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

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

    // O(n) space
    int solve(vector<int> &nums, int target)
    {
        vector<int> dp1(target + 1, 0);
        int row = nums.size();
        // int colm = target+1;

        dp1[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            dp1[i] = 0;
        }

        // print(dp1);

        for (int i = 1; i <= row; i++)
        {
            // cout << "hi " << i << endl;

            for (int j = target; j >= 0; j--)
            {
                dp1[j] = getValue(dp1, j, target + 1) + getValue(dp1, j - nums[i - 1], target + 1);
            }

            // print(dp2);
        }
        // print(dp1);

        return dp1[target];

        // getValue(dp, 0, target + 1);
    }

    // O(2n) space
    int solve1(vector<int> &nums, int target)
    {
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        vector<int> dp1(target + 1, 0);
        vector<int> dp2(target + 1, 0);
        int row = nums.size();
        // int colm = target+1;

        dp1[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            dp1[i] = 0;
        }

        // print(dp1);

        for (int i = 1; i <= row; i++)
        {
            // cout << "hi " << i << endl;

            for (int j = 0; j <= target; j++)
            {
                // dp2[i] = dp1[i] + dp1[i - nums[i]];
                dp2[j] = getValue(dp1, j, target + 1) + getValue(dp1, j - nums[i - 1], target + 1);
            }

            for (int j = 0; j <= target; j++)
            {
                dp1[j] = dp2[j];
            }

            // print(dp2);
        }
        // print(dp1);

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

        /*
            You might ask what if the given difference is negative? 
            lets say, s1-s2 = -3, So, s2-s1=3. 
            again, say, s1+s2 = 10

            So, 2*s2 = (3+10)/2. 
            So, it doesn't matter actually if it's negative or not because you are either calculating s1 or s2. 
        */

        // this line is needed because the sum is bound to be within 1000 as specified in the description
        // array sum can't be less than the difference of 2 subsets for non-negative integers.  
        // so, you will get tle if diff = 100000000000000 but sum <= 1000.
         
        if (S > sum)
            return 0;

        if ((S + sum) % 2 != 0)
        {
            return 0;
        }

        int target = (S + sum) / 2;

        return solve(nums, target);
    }
};