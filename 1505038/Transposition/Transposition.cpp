/**
@author - Rumman BUET CSE'15
Problem -
Idea -
Concept -
*/

#include <bits/stdc++.h>

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

string cipher;
ll cipherLen;

ll myLen;


vector<char> initVec[200];
vector<char> finalVec[200];

void swapColm(vector<char> vec[], int first, int second) {
//    int rowNum = static_cast<int>(cipherLen / myLen);
//    cout << rowNum << endl ;
    for (int i = 0; i < myLen; i++) {
        swap(vec[i][first], vec[i][second]);
    }
}

string printVec(vector<char> vec[], int rowNum) {
    string s = "";
    cout << vec[0].size() << endl;
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
            s += vec[i][j];
//            cout << vec[i][j];
        }
        cout << endl;
    }
    return s;
}

void func() {
//    int factor[] = {1, 5, 15, 25, 125};

    for (int i = 0; i < cipherLen; i++) {
        initVec[(i % myLen)].push_back(cipher[i]);
    }
    printVec(initVec, myLen);
    swapColm(initVec, 0, 3);
    swapColm(initVec, 1, 4);
    swapColm(initVec, 2, 3);
    swapColm(initVec, 0, 4);
    string dec = printVec(initVec, myLen);
    cout << "decrypted: " << endl << dec << endl << endl;
}

void encrypt() {

    string encoded = "";
    swapColm(initVec, 0, 4);
    swapColm(initVec, 2, 3);
    swapColm(initVec, 1, 4);
    swapColm(initVec, 0, 3);

    cout << "encrypted: " << endl << endl;
    printVec(initVec, myLen);


    for (ll j = 0; j < initVec[0].size(); j++) {
        for (ll i = 0; i < myLen; i++) {
            encoded += initVec[i][j];
        }
    }

    cout << endl << endl << encoded << endl;
    cout << "Accuracy: " << 100 << "% " << endl ; 
}


//25134
int main() {
    fi;
    fo;
    // 1, 5, 25, 125
    myLen = 25;

    cin >> cipher;
    cipherLen = static_cast<long long int>(cipher.length());

    cout << "Decryption: " << endl << endl;
    func();
    cout << "Decrypted Text: " << endl;
    cout << "KEY LENGTH: " << 5 << endl;
    cout << "KEY: " << 25134 << endl;

    encrypt();
    return 0;
}

