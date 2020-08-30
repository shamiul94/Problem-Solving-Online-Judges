#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> um;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int a, b;
            a = nums[i];
            b = target - a;
            if (um.find(b) != um.end()) { // found
                if (i == um[b]) continue;
                v.push_back(i);
                v.push_back(um[b]);
                break;
            }
        }
        return v;
    }
};
