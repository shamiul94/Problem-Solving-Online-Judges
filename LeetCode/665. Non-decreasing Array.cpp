//
// Created by shamiul93 on 6/19/19.
//

#include "bits/stdc++.h"

#define ll long long

using namespace std;

bool checkPossibility(vector<int> &nums) {
    vector<int> v;

    v.push_back(INT_MIN + 1);
    for (int i = 0; i < nums.size(); i++) {
        v.push_back(nums[i]);
    }
    v.push_back(INT_MAX - 1);

    //left to right

    int outOfPlaceLeftToRight = 0, outOfPlaceRightToLeft = 0, prev = INT_MIN;

    for (int i = 0; i < v.size(); i++) {
        if (outOfPlaceLeftToRight > 1) break;
        if (v[i] >= prev) {
            prev = v[i];
        } else {
            outOfPlaceLeftToRight++;
        }
    }

    //right to left

    prev = INT_MAX;
    for (int i = static_cast<int>(v.size() - 1); i >= 0; i--) {
        if (outOfPlaceRightToLeft > 1) break;
        if (v[i] <= prev) {
            prev = v[i];
        } else {
            outOfPlaceRightToLeft++;
        }
    }
    int ans;
    ans = min(outOfPlaceLeftToRight, outOfPlaceRightToLeft);

    return ans <= 1;
}


int main() {
    std::ios::sync_with_stdio(false);
//    string s;
////    s = longestPalindrome("aa");
//    cout << s << endl;

//    [1,1,4,2,1,3]
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);

    bool s = checkPossibility(v);
    if (s) cout << "true" << endl;
    else cout << "false " << endl;

//    cout << INT_MIN << endl ;
    return 0;
}