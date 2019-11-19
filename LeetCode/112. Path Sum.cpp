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
    bool hasPathSum2(TreeNode *root, int sum) {

        // as there are some nodes who are leaf (doesn't have either of
        // left or right) and others are one-childed nodes (who
        // have just right or left)
        // to handle this corner case, we need to treat leaf nodes
        // and one childed odes differently.
        // we will take leaf's decision while we are on them
        // that means, leaf will never go till null.
        // but for other nodes, we will go until we find null node.

        // if it's a child

        if (root != 0 && root->left == 0 && root->right == 0) {
            if (sum - root->val == 0) return true;
            else return false;
        }

        // not leaf but some node who has only one child
        // like -
        //          1
        //         /
        //        2
        //       /
        //      3
        // here, 1, 2 can be this kind of nodes

        // one other thing : as you are filtering the leaf nodes one step earlier,
        // so, no null node can arise from leaf nodes.

        if (root == 0) return false;

        return hasPathSum2(root->left, sum - root->val) || hasPathSum2(root->right, sum - root->val);
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if (root == 0) return false;
        return hasPathSum2(root, sum);
    }
};

//////////////


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    bool hasPathSum2(TreeNode *root, int sum) {

        if (root == 0) return false;
        // if it's a child
        if (root->left == 0 && root->right == 0) {
            if (sum - root->val == 0) return true;
            else return false;
        }

        // not leaf but some node who has only one child
        // like -
        //          1
        //         /
        //        2
        //       /
        //      3
        // here, 1, 2 can be this kind of nodes

        // one other thing : as you are filtering the leaf nodes one step earlier,
        // so, no null node can arise from leaf nodes.



        return hasPathSum2(root->left, sum - root->val) || hasPathSum2(root->right, sum - root->val);
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if (root == 0) return false;
        return hasPathSum2(root, sum);
    }
};


/////////////


class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == 0) return false;
        stack < TreeNode * > nodes;
        stack<int> num;

        nodes.push(root);
        num.push(sum);

        while (!nodes.empty()) {
            TreeNode *u = nodes.top();
            int currSum = num.top();
            nodes.pop();
            num.pop();

            if (u->left == 0 && u->right == 0) {
                if (currSum - u->val == 0) {
                    return true;
                } else {
                    continue;
                }
            } else {
                if (u->left == 0) {
                    nodes.push(u->right);
                    num.push(currSum - u->val);
                } else if (u->right == 0) {
                    nodes.push(u->left);
                    num.push(currSum - u->val);
                } else {
                    nodes.push(u->left);
                    num.push(currSum - u->val);
                    nodes.push(u->right);
                    num.push(currSum - u->val);
                }
            }

        }

        return false;
    }
};
