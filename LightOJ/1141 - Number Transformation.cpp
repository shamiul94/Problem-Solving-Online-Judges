///@authorRummanBUETCSE

#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

#define PII pair<int,int>
#define ll long long int

ll prime[1010];
vector<ll> v[1010];

ll s, t;

// 0,1 aren't counted...
void seive() {

    for (ll i = 4; i < 1009; i += 2) {
        prime[i] = -1;
    }

    for (ll i = 3; i <= 501; i += 2) {
        for (ll j = 2 * i; j <= 1003; j += i) {
            prime[j] = -1;
        }
    }
}

void creategraph() {
    for (ll i = 3; i <= 1000; i++) {
        if (i % 2 == 0) {
            v[i].push_back(2);
        }
        for (ll j = 3; j <= 1001; j += 2) {
            if (prime[j] == 0 && j != i && j != 1 && i % j == 0) {
                v[i].push_back(j);
            }
        }
    }
}

ll bfs() {
    queue<ll> q;
    int MoveNumber[1001];
    ll sum;
    memset(MoveNumber, -1, sizeof(MoveNumber));

    q.push(s);
    MoveNumber[s] = 0;
    while (!q.empty()) {
        ll node;
        node = q.front();
        q.pop();
        for (ll i = 0; i < v[node].size(); i++) {
            sum = node + v[node][i];
            if (sum <= t && MoveNumber[sum] == -1) {
                MoveNumber[sum] = MoveNumber[node] + 1;
                q.push(sum);
                if (sum == t)
                    return MoveNumber[sum]; /// at this case , MoveNumber[sum] == MoveNumber[t]
            }
        }
    }

    return MoveNumber[t];
}

int main() {
    seive();
    creategraph();

    ll T, ans, cs = 0;
    cin >> T;
    while (T--) {
        cs++;
        cin >> s >> t;
        ans = bfs();
        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}

