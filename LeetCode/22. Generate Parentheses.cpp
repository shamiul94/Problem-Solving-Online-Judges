class Solution {
public:

    void solve(vector <string> &v, string &str, int first, int second, int n) {
        if (first > n || second > n) return;

        if (first == n && second == n) {
            v.push_back(str);
            return;
        }

        if (second > first) return;


        str = str + '(';
        solve(v, str, first + 1, second, n);
        str.pop_back();
        str = str + ')';
        solve(v, str, first, second + 1, n);
        str.pop_back();
    }

    vector <string> generateParenthesis(int n) {
        vector <string> v;
        string s;
        solve(v, s, 0, 0, n);
        return v;
    }
};