class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> ans(nums.size());
        // the idea is that, if we save the product of the numbers strictly before and strictly after
        // of a particular number, and then we multiply the 'before' and 'after' products,
        // this final product will be
        // equal to the product of the whole array without this particular number.

        // 1 2 3 4 5
        // let's say we want to calculate the product except-self for i = 2 (number = 3)
        // before = 1*2, after = 4*5
        // ans = before * after = (1*2) * (4*5) = 2 * 20 = 40

        // calculate and save 'before'

        int before = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = before;
            before *= nums[i];
        }

        int after = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= after;
            after *= nums[i];
        }

        return ans;
    }
};