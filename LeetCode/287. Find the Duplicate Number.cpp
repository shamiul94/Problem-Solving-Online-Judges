#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
            cout << slow << " " << fast << endl;
        } while(slow != fast);
        return 0;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,5};
    Solution s;
    s.findDuplicate(nums);

    return 0;
}