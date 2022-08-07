/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        unordered_map<Node *, Node *> umap;

        Node *curr = head;

        while (curr)
        {
            umap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        Node *result = new Node(0);
        Node *finalResult = result;

        curr = head;

        while (curr)
        {
            result->next = umap[curr];
            result->next->next = umap[curr->next];
            result->next->random = umap[curr->random];

            result = result->next;
            curr = curr->next;
        }

        return finalResult->next;
    }
};

/**

(val, next, random)

(7,13,)


*/
