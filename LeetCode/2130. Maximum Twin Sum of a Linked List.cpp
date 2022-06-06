/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = head->next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int pairSum(ListNode *head)
    {
        ListNode *mid = findMid(head);

        ListNode *headOfFirstHalf = head;
        ListNode *headOfReversedSecondHalf = reverseLinkedList(mid);

        int maxTwinSum = 0;

        while (headOfFirstHalf && headOfReversedSecondHalf)
        {
            maxTwinSum = max(maxTwinSum, headOfFirstHalf->val + headOfReversedSecondHalf->val);
            headOfFirstHalf = headOfFirstHalf->next;
            headOfReversedSecondHalf = headOfReversedSecondHalf->next;
        }

        return maxTwinSum;
    }
};

/**

1 2 3 4 5 6

1. find the mid element
    1.1 slow = slow -> next ; fast = fast -> next -> next


2. reverse the second half of the linked list (starting from mid element)
    2.1

3. first half + reversed second half --> find the max



twins - (1,6), (2,5), (3,4) ..



*/