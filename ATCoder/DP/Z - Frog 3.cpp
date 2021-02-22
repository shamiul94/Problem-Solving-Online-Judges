#include <bits/stdc++.h>

#define ll long long int


#define fi                                      freopen("C:/Users/User/OneDrive/Documents/Programming/Problem-Solving-Online-Judges/in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

ll N, C;
vector<ll> heights;
vector<ll> dp(N, -1);

ll cost(int i, int j) {
    return (heights[j] - heights[i]) * (heights[j] - heights[i]) + C;
}

ll solve(int i) {

    cout << "ji - " << i << endl;

    if (i == N - 1)
        return dp[i] = 0;

    if (dp[i] != -1)
        return dp[i];

    for (int j = i + 1; j < N; j++) {
        dp[i] = min(dp[i], cost(i, j) + solve(j));
    }
    return dp[i];
}

int main() {
     fi;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // cout << "hello" << endl;

    scanf("%lld %lld", &N, &C);
//    cout << N << " " << C;

    for (ll i = 0; i < N; i++) {
        ll h;
        scanf("%lld", &h);
        heights.push_back(h);
//        cout << h << endl;
    }

    cout << solve(0) << endl;

    return 0;
}