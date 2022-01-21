//
// Created by shamiul93 on 10/29/19.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    
    void getInOrderTraversal(TreeNode* root, vector<int> &inOrderNodeList){
        if(root == NULL) return; 
        
        getInOrderTraversal(root -> left, inOrderNodeList);
        inOrderNodeList.push_back(root->val); 
        getInOrderTraversal(root -> right, inOrderNodeList); 
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrderNodeList; 
        
        getInOrderTraversal(root, inOrderNodeList);
        
        return inOrderNodeList;
    }
};

///////////


class Solution2 {
public:
    vector<int> inorderTraversalRecursive(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        vector<int> leftVec = inorderTraversal(root->left);
        ret.insert(ret.end(), leftVec.begin(), leftVec.end());

        ret.push_back(root->val);

        vector<int> rightVec = inorderTraversal(root->right);
        ret.insert(ret.end(), rightVec.begin(), rightVec.end());

        return ret;
    }
};
