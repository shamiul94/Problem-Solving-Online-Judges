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

class subtreeData {
   public: 
    int nodeCount; 
    int sum; 
    
    subtreeData() {
        nodeCount = 0; 
        sum = 0; 
    }
    
    subtreeData(int nodeCount, int sum) {
        this->nodeCount = nodeCount; 
        this->sum = sum; 
    }
}; 


class Solution {
public:
    
    double maxAverage = 0.0;
    
    subtreeData getSubtreeData(TreeNode* root) {
        subtreeData data; 
        if(root == NULL) {
            return subtreeData();
        }
        
        subtreeData left = getSubtreeData(root->left); 
        subtreeData right = getSubtreeData(root->right); 
        
        data.nodeCount = left.nodeCount + right.nodeCount + 1; 
        data.sum = left.sum + right.sum + root->val; 
        
        maxAverage = max(maxAverage, data.sum * 1.0 / data.nodeCount); 
        
        return data; 
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        getSubtreeData(root);
        
        return maxAverage;
    }
};