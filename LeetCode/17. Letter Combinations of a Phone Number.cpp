class Solution {
public:

    void solve(vector <string> &ans, vector <string> &map, string &digits, string &curr, int idx) {
        if (idx >= digits.length()) {
            ans.push_back(curr);
            return;
        }

        char c = digits[idx];
        int n = c - '0';

        string letters = map[n];

        for (int i = 0; i < letters.length(); i++) {
            curr += letters[i];
            solve(ans, map, digits, curr, idx + 1);
            curr.pop_back();
        }
    }

    vector <string> letterCombinations(string digits) {
        vector <string> ans;

        if (digits.length() == 0) return ans;

        vector <string> map(10);// 0-9

        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";

        string curr;
        solve(ans, map, digits, curr, 0);
        return ans;
    }
};