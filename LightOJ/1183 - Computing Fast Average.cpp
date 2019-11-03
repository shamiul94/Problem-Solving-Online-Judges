#include <bits/stdc++.h>

#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 100009
using namespace std;
ll N, i, j;

struct node {
    ll sum;
    ll prop;
};

node seg[mx * 4];


void pushdown(ll lo, ll hi, ll sp) {
    if (seg[sp].prop != -1) {
        seg[sp].sum = (hi - lo + 1) * seg[sp].prop;

        if (lo != hi)
            seg[2 * sp + 1].prop = seg[sp].prop, seg[2 * sp + 2].prop = seg[sp].prop;

        seg[sp].prop = -1;
    }
}


void update(ll lo, ll hi, ll sp, ll x) {
    pushdown(lo, hi, sp);

    if (lo > j || hi < i) {
        return;
    }

    if (lo >= i && hi <= j) {
        seg[sp].sum = (hi - lo + 1) * x;

        if (lo != hi)
            seg[2 * sp + 1].prop = x, seg[2 * sp + 2].prop = x;

        seg[sp].prop = -1;

        return;
    }

    ll mid;
    mid = (lo + hi) / 2;


    update(lo, mid, 2 * sp + 1, x);
    update(mid + 1, hi, 2 * sp + 2, x);

    seg[sp].sum = seg[2 * sp + 1].sum + seg[2 * sp + 2].sum;


    return;
}


ll query(ll lo, ll hi, ll sp) {
    pushdown(lo, hi, sp);

    if (lo > j || hi < i) {
        return 0;
    }

    if (lo >= i && hi <= j)
        return seg[sp].sum;

    ll mid;
    mid = (lo + hi) / 2;

    ll l, r;

    l = query(lo, mid, 2 * sp + 1);
    r = query(mid + 1, hi, 2 * sp + 2);

    return l + r;
}


ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
//    fi ;
//    fo ;
    ll T;
    scanf("%lld", &T);
    ll t = 0;
    ll q, c;
    while (T--) {
        for (ll k = 0; k < mx * 4; k++) {
            seg[k].sum = 0;
            seg[k].prop = -1;
        }

        t++;
        scanf("%lld %lld", &N, &q);
        printf("Case %lld:\n", t);
        while (q--) {
            scanf("%lld", &c);
            if (c == 2) {
                scanf("%lld %lld", &i, &j);
                ll ans, n;
                n = j - i + 1;
                ans = query(0, N - 1, 0);
//                cout << ans << endl ;
                if (ans % n == 0) {
                    printf("%lld\n", ans / n);
                } else {
                    printf("%lld/%lld\n", ans / gcd(ans, n), n / gcd(ans, n));
                }
            } else if (c == 1) {
                ll v;
                scanf("%lld %lld %lld", &i, &j, &v);
                update(0, N - 1, 0, v);
            }
        }
    }

    return 0;
}