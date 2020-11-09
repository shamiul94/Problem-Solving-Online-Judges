/*
Idea:
1. sorted array == binary search these days. so we can do it by binary search
2. we count the difference between 2 consecutive numbers. this diff actually denotes the missing number between these 2 conseq numbers. if this difference is < k, that means, we need to go right. If diff >= k, that means, we need to go left. now think about it a bit more and you will get it.

*/

class Solution {
public:
    int missingElement(vector<int> &nums, int k) {
        int lo = 0;
        int hi = nums.size() - 1;

        int missingNum = nums[hi] - nums[0] + 1 - nums.size();

        if (missingNum < k) {
            return nums[hi] + k - missingNum;
        }

        int mid = lo + (hi - lo) / 2;
        // int idx = 0 ;
        while (lo + 1 < hi) {
            mid = lo + (hi - lo) / 2;

            int num_diff = nums[mid] - nums[lo] + 1;
            int idx_diff = mid - lo + 1;
            int missing_num = num_diff - idx_diff;

            // cout << "lo" << " " << "hi" << " " << "num_diff" << " " << "idx_diff" << " " << "missing_num" << endl;
            // cout << lo << " " << hi << " " << num_diff << " " << idx_diff << " " << missing_num << endl;
            // cout << "############" << endl;

            if (k > missing_num) {
                // idx = lo;
                lo = mid;
                k -= missing_num;
            } else if (k <= missing_num) {
                hi = mid;
            }
        }
        return (nums[lo] + k);
    }
};

/////////////////////////////////////////////////

class Solution2 {
public:
    int missingElement(vector<int> &nums, int k) {
        int prev = nums[0];
        int curr;
        int ans = 0;
        int miss = 0;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            curr = nums[i];
            miss = curr - prev - 1;
            if (k > miss) {
                k = k - miss;
            } else {
                ans = prev + k;
                return ans;
            }
            prev = curr;
        }
        return nums[n - 1] + k;
    }
};

/*
1   2     5        9   10 ; k = 4
      3,4   6,7,8  
      
missing = curr - prem - 1 = 2 - 1 - 1 = 0 
        = 5 - 2 - 1 = 2 



*/