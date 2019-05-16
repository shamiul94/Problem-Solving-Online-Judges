/**
@author - Rumman BUET CSE'15
Problem -
Idea -
Concept -
*/

#include <bits/stdc++.h>

#define ll                                      long long int


#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

#define sll(a)                                scanf("%lld",&a)
#define sll2(a, b)                             sll(a) , sll(b)


using namespace std;

#define MAX 1000000000000


vector<ll> lucky;
vector<ll> veryLucky;

void printVec(vector<ll> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << endl;
}

void generateLucky(ll n) {
    if (n > MAX) return;
    if (n) lucky.push_back(n);
    generateLucky(n * 10 + 4);
    generateLucky(n * 10 + 7);
}


void generateVeryLucky(ll n, ll idx) {
    for (ll i = idx; i < lucky.size(); i++) {
        ll temp = n * lucky[i];
        if (temp > MAX || temp <= 0) return;
        veryLucky.push_back(temp);
        generateVeryLucky(temp, i);
    }
}


int main() {
//    fi;
//    fo;
    ll T, t = 0;

    generateLucky(0);
    sort(lucky.begin(), lucky.end());

    generateVeryLucky(1, 0);
    sort(veryLucky.begin(), veryLucky.end());

    set<ll> s(veryLucky.begin(), veryLucky.end());
    veryLucky.clear();
    veryLucky.assign(s.begin(), s.end());

    sll(T);

//    printVec(veryLucky);

    while (T--) {
        t++;
        ll hi, lo, ans;
        sll2(lo, hi);

        ans = upper_bound(veryLucky.begin(), veryLucky.end(), hi) -
              lower_bound(veryLucky.begin(), veryLucky.end(), lo) ;

        printf("Case %lld: %lld\n",t, ans);
    }
    return 0;
}