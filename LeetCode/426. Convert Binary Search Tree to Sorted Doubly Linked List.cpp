// @author: Shamiul Hasan

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == 0)
        {
            return 0;
        }

        // leftHead and rightHead both will be doubly + circular linked lists themselves
        Node *leftHead = treeToDoublyList(root->left);
        Node *rightHead = treeToDoublyList(root->right);

        // we are making the root node itself a CDLL so that we can merge it with left
        // and right
        root->left = root;
        root->right = root;

        return connectCDLLs(connectCDLLs(leftHead, root), rightHead);
    }

    Node *connectCDLLs(Node *head1, Node *head2)
    {
        if (head1 == 0)
            return head2;
        if (head2 == 0)
            return head1;

        // These two lines are pure poetry.
        // As the DLL is CIRCULAR, the left node of the head is definitely the tail. ***
        // so, we don't have to traverse through the whole DLL to get the tail. That helps us to find
        // the tail in O(1) instead of O(n).

        // Note: If the problem was not about CIRCULAR queue,
        // these 2 lines would not be possible
        Node *tail1 = head1->left;
        Node *tail2 = head2->left;

        // - node1  <->   node2 -
        // |                    |
        // ^--------------------^

        tail1->right = head2;
        head2->left = tail1;

        tail2->right = head1;
        head1->left = tail2;

        // we are returning head1, because, we are inherently assuming that
        // head1 comes from smaller elements while head2 consists of larger elements.
        return head1;
    }
};