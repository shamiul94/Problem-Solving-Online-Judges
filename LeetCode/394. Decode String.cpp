//
// Created by shamiul93 on 11/5/19.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string s;

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }


    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }


    string solve(int l, int r) {
        string ret = "";

        for (int i = l; i <= r;) {
            if (isAlpha(s[i])) {
                ret += s[i];
                i++;
            } else if (isDigit(s[i])) {
                string num = "";
                while (isDigit(s[i])) {
                    num += s[i];
                    i++;
                }
                // now i == '['
                stringstream stream(num);
                int newRepeat = 0;
                stream >> newRepeat; // repeat == that integer
                int uneven = 0;
                int newL, newR;
                newL = i + 1;
                do {
                    if (s[i] == '[') {
                        uneven++;
                    } else if (s[i] == ']') {
                        uneven--;
                    }
                    i++;
                } while (uneven != 0);
                newR = i - 2;
                string nextLevelUnitString = solve(newL, newR);
                for (int t = 0; t < newRepeat; t++) {
                    ret += nextLevelUnitString;
                }
            }
        }
        return ret;
    }

    string decodeString(string str) {
        s = str;
        int n = s.length();
        return solve(0, n - 1);
    }
};

int main() {
    Solution sln = Solution();
//    cout << sln.decodeString("2[abc]3[cd]ef") << endl;
//    cout << sln.decodeString("3[a2[c]]") << endl;
//    cout << sln.decodeString("abcd3[a]abcd2[bc]") << endl;
    cout << sln.decodeString("3[a]2[b4[F]c]") << endl;
}


//s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef"