//
// Created by heisenberg on 4/18/20.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> sumVsIdx;

        int sum = 0, maxLen = 0;
        sumVsIdx[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                sum += -1;
            } else {
                sum += 1;
            }

            if (sumVsIdx.count(sum) == 0) {
                sumVsIdx[sum] = i;
            } else {
                maxLen = max(maxLen, i - sumVsIdx[sum]);
            }
        }
        return maxLen;
    }
};