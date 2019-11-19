class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sArr[26] = {};
        int pArr[26] = {};

        int Ns = s.length();
        int Np = p.length();

        int unique = 0;
        for (int i = 0; i < Np; i++) {
            if (pArr[p[i] - 'a'] == 0) {
                unique++;
            }
            pArr[p[i] - 'a']++;
        }


        int lo, hi;
        lo = 0;
        int got = 0;

        vector<int> v;
        for (hi = 0; hi < Ns; hi++) {
            sArr[s[hi] - 'a']++;

            // p doesn't have it
            if (pArr[s[hi] - 'a'] == 0) continue;
            if (sArr[s[hi] - 'a'] == pArr[s[hi] - 'a']) {
                got++;
            }

            while (lo <= hi && got == unique) {
                if (hi - lo + 1 == Np) {
                    v.push_back(lo);
                }
                sArr[s[lo] - 'a']--;

// this char is in pArr
                if (pArr[s[lo] - 'a'] != 0) {
                    if (sArr[s[lo] - 'a'] < pArr[s[lo] - 'a']) {
                        got--;
                    }
                }

                lo++;
            }

        }
        return v;
    }
};
