//
// Created by shamiul93 on 12/15/19.
//
#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;


int main() {
    fi;
    int T;
    cin >> T;
    while (T--) {
        int x;
        string s;
        cin >> x;
        cin >> s;

        int l = 0, t = 0;
        int eliminate = 0 ;
        while (l < x) {
            int sL = s[t] - '0';
            string sRight = s.substr(t + 1);
            s = "";
            t = 0;
            eliminate++;
            for (int i = 0; i < sL; i++) {
                s = s + sRight;
            }
            l++;
        }
        cout << (s.length() + eliminate) % (1000000000 + 7) << endl;
    }
    return 0;
}
