#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    // " 123" v
    // "  abc 123" n
    // "123 adad 123" v
    // " +123 a 23" v
    // " sf -23" n
    // "   -23"
    // " - 23"
    // "-2147483649"

    string lessThanMini(string str) {
        string mini = "-2147483648";
        string ans;

        // -00000000000000000000000009 ??
        if (str == mini) {
            return mini;
        }
        if (str.length() > mini.length()) {
            ans = mini;
        } else if (str.length() < mini.length()) {
            ans = str;
        } else {
            for (int i = 1; i < mini.length(); i++) {
                if (str[i] == mini[i]) {
                    continue;
                } else if (str[i] < mini[i]) {
                    ans = str;
                    break;
                } else {
                    ans = mini;
                    break;
                }
            }
        }
//        cout << "less: " <<  str << endl;
        return ans;
    }

    string greaterThanMaxi(string str) {
        string maxi = "2147483647";
        string ans;

        if (str == maxi) return maxi;
        if (str.length() > maxi.length()) {
            ans = maxi;
        } else if (str.length() < maxi.length()) {
            ans = str;
        } else {
            for (int i = 0; i < maxi.length(); i++) {
                if (str[i] == maxi[i]) {
                    continue;
                } else if (str[i] < maxi[i]) {
                    ans = str;
                    break;
                } else {
                    ans = maxi;
                    break;
                }
            }
        }
//        cout << "jkjk " << str << endl;
        return ans;
    }

    int strToInt(string &str, int sum, int idx) {
        int sign = 1;
        if (str[0] == '-') {
            sign = -1;
        }
        int ans = 0;
//        cout << str << endl;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '+' || str[i] == '-') {
                continue;
            }
            ans = ans * 10 + sign * (str[i] - '0');
        }
        return ans;
    }

    string cleanZero(string &str) {
        // -00000000000000000000001
        // 0000000000000001
        string ans;
        bool stretchEnded = false;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '-' || str[i] == '+') {
                ans += str[i];
                continue;
            }
            if (str[i] == '0') {
                if (!stretchEnded) {
                    continue;
                } else {
                    ans += str[i];
                }
            } else {
                stretchEnded = true;
                ans += str[i];
            }
        }
//        cout << "ba " << ans << endl;
        return ans;
    }

    int myAtoi(string str) {
        string ans;
        bool ignoredAllSpaces = false;
        bool signSet = false;
        bool integerFound = false;

        for (int i = 0; i < str.length(); i++) {
            if (!ignoredAllSpaces) {
                if (str[i] == ' ') {
                    continue;
                } else {
                    ignoredAllSpaces = true;
                }
            }
            if (!signSet) {
                if (str[i] == '+' || str[i] == '-') {
                    signSet = true;
                    ans += str[i];
                    continue;
                } else if (str[i] >= '0' && str[i] <= '9') {
                    signSet = true;
                    integerFound = true;
                    ans += str[i];
                    continue;
                } else {
                    ans = "0";
                    break;
                }
            } else {
                if (!integerFound) {
                    if (str[i] >= '0' && str[i] <= '9') {
                        integerFound = true;
                        ans += str[i];
                        continue;
                    } else {
                        ans = "0";
                        break;
                    }
                } else {
                    if (str[i] >= '0' && str[i] <= '9') {
                        ans += str[i];
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }

        if (ans == "0") {
            return 0;
        }
        ans = cleanZero(ans);
        if (ans[0] == '-') {
            ans = lessThanMini(ans);
//            cout << strToInt(ans, 0, 0) << endl;
            return strToInt(ans, 0, 0);
        } else {
            if (ans[0] == '+') {
                ans[0] = '0';
                ans = cleanZero(ans);
                ans = greaterThanMaxi(ans);
                cout << ans << endl;
                return strToInt(ans, 0, 0);
            } else {
                ans = greaterThanMaxi(ans);
                return strToInt(ans, 0, 0);
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.myAtoi(" 1175109307q7") << endl;
    return 0;
}