#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

int main() {
//    fi;
//    ios_base::sync_with_stdio(true);
//    cin.tie(NULL);

    int N;
    cin >> N;
//    cout << " N " << N << endl;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int len = static_cast<int>(s.length());
        int ans = 0;

        for (int pos = 0; pos < len; pos++) {
            if (pos + 4 <= len - 1 && s.substr(pos, 5) == "twone") {
//                cout << pos << " " << s.substr(pos, 5) << endl;
                s[pos + 2] = '#';
                ans++;
                pos += 4;
            } else if (pos + 2 <= len - 1 && s.substr(pos, 3) == "two") {
//                cout << pos << " " << s.substr(pos, 3) << endl;

                s[pos + 1] = '#';
                ans++;
                pos += 2;
            } else if (pos + 2 <= len - 1 && s.substr(pos, 3) == "one") {
//                cout << pos << " " << s.substr(pos, 3) << endl;

                s[pos + 1] = '#';
                ans++;
//                cout << pos << endl ;
                pos += 2;
            }
        }
//        cout << s << endl;
        cout << ans << endl;

        for (int j = 0; j < len; j++) {
            if (s[j] == '#') {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}