#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define DEBUG printf("hi\n");
#define DEBUG2 printf("bi\n");

using namespace std;

vector<ll> v;
ll n, q;
ll f, l;

void input() {
    v.clear();
    for (ll i = 0; i < n; i++) {
        ll a;
        scanf("%lld", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());
}

ll LowerBound(ll f) {
    ll lo, hi, mid;
    hi = v.size() - 1;
    lo = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

        if (f == v[mid]) {
            hi = mid - 1;
        } else if (f > v[mid]) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return lo;
}

int main() {
    ios::sync_with_stdio();
//    fo ;
//    fi ;


    ll T, t = 0;

    cin >> T;

    while (T--) {

        t++;
        printf("Case %lld:\n", t);
        scanf("%lld %lld", &n, &q);

        input();

        while (q--) {

            scanf("%lld %lld", &f, &l);

            if (f > l) {
                swap(f, l);
            }

            ll Firstidx, Lastidx, ans;

            Firstidx = LowerBound(f);

            l++;

            Lastidx = LowerBound(l);

//            cout << f << " " << --l << endl ;

//            cout << Firstidx << " " << Lastidx << endl  ;
            ans = Lastidx - Firstidx;

            printf("%lld\n", ans);
//            cout << endl ;
        }
    }

    return 0;
}