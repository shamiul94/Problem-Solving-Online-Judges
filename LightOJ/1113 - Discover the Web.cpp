// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>

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

#define scanLL(a)                                scanf("%lld",&a)
#define scanLL2(a, b)                             scanL(a) , scanL(b)
#define scanLL3(a, b, c)                           scanL(a), scanL(b), scanL(c)
#define scanLL4(a, b, c, d)                         scanL(a), scanL(b), scanL(c), scanL(d)

#define inf LLONG_MAX
#define minf LLONG_MIN
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000


using namespace std;

ll N, Q;
vector<ll> v[100010];

stack<string> Forward, Backward;

void printStacks() {
    cout << endl;
    cout << "Backward Size: " << Backward.size() << endl;

    stack<string> tem;

    while (!Backward.empty()) {
        string s;
        s = Backward.top();
        cout << s << endl;
        tem.push(s);
        Backward.pop();
    }
    while (!tem.empty()) {
        Backward.push(tem.top());
        tem.pop();
    }

    cout << endl;
    cout << "Forward Size: " << Forward.size() << endl;

    while (!Forward.empty()) {
        string s;
        s = Forward.top();
        cout << s << endl;
        tem.push(s);
        Forward.pop();
    }
    while (!tem.empty()) {
        Forward.push(tem.top());
        tem.pop();
    }
}

int main() {
//    fi ;
//    fo ;
    string Current;

    ll T, t = 0;
    cin >> T;
    while (T--) {
        while (!Backward.empty()) {
            Backward.pop();
        }
        while (!Forward.empty()) {
            Forward.pop();
        }
        t++;
        printf("Case %lld:\n", t);
        string command;

//        Backward.push("http://www.lightoj.com/") ;
        Current = "http://www.lightoj.com/";


        while (cin >> command && command != "QUIT") {
//            cout << endl << "New Command: " << endl ;
            if (command == "BACK") {
                if (Backward.size() == 0) {
                    printf("Ignored\n");
                } else {
                    Forward.push(Current);
                    Current = Backward.top();
                    Backward.pop();
                    cout << Current << endl;
                }
//                printStacks() ;
            } else if (command == "FORWARD") {
                if (Forward.size() == 0) {
                    printf("Ignored\n");
                } else {
                    Backward.push(Current);
                    Current = Forward.top();
                    Forward.pop();
                    cout << Current << endl;
                }
//                printStacks() ;
            } else if (command == "VISIT") {
                string url;
                cin >> url;

                Backward.push(Current);
                Current = url;

                cout << Current << endl;

                while (!Forward.empty()) {
                    Forward.pop();
                }
//                printStacks() ;
            }
        }
    }
    return 0;
}
