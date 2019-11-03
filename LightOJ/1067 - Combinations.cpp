#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define m 1000003

vector<int> v;


ll bigmod(ll b, ll p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 1) {
        return (((b % m) * (bigmod(b, p - 1) % m)) % m);
    } else {
        return (((bigmod(b, p / 2) % m) * (bigmod(b, p / 2) % m)) % m);
    }
}

/***
Just saving the values of factorials in the vector is the work of the
vset() function...
*/

void vset() {
    v.push_back(1 % m);
    for (ll i = 1; i <= 1000000 + 7; i++) {
        v.push_back(((i % m) * (v[i - 1] % m)) % m);
    }
}

/*** Extended Euclid Algorithm can be used.
But I didn't use it. why?
Ans: As we can see , m == 1000003 ; is a prime number.
So, gcd( a , m ) must be equal to 1
Now from Fermat's little theorem we cn see-
1. a^(p-1) = 1 (mod p)
2. a^p  = a (mod p)
from 2 we can see, a^p = a (mod p)
dividing both side by a ; we get,
   a^(p-1) = 1 (mod p)
=> a * ( a^(p-2)) = 1 (mod p)
 
So, we can easily say ,  a^(p-2) is the modular inverse of a
Now , see , we could use extended Euclid formula , ax + by = gcd(a,b)
where , a is the number , and b would be m and x would be modular arithmatic
but it could get us negative
number which would take some more work to get in positive.
*/

//void viset()
//{
//    ll x , y , a ;
//    vi.push_back(0) ;
//
//    for(ll i = 1 ; i<= 1000003 ; i++)
//    {
//        a = bigmod(v[i] , m-2) ;
//
//        vi.push_back(a) ;
//    }
//}


ll C(ll n, ll r) {
    /// nCr = n! / ( (n-r)! * r! ) .

    ll ans;
    ans = ((v[n] % m) * (bigmod(v[r], m - 2) * bigmod(v[n - r], m - 2)) % m) % m;

    return ans;
}


int main() {
//    freopen("out.txt","w",stdout);
    vset();
    ll T, t = 0;
    scanf("%lld", &T);

    ll ans, n, r;

    while (T--) {
        t++;
        scanf("%lld %lld", &n, &r);
        ans = C(n, r);
        printf("Case %lld: %lld\n", t, ans);
    }
    return 0;

}
 