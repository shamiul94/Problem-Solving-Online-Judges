//https://leetcode.com/problems/non-decreasing-array/
/**
 * can be better: Runtime: 32 ms, faster than 88.13% of C++ online submissions for Non-decreasing Array.
Memory Usage: 10.3 MB, less than 83.82% of C++ online submissions for Non-decreasing Array.
 */

#include "bits/stdc++.h"

#define ll long long

using namespace std;

string longestPalindrome(string A) {
    int len = static_cast<int>(A.length());

    int maxLen = -1;
    string maxStr;

    for (int i = 0; i < len; i++) {

        int idx, left, right, traverse;

        idx = i;
        left = idx; // left e ache amar idx er shoman shongkhok
        right = len - left - 1; // right e ache
        traverse = min(left, right);

        string tem = "";
        tem = tem + A[i];

        for (int j = 1; j <= traverse; j++) {

            if (A[i - j] != A[i + j]) {
                break;
            } else {

                tem = A[i - j] + tem;
                tem = tem + A[i + j];
            }
        }

        int length = static_cast<int>(tem.length());

        if (maxLen < length) {
            maxLen = length;
            maxStr = tem;
        }
    }

    return maxStr;
}

bool checkPossibility(vector<int> &nums) {

    int outOfPlaceLeftToRight = 0, outOfPlaceRightToLeft = 0, prev = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {

        //left to right

        if (outOfPlaceLeftToRight > 1) break;
        if (nums[i] >= prev) {
            prev = nums[i];
        } else {
            outOfPlaceLeftToRight++;
        }
    }

    //right to left
    prev = INT_MAX;
    for (int i = static_cast<int>(nums.size() - 1); i >= 0; i--) {
        if (outOfPlaceRightToLeft > 1) break;
        if (nums[i] <= prev) {
            prev = nums[i];
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