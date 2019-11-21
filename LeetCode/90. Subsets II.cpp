// original solution
// 83%, 92%

// this type of problem requires backtracking.
// permutation, combination, subset, subset sum - these require backtracking.

class Solution1 {
public:
    void solve(vector <vector<int>> &vec, vector<int> &nums, vector<int> &v, int start) {
        vec.push_back(v);
        for (int i = start; i < nums.size(); i++) {
            // if the character is being repeated, it has already been added
            // to some array in the previous step.
            // that means the array including this element is already in the vec<>
            // so, we can ignore it.
            if (i != start && nums[i] == nums[i - 1]) continue;
            // this is common in this type of problem
            // here we push something in the vector
            // and send it to next step.
            v.push_back(nums[i]);
            solve(vec, nums, v, i + 1);
            // then we pop it back.
            // so that it's change is nullified.
            v.pop_back();
        }
    }

    vector <vector<int>> subsetsWithDup(vector<int> &nums) {
        vector <vector<int>> vec;
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(vec, nums, v, 0);
        return vec;
    }
};


//////////////////

// 99%, 100%
// This is also my original solution : got idea from a discussion post of subset-1
// for that solution, look at subset-1 second solution.
// that problem had no duplicate.
// I made it work for duplicate.
// I am proud of this solution.


// prerequisite to understand this solution:
// you need to review the second solution of 'Subsets' (https://leetcode.com/problems/subsets/) problem first.
//
// This solution is just an extension of that solution.

// idea: the idea is that -
// suppose you have {1,2,3,3,3}
// Now serially, you get -
// 1. null
// 2. null | 1
// 3. null | 1 | 2 ; 1,2
// 4. null | 1 | 2 ; 1,2 | 3; 1,3; 2,3; 1,2,3
// 5. null | 1 | 2 ; 1,2 | 3; 1,3; 2,3; 1,2,3 | 3,3; 1,3,3; 2,3,3; 1,2,3,3
// 6. null | 1 | 2 ; 1,2 | 3; 1,3; 2,3; 1,2,3 | 3,3; 1,3,3; 2,3,3; 1,2,3,3 | 3,3,3; 1,3,3,3; 2,3,3,3; 1,2,3,3,3
// You can see that, you don't need to add this number to all the previous subsets
// if the new number is repeated.
// you need to add this number to the last created subsets in the previous step.
// so, you save the index number in 2-d vector of the first subset which you created in
// the last iteration (which is == n, because the size of vec<vec> before that was n and last index was n-1 ).
// prevLow is that index.


class Solution {
public:

    vector <vector<int>> subsetsWithDup(vector<int> &nums) {
        vector <vector<int>> vec;
        sort(nums.begin(), nums.end());
        vector<int> u;
        vec.push_back(u);

        int prevLow;
        int start;

        for (int i = 0; i < nums.size(); i++) {
            int n = vec.size();
            if (i > 0 && nums[i] == nums[i - 1]) {
                start = prevLow;
            } else {
                start = 0;
            }
            for (int j = start; j < n; j++) {
                vector<int> v = vec[j];
                v.push_back(nums[i]);
                vec.push_back(v);
            }
            prevLow = n;
        }
        return vec;
    }
};

