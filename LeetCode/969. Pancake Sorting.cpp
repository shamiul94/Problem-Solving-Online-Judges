//https://leetcode.com/problems/pancake-sorting/

#include "bits/stdc++.h"

#define ll long long

using namespace std;


int findMax(vector<int> &v, int rangeIdx) {
    int maximum = -1, maxIdx = 0;
    for (int i = 0; i < rangeIdx; i++) {
        maximum = max(maximum, v[i]);
        if (maximum == v[i]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}


vector<int> flip(vector<int> &v, int idx) {
    reverse(v.begin(), v.begin() + idx + 1);
    return v;
}


vector<int> pancakeSort(vector<int> &A) {
    vector<int> tem;

    for (int currSize = (A.size()); currSize >= 2; currSize--) {

        int mi = findMax(A, currSize);

        if(mi != currSize-1)
        {
            flip(A, mi);
            flip(A, currSize-1);

            tem.push_back(mi+1);
            tem.push_back(currSize);
        }
    }
    return tem;
}



int main() {
//    Input: [3,2,4,1]
//    Output: [4,2,4,3]

    /*
     * 4231
     * 1324
     * 3124
     * 2134
     * 2134
     * 1234
     */


    vector<int> p;

    p.push_back(3);
    p.push_back(2);
    p.push_back(4);
    p.push_back(1);

    vector<int> t = pancakeSort(p);

    for (int i = 0; i < t.size(); i++) {
        cout << t[i] << " ";
    }

    return 0;
}