//
// Created by shamiul93 on 12/15/19.
//

#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

bool set1Possible(int a, int b, int c, int d) {
    return (a > 0 && d > 0);
}


bool set2Possible(int a, int b, int c, int d) {
    return (b > 0 && c > 0 && d > 0);
}


int main() {
//    fi;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int ans = 0;

    while (set1Possible(a, b, c, d) || set2Possible(a, b, c, d)) {
        if (set1Possible(a, b, c, d) && set2Possible(a, b, c, d)) {
            if (e >= f) {
                a--;
                d--;
                ans += e;
            } else {
                b--;
                c--;
                d--;
                ans += f;
            }
        } else if (set1Possible(a, b, c, d)) {
            a--;
            d--;
            ans += e;
        } else if (set2Possible(a, b, c, d)) {
            b--;
            c--;
            d--;
            ans += f;
        }
    }
    cout << ans << endl;
    return 0;
}