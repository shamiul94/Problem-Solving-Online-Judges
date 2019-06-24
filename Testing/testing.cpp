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

string str = "abcd";
vector<string> vec;

string Permutation(ll idx , ll mask) {
    if(idx >= str.length()) return "";

    for (int i = 0; i < str.length(); i++) {
        
    }
}


int main() {
    std::ios::sync_with_stdio(false);

//    A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
//    [8,6,2,4]

    vector<string> v{"test.email+alex@leetcode.com",
                     "test.e.mail+bob.cathy@leetcode.com",
                     "testemail+david@lee.tcode.com"};


    return 0;
}