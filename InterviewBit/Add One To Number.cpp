//link - https://www.interviewbit.com/problems/add-one-to-number/#

#include "bits/stdc++.h"

#define ll long long

using namespace std;

vector<int> fun(vector<int> &A) {
    vector<int> tem;

    reverse(A.begin(), A.end());
    A.push_back(0);
    reverse(A.begin(), A.end());

    int rem = 0, div = 1, sum = 0;
    ll sz = A.size();

    for (ll i = sz - 1; i >= 0; i--) {
        sum = A[i] + div;
        rem = sum % 10;
        A[i] = rem;
        div = sum / 10;
    }

    bool flag = false ;
    for (int i = 0; i < sz; i++) {
        if(A[i] && !flag)
        {
            flag = true;
        }
        if(flag)
        {
            tem.push_back(A[i]);
        }
    }

    return tem;
}

int main() {
    vector<int> p;
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);
    p.push_back(9);

    vector<int> t = fun(p);
    for (int i = 0; i < t.size(); i++) {
        cout << t[i] << " ";
    }
    return 0;
}