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

    int arr[2000][2];
    int maxDepth = -1;

    void solve(TreeNode *root, int currDepth, int currNodeIdx) {

        if (root == 0) return;

        if (maxDepth < currDepth) maxDepth = currDepth;

        // for the lowest index in that level
        // if [0] is still -1, it hasn't been changed. or,
        // if[0] has another value but current index is less than that previous value,
        // it means that current index should be the lowest value
        // (which is impossible because, dfs does a serial-wise traversal)
        if (arr[currDepth][0] == -1 || arr[currDepth][0] > currNodeIdx) {
            arr[currDepth][0] = currNodeIdx;
        }
            // almost same thing is being done here, but for the
            // highest non-null index of that level
        else if (arr[currDepth][1] == -1 || arr[currDepth][1] < currNodeIdx) {
            arr[currDepth][1] = currNodeIdx;
        }

        int leftChildIdx = (2 * (currNodeIdx % INT_MAX) + 1) % INT_MAX;
        int rightChildIdx = (2 * (currNodeIdx % INT_MAX) + 2) % INT_MAX;
        int childDepth = currDepth + 1;

        solve(root->left, childDepth, leftChildIdx);
        solve(root->right, childDepth, rightChildIdx);
    }

    int widthOfBinaryTree(TreeNode *root) {
        memset(arr, -1, sizeof(arr));
        solve(root, 0, 0);
        int maxWidth = -1;
        for (int i = 0; i <= maxDepth; i++) {
            int diff;

            // checking if the highest value is -1, because, that means that a
            // lowest index was found in that level but no higher index was traversed
            // meaning that, there was only one node in that level.
            // might be the first level, where there is supposed to be just one node
            // or, may be it's such a level, where node except one is null.
            // in both these cases, width is 1.

            if (arr[i][1] == -1) {
                diff = 1;
            } else {
                diff = arr[i][1] - arr[i][0] + 1;
            }

            if (maxWidth < diff) {
                maxWidth = diff;
            }
        }
        return maxWidth;
    }
};
