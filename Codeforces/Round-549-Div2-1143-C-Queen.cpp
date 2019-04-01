/**
 * @author - SHAMIUL HASAN
 * @Link - https://codeforces.com/contest/1143/problem/C
 * @Contest - Codeforces Round #549 (Div. 2)
 * @Idea - observation. idea is to delete a node when it doesn't respect ny of it's ancestor AND
 * none of its children respect it. So, if we get the respect point (Ci) of any node, we multiply
 * it with its parents' respect value. if it's 1, parent will be 1 or 0. if somehow
 * it's value becomes 0,
 * it doesn't fulfill criteria.
 */

#include <bits/stdc++.h>
#include <vector>

#define ll                                      long long int
#define sll(a)                                scanf("%lld",&a)
#define sll2(a, b)                             sll(a) , sll(b)

using namespace std;

ll N;
ll arr[100005] = {};

int main() {
    sll(N);

    ll parentIdx, respect;

    for(ll i = 0 ; i < N ; i++){
        arr[i] = 1;
    }

    for (ll i = 0; i < N; i++) {
        sll2(parentIdx, respect);
        if (parentIdx == -1) {
            arr[i] = respect;
        } else {
            arr[parentIdx - 1] *= respect;
            arr[i] *= respect;
        }
    }

    ll t = 0 ;
    for(ll i = 0 ; i < N ; i++){
        if(arr[i] == 1){
            t++;
            cout << i+1 << " ";
        }
    }

    if(t == 0) cout << -1 ;

    cout << endl;

    return 0;
}
