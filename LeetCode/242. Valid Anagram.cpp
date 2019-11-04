#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // easy problem but cool trick
    bool isAnagramArr(string s, string t) {

        if (s.length() != t.length())
            return false;

        int count[26] = {0};
        int n = s.length();

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i : count)
            if (i != 0) return false;

        return true;

    }

    // was trying to reduce memory. doesnt work for 'aa', 'bb' . not possible may be.
//    bool isAnagram(string s, string t) {
//
//        if (s.length() != t.length())
//            return false;
//
//        int alphabate = 0;
//        int n = s.length();
//
//        for (int i = 0; i < n; i++) {
//            int idxS = s[i] - 'a';
//            int idxT = t[i] - 'a';
//
//            alphabate = alphabate ^ (1 << idxS) ^ (1 << idxT);
//
//        }
//
//        return alphabate == 0;
//    }
};

int main() {
    Solution s;
//    cout << s.isAnagram("aaab", "abbb");
}