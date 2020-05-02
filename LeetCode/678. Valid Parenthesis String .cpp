//
// Created by heisenberg on 4/19/20.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // ((*))) ---> 1,2, -> 3 (, 2, 1, 0
    //                     2 x, 1, 0, -1*
    //                     1 ), 0, -1*, -2

    // (()))
    bool solve(string &s, int idx, int sum) {
        if (sum < 0) {
            return false;
        }

        if (idx >= s.length() && sum == 0) {
            return true; // we have reached the end w/o any break
        }

        if (idx >= s.length()) return false;

        bool result = false;
        if (s[idx] == '(') {
            result = solve(s, idx + 1, sum + 1);
        } else if (s[idx] == ')') {
            result = solve(s, idx + 1, sum - 1);
        } else {
            result = solve(s, idx + 1, sum + 1) || solve(s, idx + 1, sum) || solve(s, idx + 1, sum - 1);
        }

        return result;
    }

    bool checkValidString(string s) {
        return solve(s, 0, 0);
    }
};
