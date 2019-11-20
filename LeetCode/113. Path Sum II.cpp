/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 10%, 20%
class Solution1 {
public:

    void solve(vector <vector<int>> &v, vector<int> prev, TreeNode *root, int sum) {
        if (root && root->left == 0 && root->right == 0) {
            if (sum - root->val == 0) {
                prev.push_back(root->val);
                v.push_back(prev);
                return;
            } else {
                return;
            }
        }

        if (root == 0) {
            return;
        }

        prev.push_back(root->val);
        solve(v, prev, root->left, sum - root->val);
        solve(v, prev, root->right, sum - root->val);
    }

    vector <vector<int>> pathSum(TreeNode *root, int sum) {
        vector <vector<int>> v;
        vector<int> prev;
        solve(v, prev, root, sum);
        return v;
    }
};


///////////


// use reference variable parameter instead of new instantiated variable.
// 92%, 97%
class Solution {
public:

    void solve(vector <vector<int>> &v, vector<int> &prev, TreeNode *root, int sum) {
        if (root && root->left == 0 && root->right == 0) {
            if (sum - root->val == 0) {
                prev.push_back(root->val);
                v.push_back(prev);
                // as we are using prev as reference variable, we need to undo every change
                // we have committed to this vector so far in this level.
                prev.pop_back();
                return;
            } else {
                return;
            }
        }

        if (root == 0) {
            return;
        }

        prev.push_back(root->val);
        solve(v, prev, root->left, sum - root->val);
        solve(v, prev, root->right, sum - root->val);
        // undoing the change
        prev.pop_back();
    }

    vector <vector<int>> pathSum(TreeNode *root, int sum) {
        vector <vector<int>> v;
        vector<int> prev;
        solve(v, prev, root, sum);
        return v;
    }
};