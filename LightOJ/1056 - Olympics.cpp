#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)

#define pi acos(-1)

using namespace std;

int main() {
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;
        double a, b;
        double alpha, theta;
        double x;

        scanf("%lf : %lf", &a, &b);

        alpha = atan(a / b * 1.0);
        theta = pi - 2.0 * alpha;


        x = 400.0 / (2.0 * a + theta * sqrt(a * a + b * b));

        printf("Case %lld: %.10f %.10f\n", t, a * x * 1.0, b * x * 1.0);
    }

    return 0;
}
 