//
// Created by heisenberg on 4/3/20.
//


#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *solve(vector<int> &pre, vector<int> &post, unordered_map<int, int> &um,
                    int preStart, int preEnd,
                    int postStart, int postEnd) {

    }


    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {

    }
};