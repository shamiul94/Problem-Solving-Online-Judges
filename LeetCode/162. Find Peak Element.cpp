#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int low = 0;
        int high = num.size() - 1;

        while (low < high) {
            int mid1 = (low + high) / 2;
            int mid2 = mid1 + 1;
            if (num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};

int main() {
    Solution s;
    vector<int> v{1, 5, 6, 3, 2, 1, 0, 4, 6, 7, 8, 9, 10, 11};
    cout << v[s.findPeakElement(v)] << endl;
    return 0;
}