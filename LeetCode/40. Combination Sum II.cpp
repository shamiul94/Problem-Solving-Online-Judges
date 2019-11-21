class Solution {
public:

    void solve(vector <vector<int>> &vec, vector<int> &candidates, vector<int> &v, int start, int target) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            vec.push_back(v);
        }

        int n = candidates.size();
        for (int i = start; i < n; i++) {


            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // this line is added for just optimization.
            if (target - candidates[i] < 0) break;

            // this line is also added for just optimization. 
            // preventing the code from going to one extra step. 
            if (candidates[i] == target) {
                v.push_back(target);
                vec.push_back(v);
                v.pop_back();
                break;
            }

            v.push_back(candidates[i]);
            solve(vec, candidates, v, i + 1, target - candidates[i]);
            v.pop_back();
        }

    }

    vector <vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <vector<int>> vec;
        vector<int> v;
        solve(vec, candidates, v, 0, target);
        return vec;
    }
};