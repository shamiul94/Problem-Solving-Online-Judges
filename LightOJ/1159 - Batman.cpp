// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define max3(a, b, c) max( a , max(b,c))

#define mx 150000
using namespace std;

string s1, s2, s3;
ll len1, len2, len3;

ll dp[60][60][60];

ll lcs() {
    for (ll i = 0; i < 60; i++) {
        dp[i][0][0] = 0;
        dp[0][i][0] = 0;
        dp[0][0][i] = 0;
    }

    for (ll i = 1; i <= len1; i++) {
        for (ll j = 1; j <= len2; j++) {
            for (ll k = 1; k <= len3; k++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max3(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
                }
            }
        }
    }
    return dp[len1][len2][len3];
}


int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        t++;
//        m1(dp) ;
        cin >> s1 >> s2 >> s3;
        len1 = s1.length();
        len2 = s2.length();
        len3 = s3.length();

//        cout << s1 << " " << s2 <<  " " << s3 << endl  ;
//        ll a , b , c ;

//        a = lcs(s1 , s2 , len1 , len2) ;
//        b = lcs(s2 , s3 , len2 , len3) ;
//        c = lcs(s1 , s3 , len1 , len3) ;

        ll ans;
        ans = lcs();
//        ans = min3(a,b,c) ;

//        cout << a << " " << b << " " << c << endl ;

        printf("Case %lld: ", t);
        printf("%lld\n", ans);
    }
    return 0;
}

