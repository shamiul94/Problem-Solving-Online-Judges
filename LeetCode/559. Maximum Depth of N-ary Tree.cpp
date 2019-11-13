/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node *root) {
        if (root == 0) return 0;


        int n = root->children.size();

        if (n == 0)
            return 1;


        int maxD = 0;

        for (int i = 0; i < n; i++) {
            maxD = max(maxD, maxDepth(root->children[i]));
        }

        return maxD + 1;
    }
};
