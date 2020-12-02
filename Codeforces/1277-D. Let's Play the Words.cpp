#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

#define STATE_00 0
#define STATE_01 1
#define STATE_10 2
#define STATE_11 3


using namespace std;

int main() {
//    fi;
    int T;
    cin >> T;
    while (T--) {
        int N;
        string s;
        cin >> N;
        vector<int> vec(4, 0); // (0,0), (0,1), (1,0), (1,1)
        vector<vector<string>> str_vec(4);


        unordered_map<string, int> us;

        for (int i = 1; i <= N; i++) {
            cin >> s;
            int len = static_cast<int>(s.length());
            int idx = 0;

            if (s[0] == '0' && s[len - 1] == '0') {
                idx = STATE_00;
            } else if (s[0] == '0' && s[len - 1] == '1') {
                idx = STATE_01;
            } else if (s[0] == '1' && s[len - 1] == '0') {
                idx = STATE_10;
            } else if (s[0] == '1' && s[len - 1] == '1') {
                idx = STATE_11;
            }

            vec[idx]++;
            str_vec[idx].push_back(s);

            us[s] = i;
        }


        if (vec[STATE_10] == 0 && vec[STATE_01] == 0) {
            if (vec[STATE_00] != 0 && vec[STATE_11] != 0) {
                cout << -1 << endl;
            } else {
                cout << 0 << endl << endl;
            }
            continue;
        }

        int no_01 = vec[STATE_01], no_10 = vec[STATE_10];
        int each = (no_01 + no_10) / 2;
        int min_need = each - min(no_01, no_10);

        int ans = min_need;

        int giver = (no_01 == max(no_01, no_10)) ? STATE_01 : STATE_10;

        int t = 0;
        vector<int> final_vec;
        for (int i = 0; i < str_vec[giver].size() && t < ans; i++) {
            string curr = str_vec[giver][i];
            string rev = curr;
            reverse(rev.begin(), rev.end());

            // not found
            if (us.find(rev) == us.end()) {
                int a = us[curr];
                final_vec.push_back(a);
                us.erase(curr);
                us[rev] = a;
                t++;
                if (t >= ans) break;
            }
        }

        if (final_vec.size() == ans) {
            cout << ans << endl;
            for (int i = 0; i < final_vec.size(); i++) {
                cout << final_vec[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }

    }
    return 0;
}
