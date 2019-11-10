
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// original naive approach - 8% time, 5% memory

// count height of every left and right node. if you add them, you will find real diameter
// for the root node. why? because, each height has an additional 1 added into it.
// but you have to add extra 2 edges as left and right both nodes are connected to the
// root node by 2 extra edges. these edges are compensated by that extra value '2'.

class Solution {
public:
    TreeNode *farthestFromRoot;
    int maxDepth = -1;


    int height(TreeNode *root) {
        if (root == 0) return 0;

        int l = height(root->left);
        int r = height(root->right);

        return 1 + max(l, r);
    }

    int dfs(TreeNode *root) {
        if (root == 0) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int l = dfs(root->left);
        int r = dfs(root->right);
        // cout << root -> val << " " << l << " " << r << endl ;

        return maxDepth = max(maxDepth, leftHeight + rightHeight);
    }

    int diameterOfBinaryTree(TreeNode *root) {
        return dfs(root);
    }
};
