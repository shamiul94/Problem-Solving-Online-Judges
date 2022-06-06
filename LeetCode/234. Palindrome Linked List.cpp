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
        ListNode *next = curr->next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
        {
            return true;
        }

        ListNode *mid = findMid(head);

        ListNode *firstHalfIterator = head;
        ListNode *reversedSecondHalfIterator = reverseLinkedList(mid);

        while (firstHalfIterator && reversedSecondHalfIterator)
        {
            if (firstHalfIterator->val != reversedSecondHalfIterator->val)
            {
                return false;
            }
            firstHalfIterator = firstHalfIterator->next;
            reversedSecondHalfIterator = reversedSecondHalfIterator->next;
        }

        return true;
    }
};
