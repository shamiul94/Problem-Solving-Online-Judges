// recursive

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


// iterative

class Solution {
public:

    bool isSymmetric(TreeNode *root) {
        if (root == 0) return true;

        if (root->left == 0 && root->right == 0) return true;
        if (root->left == 0 || root->right == 0) return false;

        stack < TreeNode * > s;

        if (root->left) s.push(root->left);
        if (root->right) s.push(root->right);

        while (!s.empty()) {
            TreeNode *first, *second;
            first = s.top();
            s.pop();
            second = s.top();
            s.pop();

            if (first == 0 && second == 0) continue;
            if (first == 0 || second == 0) return false;

            if (first->val == second->val) {
                s.push(second->left);
                s.push(first->right);
                s.push(second->right);
                s.push(first->left);
            } else {
                return false;
            }
        }
        return true;
    }
};

