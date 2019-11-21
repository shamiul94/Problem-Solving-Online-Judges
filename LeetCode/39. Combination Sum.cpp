class Solution {
public:
    void solve(vector <vector<int>> &vec, vector<int> &candidates, vector<int> &v, int start, int target) {
        if (target < 0) {
            return; // as all numbers will be positive, so it can't increase after being negative. 
        }
        if (target == 0) {
            vec.push_back(v);
        }
        int n = candidates.size();
        for (int i = start; i < n; i++) {
            v.push_back(candidates[i]);

            // solve(vec, candidates, v, i+1, target - candidates[i]); 
            // *** i+1 is not passed because, same element can be used again.
            // what we learn?
            // solve(i) will start for() loop from i
            // but at some point, his target will be less than 0.
            // then it will return and i will increase to another
            // value. this value will continue to work.

            // *** what if we pass i+1?
            // then same combination will be repeated.
            // because same path generates multiple times.


            solve(vec, candidates, v, i, target - candidates[i]);

            v.pop_back();
        }
    }

    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector <vector<int>> vec;
        vector<int> v;
        solve(vec, candidates, v, 0, target);
        return vec;

    }
};