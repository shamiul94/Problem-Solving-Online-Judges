class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= s) {
                s = s - nums[i];
                count++;
                if (s <= 0) {
                    break;
                }
            }
        }
        return count;
    }
};
