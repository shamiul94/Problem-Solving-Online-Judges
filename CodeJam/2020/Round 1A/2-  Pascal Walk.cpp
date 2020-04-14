////
//// Created by heisenberg on 4/11/20.
////
//
//#include <bits/stdc++.h>
//
//#define fi                                      freopen("in.txt", "r", stdin)
//#define fo                                      freopen("out.txt", "w", stdout)
//
//using namespace std;
//#define ll long long
//#define VISITED 1
//#define UNVISITED -1
//vector<vector<pair<ll, ll>>> pascalTriangle;
//
//ll N;
//
//
//void makePascal() {
//    ll level = 67;
//
//    // 0
//    pascalTriangle.emplace_back();
//    pascalTriangle[0].emplace_back(make_pair(1, -1));
//
//    // 1
//    pascalTriangle.emplace_back();
//    pascalTriangle[1].emplace_back(make_pair(1, -1));
//    pascalTriangle[1].emplace_back(make_pair(1, -1));
//
//    for (ll i = 2; i < level; i++) {
//        pascalTriangle.emplace_back();
//        for (ll j = 0; j <= i; j++) {
//            if (j == 0 || j == i) {
//                pascalTriangle[i].emplace_back(make_pair(1, -1));
//            } else {
//                ll a = pascalTriangle[i - 1][j - 1].first + pascalTriangle[i - 1][j].first;
//
//                pascalTriangle[i].emplace_back(
//                        make_pair(a, -1));
//            }
//        }
//    }
//
////    cout << "fhkjd --> " << pascalTriangle[2][1].first << endl;
//}
//
//bool dp(vector<pair<ll, ll>> &path, ll i, ll j, ll left) {
//    if (i < 0 || j < 0 || i >= pascalTriangle.size() || j >= pascalTriangle[i].size()) {
//        return;
//    }
//    if (pascalTriangle[i][j].second != -1) {
//        return;
//    }
//    if (pascalTriangle[i][j].first > left){
//        return;
//    }
//
//    if(left == 0){
//        // do sth
//        return;
//    }
//
//    dp(path, i, j , left - pascalTriangle[i][j].first);
//    dp(path, i, j , left - pascalTriangle[i][j].first);
//    dp(path, i, j , left - pascalTriangle[i][j].first);
//    dp(path, i, j , left - pascalTriangle[i][j].first);
//    dp(path, i, j , left - pascalTriangle[i][j].first);
//    dp(path, i, j , left - pascalTriangle[i][j].first);
//
//}
//
//int main() {
////    fi;
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    int t = 0, T;
//    makePascal();
//
//    cin >> T;
//    while (T--) {
//        t++;
//        cout << "Case #" << t << ": ";
//        cin >> N;
//
//        vector<pair<ll, ll>> path;
//
//        dp(path, 0, 0, N);
//
//    }
//
////    for(int i = 0 ; i < pascalTriangle.size(); i++){
////        for(int j = 0 ; j < pascalTriangle[i].size(); j++){
////            cout << pascalTriangle[i][j].first << " " ;
////        }
////        cout << endl;
////    }
//
////    ll a = 1e09;
////    cout << a << endl;
//
//    return 0;
//}