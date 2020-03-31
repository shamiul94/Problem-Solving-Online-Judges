//
// Created by heisenberg on 3/31/20.
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
    TreeNode *delNode(TreeNode *root, int val, queue<TreeNode *> &q) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val == val) {
            if (root->left != 0) {
                q.push(root->left);
            }
            if (root->right != 0) {
                q.push(root->right);
            }
            return 0;
        }

        TreeNode *left = delNode(root->left, val, q);
        TreeNode *right = delNode(root->right, val, q);

        if (left == 0) {
            root->left = 0;
        }
        if (right == 0) {
            root->right = 0;
        }

        return root;
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        vector<TreeNode *> ans;
        queue<TreeNode *> q;
        q.push(root);

        for (int i = 0; i < to_delete.size(); i++) {
            int currSize = q.size();
            int t = 0;
            int delVal = to_delete[i];

            while (t < currSize) {
                TreeNode *curr = q.front();
                q.pop();

                TreeNode * tem = delNode(curr, delVal, q);

                if (tem) {
                    q.push(curr);
                }
                t++;
            }
        }

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

int main() {

}