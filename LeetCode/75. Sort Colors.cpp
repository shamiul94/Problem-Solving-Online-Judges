#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int c = 0;

        while (l < r) {
            if (l > c) {
                c++;
                continue;
            }

            if (c > r) {
                break;
            }

            if (nums[c] == 0) {
                swap(nums[l], nums[c]);
                l++;
                continue; // ?
            }

            if (nums[c] == 2) {
                swap(nums[c], nums[r]);
                r--;
                continue; // ?
            }

            if (nums[c] == 1) {
                c++;
                continue;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> m{0, 1, 0};
    s.sortColors(m);

    for (int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
    cout << endl;
    return 0;
}

/**

    0   0   1   1   1   2   2   2 
    
            l
                        r
                            c
    0   1   2   2
        l
        r
        c
        
    0   0   2   0   2   2
        l
                    r
    c

*/