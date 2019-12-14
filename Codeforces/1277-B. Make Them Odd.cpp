#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

int main() {
//    fi;
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        set<int, greater<int>> s;
        for (int i = 0; i < N; i++) {
            int n;
            cin >> n;
            if (n % 2 == 0) {
                s.insert(n);
            }
        }
//        cout << N << endl;
        set<int>::iterator it;
//        vector<int>::iterator it;

        int ans = 0;
        for (it = s.begin(); it != s.end() && !s.empty(); it++) {
            int n = *it;
//            cout << n << endl;

            if (n % 2 == 0) {
                n = n / 2;

                ans++;
//                s.erase(it);
                if (n % 2 == 0) s.insert(n);

//                if (!s.empty()) it = s.begin();
//                else break;

            }
//            else {
//                s.erase(it);
//                if (!s.empty()) it = s.begin();
//                else break;
//            }
        }
        cout << ans << endl;
    }
    return 0;
}