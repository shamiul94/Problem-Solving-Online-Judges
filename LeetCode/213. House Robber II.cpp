class Solution {
public:
    int solve(vector<int> &nums, int lo, int hi) {
        int prev1 = 0, prev2 = 0;
        for (int i = lo; i <= hi; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        // if you take 1st one, you can't take the last one.
        // if you take from 2nd one, you CAN take the last one.
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};
