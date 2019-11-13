/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// my original solution
// 96%, 80%

class Solution1 {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == 0 && t2 == 0) {
            return 0;
        } else if (t1 != 0 && t2 != 0) {
            int newVal;
            newVal = t1->val + t2->val;
            t1->val = newVal;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        } else if (t1 != 0 && t2 == 0) {
            return t1;
        } else if (t1 == 0 && t2 != 0) {
            return t2;
        }
        return 0;
    }
};

//////////////////

// my original solution
// 96%, 80%

class Solution2 {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == 0 && t2 == 0) {
            return 0;
        } else if (t1 != 0 && t2 != 0) {
            int newVal;
            newVal = t1->val + t2->val;
            t1->val = newVal;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        } else if (t1 != 0) {
            return t1;
        } else {
            return t2;
        }
        return 0;
    }
};

////////////////////
// 99%, 40%

class Solution3 {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (!t1 || !t2) return t1 ? t1 : t2;

        TreeNode *node = new TreeNode(t1->val + t2->val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
        return node;
    }
};