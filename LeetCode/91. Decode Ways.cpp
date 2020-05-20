class Solution {
public:

    int solve(string &s, int idx, vector<int> &dp) {
        if (s[idx] == '0') {
            return dp[idx] = 0;
        }

        if (idx >= s.length() - 1) {
            return 1;
        }

        if (dp[idx] != -1) return dp[idx];

        int ret = 0;


        if (s[idx] == '1') {
            if (idx + 1 < s.length()) {
                ret = solve(s, idx + 1, dp) + solve(s, idx + 2, dp);
            } else {
                ret = solve(s, idx + 1, dp);
            }
        } else if (s[idx] == '2') {
            if (idx + 1 < s.length()) {
                if (s[idx + 1] >= '0' && s[idx + 1] <= '6') {
                    ret = solve(s, idx + 1, dp) + solve(s, idx + 2, dp);
                } else {
                    ret = solve(s, idx + 1, dp);
                }
            }
        } else {
            ret = solve(s, idx + 1, dp);
        }

        return dp[idx] = ret;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return solve(s, 0, dp);
    }
};