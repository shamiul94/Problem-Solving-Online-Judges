#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define ll long long int

long long int a, b, c, d, e, f;
long long int dp[100000];

//long long int BigMOd(ll N , ll P){
//    if(P==0) return 1 ;
//    if(P%2==0)
//    {
//        ll ret = BigMOd(N , P/2) ;
//        return (((ret%P)*(ret%P))%P) ;
//    }
//    else
//    {
//        return (((N%P)*(BigMOd(N , P-1)%P))%P ) ;
//    }
//
//}


long long int fn(long long int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    if (dp[n] != -1) {
        return dp[n];
    } else {
        dp[n] = ((fn(n - 1) % 10000007 + fn(n - 2) % 10000007 + fn(n - 3) % 10000007 + fn(n - 4) % 10000007 +
                  fn(n - 5) % 10000007 + fn(n - 6) % 10000007) % 10000007);
        return dp[n];
    }
}

int main() {
    //freopen("out.txt","w",stdout);
    long long int n, caseno = 0, cases;
    scanf("%lld", &cases);
    while (cases--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}