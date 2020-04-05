//
// Created by heisenberg on 4/4/20.
//

#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

int main() {
    fi;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0, T;

    cin >> T;
    while (T--) {
        t++;
        cout << "Case #" << t << ": ";
        int N, K;
        cin >> N >> K;

        vector<int> allPossibleTraces;
        allPossibleTraces.emplace_back(N * (N + 1) / 2);

        for (int i = 1; i <= N; i++) {
            allPossibleTraces.emplace_back(N * i);
        }

        string verdict = "IMPOSSIBLE";
        for (int i = 0; i < allPossibleTraces.size(); i++) {

            if (allPossibleTraces[i] == K) {
                cout << allPossibleTraces[i] << endl;
                verdict = "POSSIBLE";
                break;
            }
        }
        cout << verdict << endl;

        int start;
        for (int i = 0; i < N; i++) {
            start = i;
            for (int j = 0; j < N; j++) {
                cout << 1 + (start % N) << " ";
                start++;
            }
            cout << endl;
        }
    }

    return 0;
}