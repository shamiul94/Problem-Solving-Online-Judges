#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main() {
//    freopen("in.txt","r", stdin );
//    freopen("out.txt","w", stdout );
    int T, t = 0;
    scanf("%d", &T);

    while (T--) {
        t++;
        int m, n;
        scanf("%d %d", &m, &n);
        int a;
        int mul = m * n;
        if (m == 1 || n == 1) {
            a = mul;
        } else if (m == 2 || n == 2) {
            if (n == 2) {
                swap(m, n);
            }

            int r, d;
            r = n % 4;
            d = n / 4;

            if (r == 0) {
                a = d * 4;
            } else if (r == 1) {
                a = d * 4 + 2;
            } else if (r >= 2) {
                a = d * 4 + 4;
            }

        } else if (mul % 2 == 0) {
            a = mul / 2;
        } else {
            a = mul / 2;
            a++;
        }

        printf("Case %d: %d\n", t, a);
    }
    return 0;
}
 