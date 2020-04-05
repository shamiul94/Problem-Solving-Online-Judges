//
// Created by heisenberg on 4/4/20.
//
//
//#include <bits/stdc++.h>
//
//#define fi                                      freopen("in.txt", "r", stdin)
//#define fo                                      freopen("out.txt", "w", stdout)
//
//#define PII pair<int,int>
//
//using namespace std;
//
//bool overlaps(PII a, PII b) {
//    // 1     5
//    //    3     6
//    if (a.first < b.first && b.first < a.second) {
//        return true;
//    }
//    //    3   6
//    //  1   4
//    if (a.first < b.second && b.second < a.second) {
//        return true;
//    }
//
//    if (b.first < a.first && a.first < b.second) {
//        return true;
//    }
//
//    if (b.first < a.second && a.second < b.second) {
//        return true;
//    }
//    return false;
//}
//
//bool overlapExists(const vector<PII > &name, PII x) {
////    for (int i = name.size() - 1; i >= 0; i--) {
//    for (int i = 0; i < name.size(); i++) {
////        if (overlaps(name[i], x)) {
////            return true;
////        }
//
//        if(x.first>=name[i].first and x.first<name[i].second){
//            return true;
//        }
//    }
//    return false;
//}
//
//int main() {
////    fi;
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    int t = 0, T, N;
//
//    cin >> T;
//
//
//    while (T--) {
//        vector<PII > v;
//
//        t++;
//        cout << "Case #" << t << ": ";
//        int a, b;
//        cin >> N;
//        for (int i = 0; i < N; i++) {
//            cin >> a >> b;
//            v.emplace_back(a, b);
//        }
////        sort(v.begin(), v.end());
//
//
//        vector<PII > cameron;
//        vector<PII > james;
//        string ans;
//
//        cameron.push_back(v[0]);
//        ans = ans + 'C';
////        cout << v.size() << endl;
//        for (int i = 1; i < v.size(); i++) {
//            PII x = v[i];
//
//            if (overlapExists(cameron, x)) {
//                if (overlapExists(james, x)) {
//                    ans = "IMPOSSIBLE";
//                    break;
//                } else {
//                    james.emplace_back(x);
//                    ans = ans + 'J';
//                }
//            } else {
//                cameron.emplace_back(x);
//                ans = ans + 'C';
//            }
//
////            if (overlapExists(cameron, x) && overlapExists(james, x)) {
////                ans = "IMPOSSIBLE";
////                break;
////            } else if (overlapExists(cameron, x)) {
////                james.emplace_back(x);
////                ans = ans + 'J';
////            } else if (overlapExists(james, x)) {
////                cameron.emplace_back(x);
////                ans = ans + 'C';
////            } else {
////                cameron.emplace_back(x);
////                ans = ans + 'C';
////            }
//        }
//        cout << ans << endl;
//
//    }
//
//    return 0;
//}

///////////////
//

#include<bits/stdc++.h>
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;
struct interval {
    int start, ending, idx;
};

bool overlaps(pair<int,int> a, pair<int,int> b) {
    // 1     5
    //    3     6
    if (a.first < b.first && b.first < a.second) {
        return true;
    }
    //    3   6
    //  1   4
    if (a.first < b.second && b.second < a.second) {
        return true;
    }

    if (b.first < a.first && a.first < b.second) {
        return true;
    }

    if (b.first < a.second && a.second < b.second) {
        return true;
    }
    return false;
}

bool cmp(interval a, interval b) {
    if (a.start != b.start) {
        return a.start < b.start;
    } else if (a.ending != b.ending) {
        return a.ending < b.ending;
    } else {
        return a.idx < b.idx;
    }
}

bool check(vector<interval> p, interval a) {
    for (int i = 0; i < p.size(); i++) {
        if (a.start >= p[i].start && a.start < p[i].ending) {
            return false;
        }
    }
    return true;
}

int main() {
//    fi;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        vector<interval> intervalList;
        vector<interval> james;
        vector<interval> cameron;

        int n;
        cin >> n;
        string ans;
        for (int i = 0; i < n; i++) {
            ans += 'A';
        }

        for (int i = 0; i < n; i++) {
            int start, end;
            cin >> start >> end;
            interval tem;
            tem.start = start;
            tem.ending = end;
            tem.idx = i;
            intervalList.push_back(tem);
        }
        sort(intervalList.begin(), intervalList.end(), cmp);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            bool v = check(james, intervalList[i]);
            if (v) {
                ans[intervalList[i].idx] = 'J';
                james.push_back(intervalList[i]);
            } else {
                v = check(cameron, intervalList[i]);
                if (v) {
                    ans[intervalList[i].idx] = 'C';
                    cameron.push_back(intervalList[i]);
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "Case #" << t << ": " << ans << endl;
        } else {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        }
    }
}