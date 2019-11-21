class Solution1 {
public:
    void solve(vector <vector<int>> &vec, vector<int> &nums, vector<int> &v, int start) {

        vec.push_back(v);

        for (int i = start; i < nums.size(); i++) {
            v.push_back(nums[i]);
            solve(vec, nums, v, i + 1);
            v.pop_back();
        }
    }

    vector <vector<int>> subsets(vector<int> &nums) {
        vector <vector<int>> vec;
        vector<int> v;
        solve(vec, nums, v, 0);
        return vec;
    }
};

////////////

// 94%, 97%
// this is basically bfs without the queue
// the vec<> is working as the queue.
// how does it work?
// suppose you have 1,2,3
// at first, vec = {null}
// at second, vec = {null}, {null+1=1}
// at third, vec = {null}, {1}, {null+2 = 2}, {1 + 2 = 1,2}
// at fourth, vec = {null}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3}


class Solution {
public:

    vector <vector<int>> subsets(vector<int> &nums) {
        vector <vector<int>> vec;
        vector<int> u;
        vec.push_back(u);


        for (int i = 0; i < nums.size(); i++) {
            int n = vec.size();
            for (int j = 0; j < n; j++) {
                // cout << vec.size()<<endl;
                vector<int> v = vec[j];
                v.push_back(nums[i]);
                vec.push_back(v);
            }
        }
        return vec;
    }
};
