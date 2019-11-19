class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int N1, N2;
        N1 = s1.length();
        N2 = s2.length();

        unordered_map<char, int> m;
        int unique = 0;

        for (int i = 0; i < N1; i++) {
            // char was not found
            if (m.find(s1[i]) == m.end()) {
                m[s[i]] = 1;
                unique++;
            } else {
                m[s[i]]++;
            }
        }

        int lo, hi;
        int got = 0;
        lo = 0;
        unordered_map<char, int> m2;


        for (hi = 0; hi < N2; hi++) {
            char currChar = s2[hi];
            m2[currChar]++;

            // if it’s not even in s1
            if (m.find(currChar) == m.end()) {
                continue;
            }

            if (m2[currChar] == m[currChar]) {
                got++;
            }


            while (lo <= hi && got == unique) {
                if (hi - lo + 1 == N1) {
                    return true;
                }

                char ch;
                ch = s2[lo];

                m2[ch]--;

// exists in s1
                if (m.find(ch) != m.end()) {
                    if (m2[ch] < m[ch]) {
                        got--;
                    }
                }

                lo++;
            }
        }
        return false;
    }
};
