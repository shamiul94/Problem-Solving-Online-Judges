#include <bits/stdc++.h>

#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 100009
using namespace std;


ll i, j, idx, N;

class node {
public:
    ll zero, one, two, prop;

    node() {
        one = two = zero = prop = 0;

    }
} seg[mx * 4];


node build(ll lo, ll hi, ll sp) {
    if (lo == hi) {
        seg[sp].zero = seg[sp].zero + 1;
        return seg[sp];
    }
    ll mid;
    mid = (lo + hi) / 2;

    node l, r;
    l = build(lo, mid, 2 * sp + 1);
    r = build(mid + 1, hi, 2 * sp + 2);

    seg[sp].zero = l.zero + r.zero;
//    seg[sp].one = l.one + r.one ;
//    seg[sp].two = l.two + r.two ;
    return seg[sp];
}


node propagate(node a, ll x) {
    a.prop += x;
    swap(a.zero, a.one);
    swap(a.zero, a.two);
    return a;
}


node loopPropagate(node a, ll x) {
    for (ll m = 0; m < x; m++) {
        swap(a.zero, a.one);
        swap(a.zero, a.two);
    }
    return a;
}


node update(ll lo, ll hi, ll sp, ll x) {
    if (lo > j || hi < i) {
        node n;
        return n;
    }
    if (lo >= i && hi <= j) {
        seg[sp] = propagate(seg[sp], x);
        return seg[sp];
    }
    ll mid;
    mid = (lo + hi) / 2;

    update(lo, mid, 2 * sp + 1, x);
    update(mid + 1, hi, 2 * sp + 2, x);

    seg[sp].zero = seg[2 * sp + 1].zero + seg[2 * sp + 2].zero;
    seg[sp].one = seg[2 * sp + 1].one + seg[2 * sp + 2].one;
    seg[sp].two = seg[2 * sp + 1].two + seg[2 * sp + 2].two;

    seg[sp] = loopPropagate(seg[sp], seg[sp].prop % 3);

    return seg[sp];
}


ll query(ll lo, ll hi, ll sp, ll carry) {
    if (lo > j || hi < i) {
        return 0;
    }
    if (lo >= i && hi <= j) {
        node n;
        n = loopPropagate(seg[sp], carry % 3);
        return n.zero;
    }

    ll mid;
    mid = (lo + hi) / 2;

    ll l, r;
    l = query(lo, mid, 2 * sp + 1, carry + seg[sp].prop);
    r = query(mid + 1, hi, 2 * sp + 2, carry + seg[sp].prop);

    return (l + r);
}

int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);
    while (T--) {
//        cout << "hi" << endl ;

        for (int k = 0; k < mx * 4; k++) {
            seg[k].zero = 0;
            seg[k].one = 0;
            seg[k].two = 0;
            seg[k].prop = 0;
        }
        t++;
        ll q;
        scanf("%lld %lld", &N, &q);
        build(0, N - 1, 0);
        printf("Case %lld:\n", t);
        while (q--) {
            ll c;
            scanf("%lld %lld %lld", &c, &i, &j);
            if (c == 0) {
                update(0, N - 1, 0, 1);
            } else {
                ll ans;
                ans = query(0, N - 1, 0, 0);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}

