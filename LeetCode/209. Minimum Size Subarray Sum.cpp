// my O(nlogn) solution
// 66%, 90%


class Solution1 {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.size() == 0) return 0;

        if (nums[0] >= s) return 1; // it's just an extended case of the below for loop.

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] >= s) return 1;
            nums[i] = nums[i - 1] + nums[i];
        }

        if (nums[n - 1] < s) return 0;
        if (nums[n - 1] == s) return n;

        int lo, hi, mid;
        int minLen = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= s) {
                lo = 0;
                hi = i - 1;
                while (lo <= hi) {
                    mid = (lo + hi) / 2;
                    if (nums[i] - nums[mid] >= s) {
                        lo = mid + 1;
                    } else if (nums[i] - nums[mid] < s) {
                        hi = mid - 1;
                    }
                }
                minLen = min(minLen, i - mid + 1); // r-l+1
            }
        }
        return minLen;
    }


};


///////////////////////////

// my O(n) solution - two pointer
// 97%, 20%

class Solution2 {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.size() == 0) return 0;

        if (nums[0] >= s) return 1; // it's just an extended case of the below for loop.

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] >= s) return 1;
            nums[i] = nums[i - 1] + nums[i];
        }

        if (nums[n - 1] < s) return 0;
        if (nums[n - 1] == s) return n;

        nums.insert(nums.begin(), 0);


        int l = 0;
        int minLen = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            while (nums[i] - nums[l] >= s) {
                minLen = min(minLen, i - l);
                l++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }

};

/////////////

// their O(n) solution - two pointer more optimized.
// 97%,100%

class Solution3 {
public:

    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};


//////////

// their O(nlogn) solution
// 19%, 35%

class Solution4 {
public:

    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); //size = n+1 for easier calculations
        //sums[0]=0 : Meaning that it is the sum of first 0 elements
        //sums[1]=A[0] : Sum of first 1 elements
        //ans so on...
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            int to_find = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};