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
ll len1, len2;

ll SeqLen[40][40] = {};
ll SeqNum[40][40] = {};

ll Length() {
    for (ll i = 0; i < 40; i++) {
        SeqLen[i][0] = i;
        SeqLen[0][i] = i;
    }

    for (ll i = 1; i <= len1; i++) {
        for (ll j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                SeqLen[i][j] = 1 + SeqLen[i - 1][j - 1];
            } else {
                SeqLen[i][j] = 1 + min(SeqLen[i - 1][j], SeqLen[i][j - 1]);
            }
        }
    }

    return SeqLen[len1][len2];
}

ll Number() {
    for (ll i = 0; i < 40; i++) {
        SeqNum[i][0] = 1;
        SeqNum[0][i] = 1;
    }

    for (ll i = 1; i <= len1; i++) {
        for (ll j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                SeqNum[i][j] = SeqNum[i - 1][j - 1];
            } else {
                if (SeqLen[i - 1][j] < SeqLen[i][j - 1]) {
                    SeqNum[i][j] = SeqNum[i - 1][j];
                } else if (SeqLen[i - 1][j] > SeqLen[i][j - 1]) {
                    SeqNum[i][j] = SeqNum[i][j - 1];
                } else if (SeqLen[i - 1][j] == SeqLen[i][j - 1]) {
                    SeqNum[i][j] = SeqNum[i - 1][j] + SeqNum[i][j - 1];
                }
            }
        }
    }
    return SeqNum[len1][len2];
}

void print() {
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            cout << SeqLen[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            cout << SeqNum[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
//    fi ;
//    fo ;
    ll T, t = 0;
    scanf("%lld", &T);

    while (T--) {
        m1(SeqLen);
        m1(SeqNum);

        t++;

        cin >> s1 >> s2;
        len1 = s1.length();
        len2 = s2.length();

        ll l, n;

        l = Length();
        n = Number();

//        print() ;

        printf("Case %lld: ", t);
        printf("%lld %lld\n", l, n);

    }
    return 0;
}
