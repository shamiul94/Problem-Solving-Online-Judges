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
    TreeNode *solve(vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> &um,
                    int postStart, int postEnd,
                    int inStart, int inEnd) {

        if (postStart > postEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]); // getting the root node from post.
        int rootPosInOrder = um[root->val];

        root->left = solve(postorder, inorder, um,
                           postStart, postStart + (rootPosInOrder - inStart) - 1,
                           inStart, rootPosInOrder - 1);
        root->right = solve(postorder, inorder, um,
                            (postStart + (rootPosInOrder - inStart) - 1) + 1, postEnd - 1,
                            rootPosInOrder + 1, inEnd);

        return root;

    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> um;
        for (int i = 0; i < inorder.size(); i++) {
            um[inorder[i]] = i;
        }
        return solve(postorder, inorder, um, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};