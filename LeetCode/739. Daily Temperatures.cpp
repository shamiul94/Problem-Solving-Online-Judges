
#include <bits/stdc++.h>
#define print_vec(vec) for(int i = 0 ; i < vec.size(); i++){cout<<vec[i]<<" ";} cout << endl

using namespace std;
// stack solution

class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        int n = T.size();
        stack<int> s;
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(i);
                continue;
            }

            int top = 0;
            // decreasing stack (upwards obviously)
            // why decreasing stack?
            // 73, 74, 75, 71, 69, 72, 76, 73
            // we start from the end.
            // If we find 76 after 73, that means, every number that can be covered with 73, will automatically
            // be covered with 76. So, we don't need 73 anymore.
            // But when we find 72 after 76, that means we need both of them because, 72 can't cover all
            // the numbers which is covered by 76.

            // Think about it. Really simple. Similar to Largest Rectangle in Histogram.
            // they all are variations of finding maximum/minimum in a range.
            while (!s.empty() && T[s.top()] <= T[i]) {
                int top = s.top();
                s.pop();
            }

            if (s.empty()) {
                ans[i] = 0;
                s.push(i);
            } else {
                ans[i] = s.top() - i;
                s.push(i);
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        int n = T.size();
        vector<int> right(n, n);
        vector<int> ans(n, 0);
        right[n - 1] = n;
        ans[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            int curr = i;
            int next = i + 1;

            while (next <= n - 1 && T[curr] >= T[next]) {
                next = right[next];
            }

            if (next > n - 1) {
                right[curr] = next;
                ans[curr] = 0;
            } else {
                right[curr] = next;
                ans[curr] = next - curr;
            }
        }
        return ans;
    }
};


int main() {
    vector<int> v{73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    s.dailyTemperatures(v);
    return 0;
}