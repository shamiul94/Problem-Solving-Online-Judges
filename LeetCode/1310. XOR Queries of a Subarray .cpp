#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int> cumulativeArr;
        cumulativeArr.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++) {
            cumulativeArr.push_back(arr[i] ^ cumulativeArr[i - 1]);
        }

        // 1 2 3 4 5 6
        vector<int> v;
        for (int i = 0; i < queries.size(); i++) {
            int L = queries[i][0];
            int R = queries[i][1];

            if (L == 0) {
                v.push_back(cumulativeArr[R]);
            }
            else {
                v.push_back(cumulativeArr[R] ^ cumulativeArr[L-1]);
            }
        }
        return v;
    }
};

int main(){
    int a , b;
    a = 4;
    b = 5;
    cout << (a ^ b) << endl;
}