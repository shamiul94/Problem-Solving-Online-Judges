#include<bits/stdc++.h>

#define ll long long
#define max3(a, b, c) max(a , max(b,c))
#define min3(a, b, c) min(a , min(b,c))
#define mid3(a, b, c) ( (a+b+c) - max3(a,b,c) - min3(a,b,c) )
#define s(a) (a*a)

using namespace std;

int main() {
    ll T, t = 0;
    scanf("%lld", &T);
    while (T--) {
        t++;
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if (s(max3(a, b, c)) == s(min3(a, b, c)) + s(mid3(a, b, c))) {
            printf("Case %lld: yes\n", t);
        } else {
            printf("Case %lld: no\n", t);
        }
    }
    return 0;
}
 