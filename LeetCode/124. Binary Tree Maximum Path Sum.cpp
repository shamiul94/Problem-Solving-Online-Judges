/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    // int sum;

    int solve(TreeNode *root, int &sum) {
        if (root == 0) return 0;
        int left = max(0, solve(root->left, sum));
        int right = max(0, solve(root->right, sum));

        sum = max(sum, left + right + root->val);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root) {
        int sum = INT_MIN;
        solve(root, sum);
        return sum;
    }
};


class Solution {
public:
    // int sum;

    int solve(TreeNode *root, int &sum) {
        if (root == 0) return 0;
        int left = solve(root->left, sum);
        int right = solve(root->right, sum);

        // left = max(0,left);
        // right = max(0,right);

        if (left < 0) left = 0;
        if (right < 0) right = 0;

        sum = max(sum, left + right + root->val);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root) {
        int sum = INT_MIN;
        solve(root, sum);
        return sum;
    }
};



