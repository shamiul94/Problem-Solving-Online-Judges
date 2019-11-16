#include <bits/stdc++.h>

using namespace std;

int maxserver(int servers[], int n, int k) {
    priority_queue<int, vector<int>, greater<int >> pq; // # 4 === type doesnt match
//    for (int i = 1; i <= n; i++) { # 5 === 0 theke start
    for (int i = 0; i < n; i++) {
//        pq.pop(servers[i]); # 1 === push hobe
        pq.push(servers[i]);
    }
    int count = 0;
//    while(pq.push() <= k){ # 2 === push doesnt return anything and size check

    while (pq.top() <= k && !pq.empty()) {
        count++;
//        k = k + pq.top(); # 6 === minus hobe
        k = k - pq.top();
        pq.pop();
    }

    return count;
}

class bal{
public:
    vector<int> v;
    vector<int> v1;
    vector<int> fun(vector<int> vv){
        vector<int> t(vv.size(), 100);
        v1 = t;
        cout << v1[0] << endl;
        return vector<int>{};
    }
};

int main() {
//    int servers[] = {1, 12, 5, 111, 200, 1000, 10, 9, 12, 15};
////    int n = sizeof(servers) / sizeof(servers[7]); # 3 === array index
//    int n = sizeof(servers) / sizeof(servers[8888] );
//    int k = 5000;
//
//    cout << maxserver(servers, n, k);
////    cout << servers[8888];
//    return 0;

//    int arr[1100][1100] = {};
//    cout << arr[100][100] << endl;
    bal b = bal();
    b.fun({1,2,3});
}