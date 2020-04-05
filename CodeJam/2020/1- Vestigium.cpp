//
// Created by heisenberg on 4/4/20.
//

#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

int main() {
//    fi;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0, T, N;

    cin >> T;
    while (T--) {
        t++;
        cout << "Case #" << t << ": ";
        cin >> N;
        vector<vector<int>> v;
        for (int i = 0; i < N; i++) {
            v.emplace_back();
            for (int j = 0; j < N; j++) {
                int x;
                cin >> x;
                v[i].emplace_back(x);
            }
        }

        int k = 0;
        for (int i = 0; i < N; i++) {
            k += v[i][i];
        }

        int r = 0, c = 0;

        for (int i = 0; i < N; i++) {
            bool repeat = false;
            unordered_set<int> um;
            um.insert(v[i][0]);
            for (int j = 1; j < N; j++) {
                if (um.find(v[i][j]) != um.end()) { // is there
                    repeat = true;
                    break;
                }
                um.insert(v[i][j]);
            }
            if (repeat) r++;
        }

        for (int i = 0; i < N; i++) {
            bool repeat = false;
            unordered_set<int> um;
            um.insert(v[0][i]);
            for (int j = 1; j < N; j++) {
//                cout << j << " " << i << " " << v[j][i] << "=" << prev << endl;
                if (um.find(v[j][i]) != um.end()) {
                    repeat = true;
                    break;
                }
                um.insert(v[j][i]);
            }
            if (repeat) c++;
        }

        cout << k << " " << r << " " << c << endl;
    }

    return 0;
}