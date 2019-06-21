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

int numUniqueEmails(vector<string> &emails) {

    vector<string> v;
    for (int i = 0; i < emails.size(); i++) {
        bool plusFound = false;

        string localName, domainName, email, finalEmail;

        email = emails[i];

        for (int j = 0; j < email.length(); j++) {
            if (email[j] == '@') {
                domainName = email.substr(j);
                break;
            }

            if (email[j] == '+') {
                plusFound = true;
            }

            if (!plusFound && email[j] != '.') {
                localName += email[j];
            }
        }

        finalEmail = localName + domainName;
        v.push_back(finalEmail);
    }

    set<string> s( v.begin(), v.end() );
    v.assign( s.begin(), s.end() );
    return static_cast<int>(v.size());
}

int main() {
    std::ios::sync_with_stdio(false);

//    A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
//    [8,6,2,4]

    vector<string> v{"test.email+alex@leetcode.com",
                     "test.e.mail+bob.cathy@leetcode.com",
                     "testemail+david@lee.tcode.com"};

    int a = numUniqueEmails(v);

    cout << a << endl;

    return 0;
}