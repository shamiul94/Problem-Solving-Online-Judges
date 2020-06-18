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
        if (heights.empty()) return 0;
        int n = heights.size();

        vector<int> left(n);
        left[0] = -1;


        for (int i = 1; i < n; i++) {
            // cout << "hi" << endl;
            // cout << i << endl;
            int curr = i;
            int prev = i - 1;
            if (heights[curr] <= heights[prev]) {
                while (true) {
                    prev = left[prev];
                    if (prev == -1) break;
                    if (heights[curr] > heights[prev]) break;
                }
                left[curr] = prev;
            } else {
                left[curr] = prev;
            }
        }


        vector<int> right(n);
        right[n - 1] = n;

        for (int i = n - 2; i >= 0; i--) {
            int curr = i;
            int next = i + 1;
            if (heights[curr] <= heights[next]) {
                while (true) {
                    next = right[next];
                    if (next == n) break;
                    if (heights[curr] > heights[next]) {
                        break;
                    }
                }
                right[curr] = next;
            } else {
                right[curr] = next;
            }
        }

//        for (int i = 0; i < n; i++) {
//            cout << left[i] << " ";
//        }
//        cout << endl;
//        for (int i = 0; i < n; i++) {
//            cout << right[i] << " ";
//        }
//        cout << endl;

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main() {
    vector<int> v{2,1,5,6,2,3};
    Solution s;
    cout <<  s.largestRectangleArea(v) << endl;
    return 0;
}