//
// Created by heisenberg on 4/3/20.
//


#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *solve(vector<int> &pre, int preStart, int preEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(pre[preStart]);

        // if there is no one >= root->val, breakIdx = preEnd+1, so that, left end will be preEnd itself
        // and, right start will be preEnd+1 and end will be preEnd --> start > end; so, will return null.
        int breakIdx = preEnd + 1;
        for (int i = preStart + 1; i <= preEnd; i++) {
            if (pre[i] >= root->val) {
                breakIdx = i;
                break;
            }
        }

        root->left = solve(pre, preStart + 1, breakIdx - 1);
        root->right = solve(pre, breakIdx, preEnd);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return solve(preorder, 0, preorder.size() - 1);
    }

};