#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool solve() {

    }

    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> Set;
        for (int i = 0; i < wordDict.size(); i++) {
            Set.insert(wordDict[i]);
        }

        vector<bool> dp(wordDict.size(), false);
    }
};