//
// Created by shamiul93 on 12/15/19.
//

#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

int main() {
//    fi;
    int n;
    string s;
    string tem;
    cin >> n;
    cin >> s;
    tem = s;

    int ans = 0;
    vector<int> idx_vec;

    for (int i = 0; i < n - 1; i++) {
        if (tem[i] == 'W' && tem[i + 1] == 'W') {
            continue;
        } else if (tem[i] == 'W' && tem[i + 1] == 'B') {
            continue;
        } else if (tem[i] == 'B' && tem[i + 1] == 'W') {
            swap(tem[i], tem[i + 1]);
            ans++;
            idx_vec.push_back(i);
        } else if (tem[i] == 'B' && tem[i + 1] == 'B') {
            tem[i] = 'W';
            tem[i + 1] = 'W';
            ans++;
            idx_vec.push_back(i);
        }
    }

    if (tem[n - 1] == 'B') {
        idx_vec.clear();
        ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'B' && s[i + 1] == 'B') {
                continue;
            } else if (s[i] == 'B' && s[i + 1] == 'W') {
                continue;
            } else if (s[i] == 'W' && s[i + 1] == 'B') {
                swap(s[i], s[i + 1]);
                ans++;
                idx_vec.push_back(i);
            } else if (s[i] == 'W' && s[i + 1] == 'W') {
                s[i] = 'B';
                s[i + 1] = 'B';
                ans++;
                idx_vec.push_back(i);
            }
        }

        if (s[n - 1] == 'W') {
            cout << -1 << endl;
            return 0;
        }

        cout << ans << endl;
        for (int i = 0; i < idx_vec.size(); i++) {
            cout << idx_vec[i] + 1 << " ";
        }
        cout << endl;

        return 0;
    }

    cout << ans << endl;
    for (int i = 0; i < idx_vec.size(); i++) {
        cout << idx_vec[i] + 1 << " ";
    }
    cout << endl;


    return 0;

}