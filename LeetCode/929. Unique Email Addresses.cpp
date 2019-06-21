//
// Created by shamiul93 on 6/21/19.
//
///
//https://leetcode.com/problems/unique-email-addresses/

#include "bits/stdc++.h"

#define ll long long

using namespace std;


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