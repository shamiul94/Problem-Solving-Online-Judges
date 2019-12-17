//
// Created by shamiul93 on 12/15/19.
//
#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;


inline bool ends_with(std::string const &value, std::string const &ending) {
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int main() {
//    fi;
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (ends_with(s, "po")) {
            cout << "FILIPINO" << endl;
        } else if (ends_with(s, "desu") || ends_with(s, "masu")) {
            cout << "JAPANESE" << endl;
        } else if (ends_with(s, "mnida")) {
            cout << "KOREAN" << endl;
        }
    }
    return 0;
}
