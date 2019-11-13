/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == 0 && l2 == 0) return 0;
        if (l1 == 0) return l2;
        if (l2 == 0) return l1;

        ListNode *n = new ListNode(-1);
        // cout << n->val << endl;
        ListNode *head = n;

        while (l1 && l2) {
            // cout << "hi" << endl;
            if (l1->val <= l2->val) {
                n->next = l1;
                l1 = l1->next;
            } else if (l1->val > l2->val) {
                n->next = l2;
                l2 = l2->next;
            }
            // we don't need to handle equal because, in the next step, it will
            // be less than someone.
            // cout << n->next->val << endl;
            n = n->next;
        }

        // it's possible that only one of them became null
        // or both of them became null
        // so, add the one who is non-null to the linked list as it's sorted already.
        if (l1) n->next = l1;
        else n->next = l2;

        return head->next;
    }
};