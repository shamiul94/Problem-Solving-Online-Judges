//
// Created by heisenberg on 3/30/20.
//

#include <bits/stdc++.h>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void solve(TreeNode *root, vector<int> &vec, int level) {
        if (root == nullptr) {
            return;
        }
        if (vec.size() <= level) {
            vec.emplace_back(INT_MIN);
        }
        vec[level] = max(vec[level], root->val);
        solve(root->left, vec, level + 1);
        solve(root->right, vec, level + 1);
    }

    vector<int> largestValues(TreeNode *root) {
        vector<int> vec;
        solve(root, vec, 0);
        return vec;
    }
};