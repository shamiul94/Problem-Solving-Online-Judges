// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000
using namespace std;

string s1, s2;
int l1, l2;

int dp[110][110] = {};
string str[110][110] = {};

void lcs() {
    for (int i = 0; i < 110; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
        str[i][0] = "";
        str[0][i] = "";
    }

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                str[i][j] = str[i - 1][j - 1] + s1[i - 1];
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                str[i][j] = str[i - 1][j];
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                str[i][j] = str[i][j - 1];
            } else if (dp[i - 1][j] == dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                str[i][j] = min(str[i - 1][j], str[i][j - 1]);
            }
        }
    }
}


int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
//    scanf("%lld",&T) ;
    cin >> T;


    while (T--) {
        t++;

        cin >> s1 >> s2;
        l1 = s1.length();
        l2 = s2.length();
        printf("Case %lld: ", t);

        lcs();
        if (str[l1][l2] == "") {
            cout << ":(" << endl;
        } else
            cout << str[l1][l2] << endl;
    }
    return 0;
}

