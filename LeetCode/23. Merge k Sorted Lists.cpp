
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        ListNode *l = new ListNode(0);
        l->next = 0;
        while (true) { // give some condition?
            int minValThisRun = INT_MAX;
            ListNode *minNode = 0;

            for (int i = 0; i < n; i++) {
                if (lists[i] != 0 && lists[i]->val < minValThisRun) {
                    minValThisRun = lists[i]->val;
                    minNode = lists[i];
                }
            }
            if (minNode == 0) break;
            l->next = minNode;
            minNode = minNode->next;
        }
        return l->next;
    }
};
