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


    string solve1(int l, int r) {
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
                string nextLevelUnitString = solve1(newL, newR);
                for (int t = 0; t < newRepeat; t++) {
                    ret += nextLevelUnitString;
                }
            }
        }
        return ret;
    }


    // memory optimized - by eliminating stream
    string solve2(int l, int r) {
        string ret = "";

        for (int i = l; i <= r;) {
            if (isAlpha(s[i])) {
                ret += s[i];
                i++;
            } else if (isDigit(s[i])) {
                int newRepeat = 0;

                while (isDigit(s[i])) {
                    newRepeat = 10 * newRepeat + (s[i] - '0');
                    i++;
                }
                // now i == '['
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
                string nextLevelUnitString = solve2(newL, newR);
                for (int t = 0; t < newRepeat; t++) {
                    ret += nextLevelUnitString;
                }
            }
        }
        return ret;
    }

    // recursive but time efficient. 0 ms. (100%)
    // This might be the most beautiful piece of recursive function I have seen in my entire life.
    // This elegant piece of gold is inspired from here -
    // https://leetcode.com/problems/decode-string/discuss/87544/Clean-C%2B%2B-Recursive-Solution-with-Explanation
    string solve(int &idx) {
        string ret = "";

        int repeat = 0;
        for (; idx < s.size(); idx++) {
            if (isAlpha(s[idx])) {
                ret += s[idx];
            } else if (isDigit(s[idx])) {
                repeat = 10 * repeat + (s[idx] - '0');
            } else if (s[idx] == '[') {
                string get = solve(++idx);
                for (int i = 0; i < repeat; i++) {
                    ret += get;
                }
                repeat = 0;
            } else if (s[idx] == ']') {
                return ret;
            }
        }
        return ret;
    }


    string decodeString(string str) {
        s = str;
        int n = s.length();
//        return solve(0, n - 1);
        int idx = 0;
        return solve(idx);
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