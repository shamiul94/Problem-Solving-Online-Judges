//
// Created by shamiul93 on 12/15/19.
//

#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

#define pii pair<ll, ll>
#define ll long long
using namespace std;

int main() {
    fi;
    ll n, sx, sy;
    cin >> n >> sx >> sy;

    vector<pii > vec; // x,y

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }

    ll up = 0, down = 0, left = 0, right = 0;
    int len = static_cast<int>(vec.size());
    for (int i = 0; i < len; i++) {

        if (vec[i].first < sx) {
            left++;
        } else if (vec[i].first > sx) {
            right++;
        }

        if (vec[i].second < sy) {
            down++;
        } else if (vec[i].second > sy) {
            up++;
        }
    }
//    cout << right << " " << left << endl;

    ll shawarma_x = sx, shawarma_y = sy;


    if (right == left) {
        shawarma_x = sx;
        if (up > down) {
            shawarma_y = sy + 1;
        } else if (up < down) {
            shawarma_y = sy - 1;
        } else if (up == down) {
            shawarma_y = sy + 1;
        }
    } else if (up == down) {
        shawarma_y = sy;
        if (right > left) {
            shawarma_x = sx + 1;
        } else if (right < left) {
            shawarma_x = sx - 1;
        } else if (right == left) {
            shawarma_x = sx + 1;
        }
    } else if(right > left){

    }


    lse {
        if (right > left) {
            shawarma_x = sx + 1;
        } else if (right < left) {
            shawarma_x = sx - 1;
        }

        if (up > down) {
            shawarma_y = sy + 1;
        } else if (up < down) {
            shawarma_y = sy - 1;
        }
    }


    ll ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        ll dx, dy;
        dx = abs(vec[i].first - shawarma_x);
        dy = abs(vec[i].second - shawarma_y);

        ll sdx = 0, sdy = 0;
        sdx = abs(vec[i].first - sx);
        sdy = abs(vec[i].second - sy);

        ll a = 0, b = 0;
        a = abs(sx - shawarma_x);
        b = abs(sy - shawarma_y);

        cout << "(" << vec[i].first << "," << vec[i].second << ") ==> " <<
             sdx << " : " << dx + a << " ; " << sdy << " : " << dy + b << endl;

        if (sdx == dx + a && sdy == dy + b) {
            ans++;
        }
        cout << "ans: " << ans << endl;
    }

    cout << ans << endl;
    cout << shawarma_x << " " << shawarma_y << endl;
    return 0;
}