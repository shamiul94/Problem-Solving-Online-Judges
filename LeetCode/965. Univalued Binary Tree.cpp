
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
    int prevVal = -1;

    bool isUnivalTree(TreeNode *root) {
        if (root == 0) return true;

        if (prevVal == -1)
            prevVal = root->val;

        if (root->val != prevVal)
            return false;

        return isUnivalTree(root->left) && isUnivalTree(root->right);

    }
};
