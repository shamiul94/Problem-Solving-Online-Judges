class Solution {
public:
    bool isAlphaNum(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        if (s.empty()) return true;
        if (s.length() == 1) return true;
        int n, lo, hi;
        n = s.length();

        lo = 0;
        hi = n - 1;
        while (lo <= hi) {
            if (!isAlphaNum(s[lo])) {
                lo++;
                continue;
            }
            if (!isAlphaNum(s[hi])) {
                hi--;
                continue;
            }
            if (tolower(s[lo]) == tolower(s[hi])) {
                lo++;
                hi--;
            } else {
                return false;
            }
        }
        return true;
    }
};
