/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{
public:
    stack<TreeNode *> stk;

    void traverseTowardsSmallestNode(TreeNode *root)
    {
        if (root == 0)
        {
            return;
        }
        stk.push(root);
        traverseTowardsSmallestNode(root->left);
    }

    BSTIterator(TreeNode *root)
    {
        traverseTowardsSmallestNode(root);
    }

    int next()
    {
        TreeNode *top = stk.top();
        stk.pop();
        traverseTowardsSmallestNode(top->right);
        return top->val;
    }

    bool hasNext()
    {
        return stk.size() > 0;
    }
};
// +1 7752477507

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 
 
 
 stack - [7, 3,]
 
 
 */