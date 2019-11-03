
#include <bits/stdc++.h>

#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

long long int solve(long long int num) {
    long long int ans = 1, i, res;
    int neg = 0;
    if (num < 0) {
        neg = 1;
        num *= -1;
    }
    for (i = 2; i * i <= num; i++) {
        if (num % i) continue;
        long long int temp = num;
        res = 0;
        while (temp % i == 0) {
            temp /= i;
            res++;
        }
        if (temp == 1) {

            if (!(neg && res % 2 == 0)) /// if the x is negative then the power can never be even number .
                return res;
        }
    }
    return 1;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int cs, t;
    scanf("%d", &t);
    for (cs = 1; cs <= t; cs++) {
        long long int num;
        scanf("%lld", &num);

        printf("Case %d: %lld\n", cs, solve(num));
    }
    return 0;

}
 