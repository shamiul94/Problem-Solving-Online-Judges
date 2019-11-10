class Solution {
public:

    bool isSym(TreeNode *s, TreeNode *t) {
        if (s == 0 && t == 0) return true;
        if (s == 0 || t == 0) return false;

        if (s->val == t->val) {
            return isSym(s->left, t->right) && isSym(s->right, t->left);
        } else return false;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == 0) return true;

        if (isSym(root->left, root->right)) {
            return true;
        } else return false;
    }
};
