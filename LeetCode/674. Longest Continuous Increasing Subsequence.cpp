class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int max_len = 1;
        int len;

        int prev = nums[0];
        len = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > prev) {
                len++;
                prev = nums[i];
            } else {
                prev = nums[i];
                len = 1;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};