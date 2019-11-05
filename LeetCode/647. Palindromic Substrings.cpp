#include <bits/stdc++.h>

#define DEBUG 1
using namespace std;


// copy from here
// change this part only
class Solution {
public:
    int countSubstrings(string s) {
        int N;
        N = static_cast<int>(s.length());
        int palin = 0;
        for (int i = 0; i < N; i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r <= N - 1) {
                if (s[l--] == s[r++]) {
                    palin++;
                } else {
                    break;
                }
            }
        }

        for (int i = 0; i < N - 1; i++) {
            int l = i;
            int r = i + 1;

            while (l >= 0 && r <= N - 1) {
                if (s[l--] == s[r++]) {
                    palin++;
                } else {
                    break;
                }
            }
        }

        return palin;
    }
};
// change ends here

#ifdef DEBUG

int main() {
    Solution sln = Solution();
    /* call sln.function() here */
    cout << sln.countSubstrings("abaa") << endl;
    return 0;
}

#endif