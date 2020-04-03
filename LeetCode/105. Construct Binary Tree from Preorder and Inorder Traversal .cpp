
//Definition for a binary tree node.

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {

        if (preStart > preEnd) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preStart]); // getting the root node from pre.

        int rootPosInOrder = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                rootPosInOrder = i;
            }
        }

        root->left = solve(preorder, inorder,
                           preStart + 1, preStart + (rootPosInOrder - inStart),
                           inStart, rootPosInOrder - 1);

        root->right = solve(preorder, inorder,
                            preStart + (rootPosInOrder - inStart) + 1, preEnd,
                            rootPosInOrder + 1, inEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return solve(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

//////////////////// with map


class Solution2 {
public:
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &um,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {

        if (preStart > preEnd) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preStart]); // getting the root node from pre.

        int rootPosInOrder = 0;
//        for (int i = inStart; i <= inEnd; i++) {
//            if (inorder[i] == root->val) {
//                rootPosInOrder = i;
//            }
//        }

        rootPosInOrder = um[root->val];

        root->left = solve(preorder, inorder, um,
                           preStart + 1, preStart + (rootPosInOrder - inStart),
                           inStart, rootPosInOrder - 1);

        root->right = solve(preorder, inorder, um,
                            preStart + (rootPosInOrder - inStart) + 1, preEnd,
                            rootPosInOrder + 1, inEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> um;
        for (int i = 0; i < inorder.size(); i++) {
            um[inorder[i]] = i;
        }
        return solve(preorder, inorder, um, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

