#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

#define pii pair<ll, ll>
#define ll long long
using namespace std;

/*
1 --> 1
2 --> 2 1
3 --> 3 2 1
4 --> 4 2 1
5 --> 5 4 2 1
6 --> 6 3 2 1
7 --> 7 6 3 2 1
8 --> 8 4 2 1
9 --> 9 8 4 2 1
10 --> 10 5 4 2 1
11 --> 11 10 5 4 2 1
12 --> 12 6 3 2 1
13 --> 13 12 6 3 2 1
14 --> 14 7 6 3 2 1
15 --> 15 14 7 6 3 2 1
16 --> 16 8 4 2 1
17 --> 17 16 8 4 2 1
18 --> 18 9 8 4 2 1
19 --> 19 18 9 8 4 2 1
20 --> 20 10 5 4 2 1
 */

ll count(ll currLeft, ll currRight, ll n) {
    ll cnt = currRight - currLeft + 1;
    while (currLeft <= n && currRight < n) {
        currLeft = 2 * currLeft;
        currRight = 2 * currRight + 1;
        if (currRight > n) currRight = n;
        cnt += (currRight - currLeft + 1);
    }
    return cnt;
}

ll solve(ll num, ll n) {
    ll cnt;

    if (num % 2 == 0) {
        // even
        cnt = count(num, num + 1, n);
    } else {
        // odd
        cnt = count(num, num, n);
    }
    return cnt;
}

int main() {
    fi;
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll lo, hi, mid;
    ll ans1, ans2;

    // even
    lo = 1; // 2*1 = 2 --> lowest even number
    hi = n / 2; // 2n/2 = n --> highest even number

    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (solve(mid, n) >= k) {
            lo = mid;
        } else hi = mid - 1;
    }

    ans1 = solve(2 * lo, n) >= k ? 2 * lo : 0;


    // odd
    lo = 0; // 2*0+1 = 1 -> lowest odd
    hi = (n - 1) / 2;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (solve(2 * mid + 1, n) >= k) {
            lo = mid;
        } else hi = mid - 1;
    }

    ans2 = solve(2 * lo + 1, n) >= k ? 2 * lo + 1 : 0;
    cout << max(ans1, ans2) << endl;
    return 0;
}











//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int N = 1e6 + 100;
//
//typedef long long ll;
//
//ll n, k;
//
//ll solve_odd(ll x, ll n) {
//    if (x > n) return 0;
//    ll L = x, R = x;
//    ll tot = 1;
//    while (true) {
//        L = 2 * L;
//        R = 2 * R + 1;
//        if (L > n) break;
//        R = min(R, n);
//        tot += (R - L + 1);
//        if (R == n) break;
//    }
//    return tot;
//}
//
//ll solve_even(ll x, ll n) {
//    return solve_odd(x, n) + solve_odd(x + 1, n);
//}
//
//ll solve(ll x) {
//    if (x & 1) return solve_odd(x, n);
//    return solve_even(x, n);
//}
//
//int main() {
//    // freopen("in.txt", "r", stdin);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> n >> k;
////    if(n <= 10) {
////        ll ans = -1;
////        for(int i = 1; i <= n; i++) {
////            if(solve(i) >= k) ans = i;
////        }
////        cout << ans << endl;
////        return 0;
////    }
//    ll lo = 0, hi = (n - 1) / 2;
//    while (lo < hi) {
//        ll mid = (hi + lo + 1) / 2;
//        if (solve(2 * mid + 1) >= k) lo = mid;
//        else hi = mid - 1;
//    }
//    ll cand1 = 2 * lo + 1;
//    if (solve(cand1) < k) cand1 = 0;
//
//    lo = 1, hi = n / 2;
//    while (lo < hi) {
//        ll mid = (hi + lo + 1) / 2;
//        if (solve(2 * mid) >= k) lo = mid;
//        else hi = mid - 1;
//    }
//    ll cand2 = 2 * lo;
//    if (solve(cand2) < k) cand2 = 0;
//
//    cout << max(cand1, cand2) << endl;
//    return 0;
//}
//

//////////////////////////////////////////////////////////////////////////////////////////////

//
// Created by shamiul93 on 12/15/19.
//


//
//int main() {
//    fo;
//    vector<vector<ll>> vec(300);
//    ll n = 250;
//
//    for (int i = 1; i <= n; i++) {
//        int x = i;
//        while (x > 0) {
//            vec[i].push_back(x);
//            if (x % 2 == 0) {
//                x /= 2;
//            } else {
//                x--;
//            }
//        }
//    }
//
//    for (int i = 1; i <= n; i++) {
//        cout << i << " --> ";
//        for (int j = 0; j < vec[i].size(); j++) {
//            cout << vec[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "-----------------" << endl;
//    for (int i = 1; i <= n; i++) {
//        int cnt = 0;
//        for (int j = 1; j <= n; j++) {
//            if (find(vec[j].begin(), vec[j].end(), i) != vec[j].end()) {
//                cnt++;
//            }
//        }
//        cout << i << " -> " << cnt  << endl;
//    }
//
//    return 0;
//}

/*
 *
 */