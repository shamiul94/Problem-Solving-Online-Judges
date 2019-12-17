#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

int main() {
    fi;
    int T;
    cin >> T;
    while (T--) {
        string s, c;
        cin >> s >> c;
//        cout << s << " " << c << endl;

        int i = 0, j = 0;
        int sLen = s.length();
        int cLen = c.length();
        string ans;
        for (i = 0, j = 0; i < sLen, j < cLen; i++, j++) {
            if (s[i] == c[j]) {
                ans = "---";
                continue;
            }
            if (s[i] < c[j]) {
                ans = s;
                break;
            }
            if (s[i] > c[j]) {
//                cout << s[i] << " " << c[j] << endl;
                bool possible = false;
                ans = "---";
                for (int idx = i + 1; idx < sLen; idx++) {
                    if (s[idx] > c[j]) {
                        ans = "---";
                        continue;
                    }

                    if (s[idx] < c[j]) {
                        possible = true;
                        swap(s[i], s[idx]);
                        ans = s;
                        break;
                    }
                    if (s[idx] == c[j]) {
                        swap(s[i], s[idx]);

                        if (i + 1 < sLen && j + 1 < cLen) {
                            if (s.substr(i + 1).compare(c.substr(j + 1)) < 0) {
                                ans = s;
                                possible = true;
                                break;
                            } else if (s.substr(i + 1).compare(c.substr(j + 1)) == 0) {
                                ans = "---";
                                possible = false;
                                break;
                            } else {
                                ans = "---";
                                possible = false;
                                break;
                            }
                        } else if (i + 1 < sLen) {
                            ans = "---";
                            possible = false;
                            break;
                        } else if (j + 1 < cLen) {
                            ans = s;
                            possible = true;
                            break;
                        } else {
                            ans = "---";
                            possible = false;
                            break;
                        }
                    }
                }
            }
//            if (ans != "#") {
                break;
//            }
        }
        cout << ans << endl;
    }
    return 0;
}
