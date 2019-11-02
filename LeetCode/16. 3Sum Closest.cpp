#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSum(vector<int> &nums, int target) {
        int minDiff = INT_MAX, closestSum;
        sort(nums.begin(), nums.end());
        int a, b, c;
        int Target = target;
        int n = static_cast<int>(nums.size());
        int l, r;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // ignoring duplicates
            l = i + 1;
            r = n - 1;
            a = nums[i];
            // 2 pointer
            while (l < r) {
                b = nums[l];
                c = nums[r];
                int sum = a + b + c;
                if (sum < Target) {
                    l++;
                } else if (sum > Target) {
                    r--;
                } else {
                    while (l < r && nums[l] == b) { // ignoring duplicates
                        l++;
                    }
                    while (r > l && nums[r] == c) { // ignoring duplicates
                        r--;
                    }
                }
                int diff = abs(Target - sum);
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }
            }
        }
        return closestSum;
    }
};
