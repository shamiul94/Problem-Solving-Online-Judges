/**
@author - Rumman BUET CSE'15

Problem - 1007 - Mathematically Hard
Link - http://www.lightoj.com/volume_showproblem.php?problem=1007

Concept -
Euler Totient Function :

    You are given a number n . How many relative primes has this number those are smaller
    than n ?
    Ans: Euler has given this formula for that.

        Phi = n * (1 - 1/p1) * (1- 1/p2) * (1- 1/p3)*....*( 1 - 1/Pn)
    where , p1 , p1 , p3, .... - are the prime divisors of n

    ** Now all you have to do is optimization.

    How is that?
    Ans:
        *Memory: I can take 5*10^6 sized array of even Unsigned Long Long if I declare it globally
        or by malloc() ;

        *At first , use sieve , then get all phi of the numbers. And then squares , and sum of
        previous ones ( Similar to Fibonacci series) .

        * ans = phi[i]-phi[i-1] ;

        So, this is the rule.
*/


#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long /// ULL ***
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)

#define sz 5000007

bool prime[sz] = {true};
vector<ll> v;

void seive() {
//    cout << "lI" << endl ;

    for (ll i = 0; i < sz; i++) {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;

    for (ll i = 4; i < sz; i += 2) {
        prime[i] = false;
    }

//cout << "mi" ;
    for (ll i = 3; 2 * i <= sz; i += 2) {
        if (prime[i] == true) {
            for (ll j = 2 * i; j < sz; j += i) {
                prime[j] = false;
            }
        }
    }
}


void primegenerator() {
//     cout << "hi";
    for (ll i = 0; i < sz; i++) {
        if (prime[i] == true) {
            v.push_back(i);
        }
    }
//cout << "jikk" ;
}

ll phi[sz];

void Phigenerator() {
    for (ll i = 0; i < sz; i++) {
        phi[i] = i;
    }

    for (ll i = 0; i < v.size(); i++) {
        for (ll j = v[i]; j < sz; j += v[i]) {
//            cout << phi[j] << " " << v[i]-1 << " " << v[i] << endl ;
            phi[j] = (phi[j] * (v[i] - 1)) / v[i];

//            cout << phi[j] << " " << v[i]-1 << " " << v[i] << endl ;

        }
    }

    for (ll i = 1; i < sz; i++) {
        phi[i] = phi[i] * phi[i];
        phi[i] = phi[i] + phi[i - 1];
    }
}

int main() {
//    fi;
//    fo ;
    seive();
    primegenerator();
    Phigenerator();

//    for(ll i = 0 ; i< 100 ; i++ )
//    {
//        cout << i << " - "  << phi[i] << endl ;
//    }


    ll T, t = 0;
    scanf("%llu", &T);

    while (T--) {
        t++;
        ll a, b;
        ll ans;

        scanf("%llu %llu", &a, &b);

        if (a > b) {
            swap(a, b);
        }

        ans = phi[b] - phi[a - 1];

        printf("Case %llu: %llu\n", t, ans);
    }

//   cout << phi[200000] << endl ;
    return 0;
}