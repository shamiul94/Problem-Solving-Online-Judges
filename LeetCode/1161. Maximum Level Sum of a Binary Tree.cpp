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
    void solve(TreeNode *root, vector<int> &levelArr, int level) {
        if (root == 0) return;

        // if(level > levelArr.size()) { // as we are starting from level 1
        //     levelArr.push_back(0);
        // }

        // level starts from 1 but vector index starts from 0
        // so, level-1 will be levelArr index.

        levelArr[level - 1] = levelArr[level - 1] + root->val;


        solve(root->left, levelArr, level + 1);
        solve(root->right, levelArr, level + 1);
    }

    int maxLevelSum(TreeNode *root) {
        vector<int> levelArr(40, 0);
        int maxVal = 0;
        int minLevel = 0;
        solve(root, levelArr, 1);

        for (int i = 0; i < levelArr.size(); i++) {
            if (maxVal < levelArr[i]) {
                maxVal = levelArr[i];
                minLevel = i + 1;
            }
        }

        return minLevel;
    }
};