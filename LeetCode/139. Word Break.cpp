
class Solution {
public:
    bool solve(string &s, unordered_set <string> &Set, vector<bool> &dp) {
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                // cout << s.substr(j, i - j) << endl;
                if (dp[j] == true && Set.find(s.substr(j, i - j)) != Set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

    bool wordBreak(string s, vector <string> &wordDict) {
        unordered_set <string> Set;
        for (int i = 0; i < wordDict.size(); i++) {
            Set.insert(wordDict[i]);
        }

        vector<bool> dp(s.size() + 1, false);
        return solve(s, Set, dp);
    }
};