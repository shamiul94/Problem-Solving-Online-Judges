
#include <bits/stdc++.h>

#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 100009
using namespace std;


class node {
public:
    ll one, zero, prop;

    node() {
        one = 0;
        zero = 0;
        prop = 0;
    }

    node(ll a, ll b) {
        one = a;
        zero = b;
        prop = 0;
    }
};

ll N, i, j, idx;
char str[mx] = {};
node seg[mx * 4] = {};


node build(ll lo, ll hi, ll sp) {
    if (lo == hi) {
        if (str[lo] == '1') {
            seg[sp] = node(1, 0);
        } else {
            seg[sp] = node(0, 1);
        }
        return seg[sp];
    }

    ll mid;
    mid = (lo + hi) / 2;

    node l, r;
    l = build(lo, mid, 2 * sp + 1);
    r = build(mid + 1, hi, 2 * sp + 2);

    seg[sp].zero = l.zero + r.zero;
    seg[sp].one = l.one + r.one;

    return seg[sp];
}

node propagate(node a, ll x) {
    a.prop += x;
    swap(a.zero, a.one);
    return a;
}

node loopPropagate(node a, ll x) {
    for (ll k = 0; k < x; k++) {
        swap(a.zero, a.one);
    }
    return a;
}

node update(ll lo, ll hi, ll sp, ll x) {
    if (lo > j || hi < i) {
        return node(0, 0);
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

    seg[sp] = loopPropagate(seg[sp], x % 2);
    return seg[sp];
}

ll query(ll lo, ll hi, ll sp, ll carry) {
    if (lo > idx || hi < idx) {
        return 0;
    }
    if (lo >= idx && hi <= idx) {
        node n;
        n = loopPropagate(seg[sp], carry % 2);
        if (n.zero == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    ll mid;
    mid = (lo + hi) / 2;
    ll l, r;
    l = query(lo, mid, 2 * sp + 1, carry + seg[sp].prop);
    r = query(mid + 1, hi, 2 * sp + 2, carry + seg[sp].prop);

    return l + r;
}


int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        for (ll k = 0; k < mx; k++) {
            str[k] = '\0';
        }
        for (ll k = 0; k < mx * 4; k++) {
            seg[k].zero = 0;
            seg[k].one = 0;
            seg[k].prop = 0;
        }

        ll q;
        t++;
        printf("Case %lld:\n", t);
        scanf(" %s", str);
        scanf("%lld", &q);
        N = strlen(str);
        build(0, N - 1, 0);
        while (q--) {
            char c;
            scanf(" %c", &c);
            if (c == 'I') {
                scanf("%lld %lld", &i, &j);
                i--;
                j--;
                update(0, N - 1, 0, 1);
            } else {
                scanf("%lld", &idx);
                idx--;
                ll ans;
                ans = query(0, N - 1, 0, 0);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
 