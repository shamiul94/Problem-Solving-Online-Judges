#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

int main() {
//    fi;
    vector<long long int> seed{1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};
    vector<long long int> key{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long long int> beautifulNumbers;

    for (long long i : seed) {
        for (long long j : key) {
            beautifulNumbers.push_back(i * j);
        }
    }


    int T;
    cin >> T;
    while (T--) {
        long long int age;
        cin >> age;
        int ans = 0;
        int L = static_cast<int>(beautifulNumbers.size());
        for (int i = 0; i < L; i++) {
            if (beautifulNumbers[i] <= age) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
