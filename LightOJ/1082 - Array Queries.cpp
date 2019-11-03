#include <bits/stdc++.h>

#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

using namespace std;

ll N, q;
ll i, j;

int *arr;
int *seg;

int conseg(int lo, int hi, int sp) {
    if (lo == hi) {
        seg[sp] = arr[lo];
        return seg[sp];
    }
    ll mid;
    mid = (lo + hi) / 2;

    seg[sp] = min(conseg(mid + 1, hi, 2 * sp + 2), conseg(lo, mid, 2 * sp + 1));
    return seg[sp];
}

void initseg() {
    ll max_size, x;
    x = ceil(log2(N)) + 1;
    max_size = pow(2, x) - 1;

    free(seg);
    seg = new int[max_size];
    for (ll i = 0; i < max_size; i++) {
        seg[i] = 9999;
    }
    conseg(0, N - 1, 0);
}

void consarr() {
    free(arr);
    arr = new int[N + 10];

    for (ll i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

int query(int lo, int hi, int pos) {
    if (i <= lo && j >= hi) {
        return seg[pos];
    }
    if (j < lo || i > hi) {
        return INT_MAX;
    }

    int mid;
    mid = (lo + hi) / 2;

    return min(query(lo, mid, 2 * pos + 1), query(mid + 1, hi, 2 * pos + 2));
}

int main() {
//    fi ;
//    fo ;

    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;
        scanf("%lld %lld", &N, &q);
        consarr();
        initseg();

        printf("Case %d:\n", t);
        while (q--) {
            scanf("%lld %lld", &i, &j);
            i--;
            j--;
            int p;
            p = query(0, N - 1, 0);
            printf("%d\n", p);
        }
    }

    return 0;
}
 