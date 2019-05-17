/**
@author - Rumman BUET CSE'15
Problem -
Idea -
Concept -
*/

#include <bits/stdc++.h>

#define PRINT_CASE(ans)                         printf("Case %lld: %lld\n",t, ans)
#define SORT_VECTOR(vec)                        sort((vec).begin(), (vec).end())

#define ll                                      long long int
#define ull                                     unsigned long long
#define ld                                      long double

#define ff                                      first
#define ss                                      second

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define pi acos(-1.0)
#define debug                                   printf("yes\n")
#define what_is(x)                              cout << #x << " is " << x << endl
#define pf                                      printf
#define sf                                      scanf

#define pb                                      push_back
#define mp                                      make_pair
#define eb                                      emplace_back
#define pii                                     pair<int, int>
#define piii                                    pair<pii, int>

#define SQR(a)                                  ((a)*(a))
#define QUBE(a)                                 ((a)*(a)*(a))

#define scanI(a)                                scanf("%d",&a)
#define scanI2(a, b)                             scanI(a) , scanI(b)
#define scanI3(a, b, c)                           scanI(a), scanI(b), scanI(c)
#define scanI4(a, b, c, d)                         scanI(a), scanI(b), scanI(c), scanI(d)

#define sll(a)                                scanf("%lld",&a)
#define sll2(a, b)                             sll(a) , sll(b)
#define sll3(a, b, c)                           sll(a), sll(b), sll(c)
#define sll4(a, b, c, d)                         sll(a), sll(b), sll(c), sll(d)

#define inf LLONG_MAX
#define minf LLONG_MIN
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

using namespace std;

ll BigMod(ll B, ll P, ll M) {
    ll R = 1;
    while (P > 0) {
        if (P % 2 == 1) {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}

void printVec(vector<ll> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int Set(int N, int pos) {
    return N = N | (1 << pos);
}

int reset(int N, int pos) {
    return N = N & ~(1 << pos);
}

bool check(int N, int pos) {
    return (bool) (N & (1 << pos));
}

/************************************** END OF INITIALS ****************************************/

ll N;
vector<ll> sides;

int main() {
//    fi;
//    fo;
    ll T, t = 0, side;

    sll(T);

    while (T--) {
        t++;

        sides.clear();

        sll(N);

        for (ll i = 0; i < N; i++) {
            sll(side);
            sides.push_back(side);
        }
        SORT_VECTOR(sides);
        ll ans = 0;
        for (ll i = 0; i < N; i++) {
            for (ll j = i + 1; j < N; j++) {
                ll a, b, c;
                a = sides[i];
                b = sides[j];
                c = a + b - 1; /*at most*/
                ans += (upper_bound(sides.begin(), sides.end(), c) - sides.begin() - 1) - j;
            }
        }

        PRINT_CASE(ans);
    }
    return 0;
}