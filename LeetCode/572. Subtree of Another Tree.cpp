
// trivial recursive solution. check for every node if that subtree is the same as t.
// this is better.

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == 0 && q == 0) return true;
        if (p == 0 || q == 0) return false;

        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }

    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == 0) return false;

        if (isSameTree(s, t)) {
            return true;
        }

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};


// I tried to optimize my original solution here but it does worse in both time-wise and memorywise. timewise
// it is almost same but memorywise it's worse.

class Solution2 {
public:

    vector<TreeNode *> v;
    int tHeight, sHeight;

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == 0 && q == 0) return true;
        if (p == 0 || q == 0) return false;

        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }

    int height(TreeNode *s) {
        if (s == 0) return 0;
        return 1 + max(height(s->left), height(s->right));
    }

    int getSameHeightNodes(TreeNode *s) {
        if (s == 0) return 0;
        int h = 1 + max(getSameHeightNodes(s->left), getSameHeightNodes(s->right));
        // cout << s->val << endl;

        if (h == tHeight) {
            v.push_back(s);
        }
        return h;
    }


    bool isSubtree(TreeNode *s, TreeNode *t) {
        tHeight = height(t);
        int pp = getSameHeightNodes(s);

        for (int i = 0; i < v.size(); i++) {
            // cout << v[i]->val << endl;
            if (isSameTree(v[i], t)) {
                return true;
            }
        }

        return false;
    }
};


