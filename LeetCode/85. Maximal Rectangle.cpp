//
// Created by heisenberg on 6/18/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // stack solution
    int solveHistogram1(vector<int> &heights) {
        int n = heights.size();

        int maxArea = 0;
        stack<int> s;

        int i = 0;
        for (; i < n; i++) {
            if (s.empty()) {
                s.push(i);
                continue;
            }
            if (heights[i] >= heights[s.top()]) {
                s.push(i);
                continue;
            }

            while (!s.empty() && heights[s.top()] > heights[i]) {
                int topIdx = s.top();
                s.pop();
                int areaWithThisHeight = heights[topIdx] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, areaWithThisHeight);
            }
            s.push(i);
        }

        while (!s.empty()) {
            int topIdx = s.top();
            s.pop();
            int areaWithThisHeight = heights[topIdx] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, areaWithThisHeight);
        }
        return maxArea;
    }

    // DP solution
    int solveHistogram(vector<int> &heights) {
        int maxArea = 0;
        int n = heights.size();
        vector<int> left(n);


        left[0] = -1;
        for (int i = 1; i < n; i++) {
            int curr = i;
            int prev = i - 1;

            if (heights[curr] > heights[prev]) {
                left[curr] = prev;
                continue;
            }
            // if(heights[curr] <= heights[prev])
            while (prev >= 0 && heights[curr] <= heights[prev]) {
                prev = left[prev];
            }
            left[curr] = prev;
        }

        vector<int> right(n);
        right[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            int curr = i;
            int next = i + 1;

            if (heights[curr] > heights[next]) {
                right[curr] = next;
                continue;
            }

            while (next <= n - 1 && heights[curr] <= heights[next]) {
                next = right[next];
            }

            right[curr] = next;
        }



        for (int i = 0; i < n; i++) {
            int area = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }


    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        vector<int> heights(matrix[0].size(), 0);
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, solveHistogram(heights));
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    vector<vector<char>> v{
            {'1', '0', '0', '1', '1'},
            {'1', '0', '1', '1', '0'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '1', '0', '0'}
    };
    cout << s.maximalRectangle(v) << endl;

    vector<int> h{4, 0, 4, 4, 0};
    cout << s.solveHistogram(h) << endl;
    return 0;
}