/**
@author - Rumman BUET CSE'15
Problem -
Idea -
Concept -
*/

#include <bits/stdc++.h>

#define PRINT_CASE(ans)                         printf("Case %lld: %lld\n",t, ans)
#define SORT_VECTOR(vec)                        sort(vec.begin(), vec.end())


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

void printVec(vector<char> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

/************************************** END OF INITIALS ****************************************/

int LPS[1000005] = {};
int N;

void generateLPSArray(string pattern) {
    N = (int)(pattern.length());
    int j, i;
    // initialize
    j = 0;
    LPS[0] = 0;

    for (i = 1; j < i && i < N;) {
        if (pattern[j] == pattern[i]) {
            LPS[i] = j + 1;
            i++;
            j++;
        } else { // pattern[j] != pattern[i]
            if (j > 0) {
                j = LPS[j - 1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}

int solve(string A) {
    reverse(A.begin(), A.end());
    m0(LPS);
    string tem = A;
    int realStringLen = static_cast<int>(A.length());
    string modified = A + "#";
    reverse(tem.begin(), tem.end());
    modified += tem;

    generateLPSArray(modified);
    int lastIdxValue = LPS[N - 1];

    return (realStringLen + (realStringLen - lastIdxValue));
}


int main() {
//    fi;
//    fo;
    ll T, t = 0;

    sll(T);

    while (T--) {
        t++;
        ll ans;
        string str;
        cin >> str;
        ans = solve(str);

        PRINT_CASE(ans);
    }
    return 0;
}