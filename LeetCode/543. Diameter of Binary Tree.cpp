
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


// more optimized O(n) solution - compute diameter and height at once. not using height function for every call.

// idea is that, in previous solution, we were calculating height for every
// node every time by different function. that made it n^2. so, what we are
// doing now is that we are just calculating the height now. it takes
// at most n times. every time we check if l+r>maxDia. why?
// because, look at the problem carefully. each and every diameter will pass through some
// node for sure. not necessarily through our initial root but definitely SOME node.
// so, we traverse every node and look at their both side's depth.
// we add those depth to get the total diameter for that node and compare it to
// maxdia.
class Solution {
public:

    int maxDia = 0;

    // in this function we are basically calculating height for every node.
    // additionally we are checking a global variable maxDia.

    int dfs(TreeNode *root) {
        if (root == 0) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        maxDia = max(maxDia, l + r);
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode *root) {
        int a = dfs(root);
        return maxDia;
    }
};
