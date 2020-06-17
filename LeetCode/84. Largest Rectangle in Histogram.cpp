#include <bits/stdc++.h>

using namespace std;

// stack based
class Solution1 {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();

        stack<int> idxStk; // keep left indexes in it

        int maxArea = 0;

        int i = 0;
        while (i < n) {
            if (idxStk.empty() || heights[i] >= heights[idxStk.top()]) {
                idxStk.push(i);
                i++;
                continue;
            }

            // not empty + smaller than the top
            int currTop = idxStk.top();
            idxStk.pop();

            int width = 0;
            if (!idxStk.empty()) {
                int nextTop = idxStk.top(); // don't pop it 
                width = i - nextTop - 1;
            } else {
                width = i;
            }

            int area = width * heights[currTop];

            maxArea = max(area, maxArea);
        }

        while (!idxStk.empty()) {
            int currTop = idxStk.top();
            idxStk.pop();

            int width = idxStk.empty() ? i : i - idxStk.top() - 1;
            int area = width * heights[currTop];
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};

// DP solution


// stack based
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.size() == 0) return 0;
        int n = heights.size();
        vector<int> left;
        left.push_back(-1);
        for (int i = 1; i < n; i++) {
            int curr = i;
            int prev = i - 1;
            if (heights[curr] <= heights[prev]) {
                while (true) {
                    prev = left[prev];
                    if (heights[prev] > heights[curr]) break;
                    if (prev == -1) break;
                }

                left[curr] = prev;

            } else {
                left.push_back(i);
            }
        }
    }
};