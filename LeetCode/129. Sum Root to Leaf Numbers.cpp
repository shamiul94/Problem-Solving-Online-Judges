/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, int num, int &ans) {
        if (root == 0) return;
        if (root->left == 0 && root->right == 0) {
            ans += num * 10 + root->val;
            return;
        }

        solve(root->left, num * 10 + root->val, ans);
        solve(root->right, num * 10 + root->val, ans);
    }

    int sumNumbers(TreeNode *root) {
        // if(root==0) return 0;
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};