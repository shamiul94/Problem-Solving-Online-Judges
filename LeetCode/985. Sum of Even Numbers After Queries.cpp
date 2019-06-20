//
// Created by shamiul93 on 6/20/19.
//
//https://leetcode.com/problems/sum-of-even-numbers-after-queries/

#include "bits/stdc++.h"

#define ll long long

using namespace std;

vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 0) { sum += A[i]; }
    }

    int tem = 0;
    for (int i = 0; i < queries.size(); i++) {
        int val = queries[i][0], idx = queries[i][1];

        tem = sum;
        if (A[idx] % 2 == 0) {
            tem = tem - A[idx];
        }

        A[idx] += val;
        if (A[idx] % 2 == 0) {
            tem += A[idx];
        }
        sum = tem;
        ans.push_back(tem);
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);

//    A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
//    [8,6,2,4]

    vector<int> a{1, 2, 3, 4};
    vector<vector<int>> q{{1,  0},
                          {-3, 1},
                          {-4, 0},
                          {2,  3}};


    vector<int> p = sumEvenAfterQueries(a, q);
    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << " ";
    }

    return 0;
}