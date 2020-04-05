//
// Created by heisenberg on 4/4/20.
//

#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

string makeBigString(string ips) {
    string s;
    for (int i = 0; i < ips.length(); i++) {
        int num = ips[i] - '0';
        for (int j = 0; j < num; j++) {
            s = s + '(';
        }
        s = s + ips[i];
        for (int j = 0; j < num; j++) {
            s = s + ')';
        }
    }
    return s;
}

string solve(string s) {
    stack<char> stk;
    stk.push(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '(' && stk.top() == ')') {
            stk.pop();
            continue;
        }
        stk.push(s[i]);
    }
    string ans;
    while (!stk.empty()) {
        ans = ans + stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
//    fi;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0, T, N;

    cin >> T;
    while (T--) {
        t++;
        cout << "Case #" << t << ": ";
        string ips, s;
        cin >> ips;
        s = makeBigString(ips);

        string ans = solve(s);
        cout << ans << endl;
    }

    return 0;
}