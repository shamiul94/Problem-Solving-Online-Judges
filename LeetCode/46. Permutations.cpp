// original solution - backtracking
// 19%, 13%

class Solution1 {
public:
    vector<int> numV;
    vector<int> taken;
    vector <vector<int>> ans;
    int numSize;

    void solve(vector<int> v, int idx) {
        if (idx >= numSize) {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < numSize; i++) {
            // it hasn't been occupied yet.
            if (taken[i] == 0) {
                taken[i] = 1;

                v.push_back(numV[i]);
                solve(v, idx + 1);
                v.pop_back();

                taken[i] = 0;
            }
        }
    }

    vector <vector<int>> permute(vector<int> &nums) {

        numV = nums;
        numSize = nums.size();
        vector<int> t(numSize, 0);
        taken = t;

        solve({}, 0);
        return ans;
    }
};

//////////////////


// original solution - backtracking
// 90%, 100%
// best - mine

class Solution {
public:
    int numSize;

    // notice that, we have removed the global variables (member variables like numV, ans)
    // and converted them as some local variable and pass them as reference.
    // although technically should take the same time,
    // global variables are time consuming and memory consuming.
    // avoid them from now on. use reference instead.
    void solve(vector <vector<int>> &ans, vector<int> &numV, int idx) {
        if (idx >= numSize) {
            ans.push_back(numV);
            return;
        }

        // this line is a great optimization of the first solution.
        // we have discarded the taken[] array and changed the numV array instead.
        // why? and how does it work?
        // - if you change the idx th value of the vector with the i th value
        // and change it back after recursion, the recursion function gets the temporary
        // changed vector in it and it works on that temporary changed vector.
        // while working, it can be sure that every thing before it's index is taken
        // and everything after this index is untouched so far.
        // that's because it has got a changed vector where this was done in the previous step
        // of recursion.
        for (int i = idx; i < numSize; i++) {
            // swapping because, I want the next level to start for loop from idx
            // to make that happen i have to take every touched value before
            // idx th position in the numV array so that the next recursion level can
            // start for looping from idx th position
            swap(numV[i], numV[idx]);
            // basic recursion
            solve(ans, numV, idx + 1);
            // swap it back because, now it's time for another choice in the same level.
            swap(numV[i], numV[idx]);
        }
    }

    vector <vector<int>> permute(vector<int> &nums) {
        vector <vector<int>> ans;
        numSize = nums.size();

        solve(ans, nums, 0);
        return ans;
    }
};
