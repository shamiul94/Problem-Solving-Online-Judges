class Solution {
public:
    int lengthOfLongestSubstring3(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

    int lengthOfLongestSubstring2(string s) {
        if (s == "") return 0;
        // O(1)
        unordered_map<char, int> unique;
        // save the index of this char i have found till now in current substring.

        int i = 0;
        int maxLen = -1;

        //O(n)
        for (int j = 0; j < s.length(); j++) {
            // O(1)
            if (unique.find(s[j]) == unique.end()) // not found
            {
                // O(1)
                unique[s[j]] = j;
                maxLen = max(maxLen, j - i + 1);
            } else { // found
                //O(1)
                i = max(i, unique[s[j]] + 1);
                unique[s[j]] = j;
                maxLen = max(maxLen, j - i + 1);
            }
            cout << i << " " << j << endl;
        }

        return maxLen;
    }
};
// tmmzuxt

// abba
