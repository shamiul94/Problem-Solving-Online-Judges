/**
@author - Rumman BUET CSE'15
Problem - 1035 - Intelligent Factorial Factorization

Link - http://www.lightoj.com/volume_showproblem.php?problem=1035

Concept-

    No concept. :p
    Easy one. Sieve , array 2D , optimize...etc.

*/


#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define isprime false

int a[110][110];
bool prime[110] = {};
vector<int> v;

/// False == is a prime
void sieve() {
    prime[0] = !isprime;
    prime[1] = !isprime;

    for (ll i = 4; i < 110; i += 2) {
        prime[i] = !isprime;
    }
    for (ll i = 3; i < 110; i += 2) {
        if (prime[i] == isprime) {
            for (ll j = 2 * i; j < 110; j += i) {
                prime[j] = !isprime;
            }
        }
    }

    for (ll i = 0; i < 110; i++) {
        if (prime[i] == isprime) {
            v.push_back(i);
        }
    }
}


void result() {
    for (ll i = 2; i <= 100; i++) {
        ll an;
        an = i;

        for (ll j = 0; j < v.size(); j++) {
            ll c = 0;

            while (an % v[j] == 0 && an > 0) {
                c++;
                an = an / v[j];
            }
            ll d;
            d = v[j];
            a[i][d] = c;

            if (an == 0 || v[j] > an) {
                break;
            }
        }
    }
//    cout << "ni" ;

}

int main() {
//    fi ;
//    fo ;
    ll arr[110] = {};
    sieve();
    result();

    ll T, t = 0;

    scanf("%lld", &T);

    while (T--) {
        t++;
        ll n;
        scanf("%lld", &n);

        for (ll i = 2; i <= n; i++) {
            ll last = 2;
            for (ll j = 2; j <= 100; j++) {
                if (prime[j] == isprime) {
                    arr[j] += a[i][j];
                }
            }
        }

        printf("Case %lld: %lld = ", t, n);

        ll k = 0;

        for (ll i = 2; i <= 100; i++) {
            if (arr[i] >= 1) {
                if (k == 1) {
                    printf(" * %lld (%lld)", i, arr[i]);
                } else {
                    printf("%lld (%lld)", i, arr[i]);
                    k = 1;
                }
            }
        }
        printf("\n");

        for (ll i = 0; i < 110; i++) {
            arr[i] = 0;
        }

    }

    return 0;
}