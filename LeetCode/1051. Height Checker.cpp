//
// Created by shamiul93 on 6/19/19.
//

#include "bits/stdc++.h"

#define ll long long

using namespace std;



int heightChecker(vector<int>& heights) {
    vector<int> tem = heights;
    sort(tem.begin(), tem.end());

    int ans = 0;
    for(int i = 0 ; i < heights.size(); i++)
    {
        if(tem[i] != heights[i])
        {
            ans++;
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);

//    [1,1,4,2,1,3]
    vector<int> v ;
    v.push_back(1);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    cout << heightChecker(v) << endl ;
    return 0;
}