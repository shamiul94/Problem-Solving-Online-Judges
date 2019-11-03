#include <bits/stdc++.h>

#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

using namespace std;

int *arr, *seg;
int n, q, v, idx, st, en;


int update(int lo, int hi, int sp, int value) {
    if (hi < idx || lo > idx) {
        return 0;
    }
    if (lo == idx && hi == idx) {
        seg[sp] = value;
        return seg[sp];
    }

    ll mid, left, right;

    mid = (lo + hi) / 2;

    left = 2 * sp + 1;
    right = 2 * sp + 2;

    update(lo, mid, left, value);
    update(mid + 1, hi, right, value);

    seg[sp] = seg[left] + seg[right];
    return seg[sp];
}

//int update(int lo, int hi, int sp , int val)
//{
//    if(lo == idx && hi == idx)
//    {
//        seg[sp] = val ;
//        return seg[sp] ;
//    }
//    if(lo == hi)
//    {
//        return seg[sp] ;
//    }
//
//    ll mid ;
//    mid = (lo + hi) / 2 ;
//
//    seg[sp] = update(lo, mid, 2*sp + 1 , val) + update(mid+1, hi, 2*sp + 2 , val) ;
//    return seg[sp] ;
//}

int querysum(int lo, int hi, int sp) {
    if (hi < st || lo > en) {
        return 0;
    }
    if (lo >= st && hi <= en) {
        return seg[sp];
    }

    ll mid;
    mid = (lo + hi) / 2;
    return querysum(lo, mid, 2 * sp + 1) + querysum(mid + 1, hi, 2 * sp + 2);
}

int conseg(int lo, int hi, int sp) {
    if (lo == hi) {
        seg[sp] = arr[lo];
        return seg[sp];
    }

    ll mid;
    mid = (lo + hi) / 2;

    seg[sp] = conseg(lo, mid, 2 * sp + 1) + conseg(mid + 1, hi, 2 * sp + 2);
    return seg[sp];
}


void initseg() {
    ll x;
    x = ceil(log2(n)) + 1;
    ll len;
    len = pow(2, x) - 1;
    seg = new int[len + 10];
    for (ll i = 0; i < len + 10; i++) {
        seg[i] = 0;
    }
    conseg(0, n - 1, 0);
}


int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);
    while (T--) {
        t++;

        scanf("%d %d", &n, &q);
        arr = new int[n + 10];


        for (ll i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        initseg();


        printf("Case %d:\n", t);

        while (q--) {
            ll cs;
            scanf("%lld", &cs);
            if (cs == 1) {
                scanf("%d", &idx);

                update(0, n - 1, 0, 0);
                printf("%d\n", arr[idx]);
                arr[idx] = 0;
            } else if (cs == 2) {
                scanf("%d %d", &idx, &v);
                arr[idx] = arr[idx] + v;
                update(0, n - 1, 0, arr[idx]);
            } else {
                scanf("%d %d", &st, &en);
                int ans;
                ans = querysum(0, n - 1, 0);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
 