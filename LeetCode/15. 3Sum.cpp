#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> v;
        if(nums.size() == 0) return v;
        sort(nums.begin(), nums.end());
        int a, b, c;
        int target = 0;
        int n = nums.size();
        int l, r;
        for (int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;  // ignoring duplicates
            l = i+1;
            r = n-1;
            a = nums[i];
            // 2 pointer
            while (l < r) {
                b = nums[l];
                c = nums[r];
                int sum = a + b + c;
                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    v.push_back(vector<int>{a, b, c});
                    while (l < r && nums[l] == b) { // ignoring duplicates
                        l++;
                    }
                    while (r > l && nums[r] == c) { // ignoring duplicates
                        r--;
                    }
                }
            }
        }
        return v;
    }
};
