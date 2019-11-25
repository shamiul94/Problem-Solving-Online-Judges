
///////////////

class Solution1 {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int maxRun = 0, thisRun = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                thisRun++;
                maxRun = (maxRun < thisRun) ? thisRun : maxRun;
                continue;
            }
            thisRun = 0;
        }
        return maxRun;
    }
};


/////////////


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int maxRun = 0, thisRun = 0;
        for (int i = 0; i < nums.size(); i++) {
            thisRun = (thisRun + 1) * nums[i]; // multiplying with 0 clears everything.
            maxRun = max(maxRun, thisRun);
        }
        return maxRun;
    }
};
