// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define inf LLONG_MAX
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask) /// __builtin_popcount : it's a built in function of GCC. Finds out the numbers of 1 in binary representation.
#define mx 150000

using namespace std;

ll n, m, maxElement, sum;
ll arr[1010] = {};


ll Possible(ll expectedValue) {
    ll currValue = 0, part = 1;

    for (ll i = 0; i < n; i++) {
        currValue += arr[i];
        if (currValue > expectedValue) {
            part++;
            currValue = arr[i];
        }
    }

    return part;
}


ll binarySearch() {
    ll lo, hi, mid;

    ll possibleAns;

    lo = maxElement;
    hi = sum;

    ll part;
    ll k = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

        part = Possible(mid);

        if (part <= m) {
            possibleAns = mid;
            hi = mid - 1;
        } else if (part > m) {
            lo = mid + 1;
        }
    }

    return possibleAns;
}

int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        maxElement = -1 * inf;
        sum = 0;
        t++;

        scanf("%lld %lld", &n, &m);
        for (ll i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);

            sum += arr[i];

            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }

        ll ans = binarySearch();

        printf("Case %lld: ", t);
        printf("%lld\n", ans);
    }
    return 0;
}
