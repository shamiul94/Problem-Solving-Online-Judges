
#include <bits/stdc++.h>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *ans;

    ListNode *solve(ListNode *head) {
        if (!head) return nullptr;
        if (head->next == nullptr) {
            return ans = head;
        }

        ListNode *tem;
        tem = solve(head->next);
        tem->next = head;
        tem->next->next = nullptr;
        return tem->next;
    }

    ListNode *reverseList(ListNode *head) {
        ans = nullptr;
        solve(head);
        return ans;
    }
};

int main() {
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);

//    while (l) {
//        cout << l->val << " -> ";
//        l = l->next;
//    }

    Solution s;
    ListNode *p = s.reverseList(l);
//
//    while (p) {
//        cout << p->val << " -> ";
//        p = p->next;
//    }
    cout << endl;
    return 0;

}