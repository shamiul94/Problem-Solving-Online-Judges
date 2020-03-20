#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B) {
        int lenA = A.size();
        int lenB = B.size();

        vector<vector<int>> ans;

        int i = 0, j = 0;

        while (i < lenA && j < lenB) {
            vector<int> eleA = A[i];
            vector<int> eleB = B[j];

            // cout << eleA[0] << " " << eleA[1] << endl ;
            // cout << eleB[0] << " " << eleB[1] << endl ;

            vector<int> intersectingPoint;
            intersectingPoint.push_back(max(eleA[0], eleB[0]));
            intersectingPoint.push_back(min(eleA[1], eleB[1]));

            if (eleA[1] < eleB[0]) {
                i++;
                continue;
            } else if (eleB[1] < eleA[0]) {
                j++;
                continue;
            } else if (intersectingPoint[1] == eleA[1] && intersectingPoint[1] == eleB[1]) {
                i++;
                j++;
            } else if (intersectingPoint[1] == eleA[1]) {
                i++;
            } else if (intersectingPoint[1] == eleB[1]) {
                j++;
            }
            ans.push_back(intersectingPoint);
        }
        return ans;
    }
};

int main() {
    Solution s;
//    vector<vector<int>> a{{0,  2},
//                          {5,  10},
//                          {13, 23},
//                          {24, 25}};
//    vector<vector<int>> b{{1,  5},
//                          {8,  12},
//                          {15, 24},
//                          {25, 26}};

    vector<vector<int>> a{{0,  2},
                          {6,  10},
                          {13, 23},
                          {24, 25}};
    vector<vector<int>> b{{3, 4}};
    vector<vector<int>> v = s.intervalIntersection(a, b);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]