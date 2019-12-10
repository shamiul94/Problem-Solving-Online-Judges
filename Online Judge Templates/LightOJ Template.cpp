/**
@author - Rumman BUET CSE'15
Problem - 
Idea - 
Concept - 
*/

#include <bits/stdc++.h>

#define PRINT_CASE(ans)                         printf("Case %lld: %lld\n",t, ans)
#define SORT_VECTOR(vec)                        sort(vec.begin(), vec.end())
#define print_vec(vec) for(int i = 0 ; i < vec.size(); i++){cout<<vec[i]<<" ";} cout << endl


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

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); debug("%s:%.4fs\n",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))

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

void printVec(vector<char> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

ll Set(ll N, ll pos) {
    return N = N | ((ll) 1 << pos);
}

ll reset(ll N, ll pos) {
    return N = N & ~((ll) 1 << pos);
}

ll check(ll N, ll pos) {
    return (bool) (N & ((ll) 1 << pos));
}

ll setValueBit(ll n, ll pos, ll val) {
    if (val == 1) {
        n = Set(n, pos);
    } else if (val == 0) {
        n = reset(n, pos);
    }
    return n;
}

/************************************** END OF INITIALS ****************************************/

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);

    ll T, t = 0;

    sll(T);

    while (T--) {
        t++;
        ll ans;

        PRINT_CASE(ans);
    }
    return 0;
}