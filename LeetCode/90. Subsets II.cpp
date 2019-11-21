// original solution
// 83%, 92%

// this type of problem requires backtracking.
// permutation, combination, subset, subset sum - these require backtracking.

class Solution {
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
