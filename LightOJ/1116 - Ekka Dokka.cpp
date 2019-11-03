#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    long long int w, n, m, test, t = 0;
    cin >> test;
    while (test--) {
        t++;
        cin >> w;
        if (w & 1) {
            printf("Case %lld: Impossible\n", t);
        } else {
            n = w;
            m = 1;
            while (!(n & 1)) {
                n = n / 2;
                m = m * 2;
            }
            printf("Case %lld: %lld %lld\n", t, n, m);
        }
    }

    return 0;
}