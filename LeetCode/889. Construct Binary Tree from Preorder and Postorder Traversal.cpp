//
// Created by heisenberg on 4/3/20.
//


#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *solve(vector<int> &pre, vector<int> &post,
                    unordered_map<int, int> &pre_um, unordered_map<int, int> &post_um,
                    int preStart, int preEnd,
                    int postStart, int postEnd) {

        if (postStart > postEnd || preStart > preEnd) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(pre[preStart]);
        if (postStart == postEnd || preStart == preEnd) {
            return root;
        }


        int postFirstRightChild = post[postEnd - 1];
        int preFirstLeftChild = pre[preStart + 1];

        if (postFirstRightChild != preFirstLeftChild) {
            // root has both left and right child
            int postDivIdx, preDivIdx;
            postDivIdx = post_um[preFirstLeftChild];
            preDivIdx = pre_um[postFirstRightChild];

            root->left = solve(pre, post, pre_um, post_um,
                               preStart + 1, preDivIdx - 1,
                               postStart, postDivIdx);

            root->right = solve(pre, post, pre_um, post_um,
                                preDivIdx, preEnd,
                                postDivIdx + 1, postEnd - 1);
        } else {
            // root doesn't have either right or left child
            root->left = solve(pre, post, pre_um, post_um,
                               preStart + 1, preEnd,
                               postStart, postEnd - 1);
        }
        return root;
    }


    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        unordered_map<int, int> pre_um;
        unordered_map<int, int> post_um;

        for (int i = 0; i < post.size(); i++) {
            pre_um[pre[i]] = i;
        }

        for (int i = 0; i < post.size(); i++) {
            post_um[post[i]] = i;
        }

        return solve(pre, post, pre_um, post_um, 0, pre.size() - 1, 0, post.size() - 1);
    }
};