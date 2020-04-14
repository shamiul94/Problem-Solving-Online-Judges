
#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:

    int Length(ListNode *l) {
        if (l == nullptr) {
            return 0;
        }
        return 1 + Length(l->next);
    }

    void printLL(ListNode *l) {
        if (l == nullptr) {
            return;
        }

        cout << l->val << "->";
        printLL(l->next);
    }

    int solve(ListNode *longer, ListNode *shorter, int longerLen, int shorterLen, ListNode *result, int level) {
        if (longer == nullptr && shorter == nullptr) {
            return -1;
        }

        result->next = new ListNode(0);

        /**understand this logic
         * 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8
         *                     3 - 4 - 5
         * |-----------------|
         * this range can only add carry with the first number.
         * and this range lies between (0 to longerLen - shorterLen)
         **/

        if (level <= longerLen - shorterLen) {
            int add = solve(longer->next, shorter, longerLen, shorterLen, result->next, level + 1);
            if (add == -1) {
                result->next = nullptr;
                add = 0;
            }
            result->val = (longer->val + add) % 10;
//            cout << longer->val << " " << shorter->val << " " << add << " " << longer->val + add << endl;

            return (longer->val + add) / 10;
        } else {
            int add = solve(longer->next, shorter->next, longerLen, shorterLen, result->next, level + 1);
            if (add == -1) {
                result->next = nullptr;
                add = 0;
            }
            result->val = (longer->val + shorter->val + add) % 10;
//            cout << longer->val << " " << shorter->val << " " << add << " " << longer->val + shorter->val + add << endl;

            return (longer->val + shorter->val + add) / 10;
        }
    }


    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int length1 = Length(l1);
        int length2 = Length(l2);

        ListNode *result = new ListNode(0);

        int carry = -1;
        if (length1 < length2) {
            carry = solve(l2, l1, length2, length1, result, 1);
        } else {
            carry = solve(l1, l2, length1, length2, result, 1);
        }

        if (carry == 1) {
            ListNode *newRoot = new ListNode(carry);
            newRoot->next = result;
            result = newRoot;
        }

        return result;
    }
};
