#include <bits/stdc++.h>

using namespace std;
//
//Definition for
//a binary
//tree node
//.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int X;
    int Y;
    int val;

    Node(int _X, int _Y, int _val) {
        X = _X;
        Y = _Y;
        val = _val;
    }
};

bool operator<(const Node &n1, const Node &n2) {
    if (n1.X < n2.X) {
        // if n1 is on the left of n2, then n1 is 'smaller' than n2.
        return true;
    } else if (n1.X == n2.X) {
        // if n1 and n2 has same X, we have to check Y values.
        if (n1.Y < n2.Y) {
            // if n1 and n2 has same X but n1 has smaller Y, then n1 is situated 'below' n2. So, n2 should come first in the answer. So, n2 should be 'smaller'. Hence, we return false.
            return false;
        } else if (n1.Y == n2.Y) {
            //  if n1 and n2 has same X and Y, we will sort them by their values.
            return n1.val < n2.val;
        } else {
            //  opposite case of if (n1.Y < n2.Y)
            return true;
        }
    } else {
        return false;
    }
}


class Solution {
public:
    void solve(TreeNode *root, int x, int y, vector<Node> &nodes) {
        if (root == nullptr) {
            return;
        }

        nodes.push_back(Node(x, y, root->val));

        solve(root->left, x - 1, y - 1, nodes);
        solve(root->right, x + 1, y - 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<Node> nodes;
        solve(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        int prevX, idx = 0;
        vector<vector<int>> ans;
        ans.emplace_back();
        ans[idx].push_back(nodes[0].val);
        prevX = nodes[0].X;

        // clustering them by X as they are already sorted thorugh necessary criteria.
        for (int i = 1; i < nodes.size(); i++) {
            if (prevX == nodes[i].X) {
                ans[idx].push_back(nodes[i].val);
            } else {
                ans.emplace_back();
                idx++;
                ans[idx].push_back(nodes[i].val);
            }
            prevX = nodes[i].X;
        }

        return ans;
    }
};


int main() {
    Node a(1, 1, 2);
    Node b(1, 2, 9);
    Node c(2, 1, 5);
    Node d(3, 1, 4);
    Node e(1, 1, 3);
    Node f(1, 2, 1);

    vector<Node> v{a, b, c, d, e, f};

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].X << " , " << v[i].Y << " -> " << v[i].val << endl;
    }
}
