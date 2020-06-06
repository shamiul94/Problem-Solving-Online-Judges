
bool compare(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

class Solution1 {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector <vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            if (ans.size() == 0) {
                ans.push_back(intervals[i]);
                continue;
            }

            vector<int> first = ans.back();
            ans.pop_back();
            vector<int> second = intervals[i];

            if (second[0] > first[1]) {
                ans.push_back(first);
                ans.push_back(second);
            } else {
                vector<int> v;
                v.push_back(first[0]);
                v.push_back(max(first[1], second[1]));
                ans.push_back(v);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector <vector<int>> ans;

        vector<int> extended;
        vector<int> second;

        if (intervals.size() == 0) return ans;

        for (int i = 0; i < intervals.size(); i++) {
            if (i == 0) {
                extended = intervals[i];
                continue;
            }

            second = intervals[i];

            if (second[0] > extended[1]) {
                ans.push_back(extended);
                extended = second;
            } else {
                extended[1] = max(extended[1], second[1]);
            }
        }
        ans.push_back(extended);
        return ans;
    }
};