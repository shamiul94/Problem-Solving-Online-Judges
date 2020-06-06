#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int calculate(string s) {
        stack<string> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;

            if (s[i] == '(' || s[i] == '+' || s[i] == '-') {
//                cout << i << "-> " << string(1, s[i]) << endl;
                stk.push(string(1, s[i])); // use string constructor?
                continue;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                int prevI = i;
                int num = 0;
                for (int j = i; j < s.length(); j++) {
                    if (s[j] >= '0' && s[j] <= '9') {
                        num = num * 10 + (s[j] - '0');
                        if (j == s.length() - 1) {
                            i = j;
                            stk.push(to_string(num));
                            break;
                        }
                    } else {
//                        cout << j << " =  " << s[j] << endl;
                        i = j - 1;
                        stk.push(to_string(num));
                        break;
                    }
                }
            }

            if (s[i] == ')') {
                string top = stk.top();
                stk.pop();
                int num = 0;
                int curr = 0;
                while (top != "(") {
                    if (top != "+" && top != "-") {
                        curr = stoi(top);
                        num += curr;
                    } else if (top == "+") {
                        // num += curr;
                    } else if (top == "-") {
                        num += (-2 * curr);
                    }

                    top = stk.top();
                    stk.pop();
                }
                stk.push(to_string(num));
                continue;
            }
        }
        int num = 0;
        int curr = 0;
        string top;
        while (!stk.empty()) {
            top = stk.top();
//            cout << top << endl;
            stk.pop();
            if (top != "+" && top != "-") {
                curr = stoi(top);
                num += curr;
            } else if (top == "+") {
                // num += curr;
            } else if (top == "-") {
                num += (-2 * curr); // overflow?
            }
        }
        return num;
    }
};


int main() {
    Solution s;
    cout << s.calculate(" 2-1 + 2 ") << endl;
}

// 2 + 3 + (3 + 4) - 3 - 4
// 2 + 3 + 7 - 3 - 4