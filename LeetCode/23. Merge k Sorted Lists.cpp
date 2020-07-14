
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

////////////////////// Merge Sort Based //////////////////////////////


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
    }
};




/////////////////////// Priority Queue based - not too good either. (25%, 25%)///////////////////////

struct compare {
    bool operator()(const ListNode *l1, const ListNode *l2) {
        return l1->val > l2->val;
    }
};

class Solution3 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        ListNode *ans = new ListNode(0);
        ListNode *ret = ans;
        while (!pq.empty()) {
            ListNode *top = pq.top();
            pq.pop();
            cout << top->val << endl;
            ans->next = new ListNode(top->val);
            ans = ans->next;
            // cout << ans->val << endl;
            if (top->next) {
                pq.push(top->next);
            }
        }

        return ret->next;
    }
};

//////////////////// Map based - Time 67%, Memory 9% //////////////////////////

// Time: O(n*m), Space: O(u)

class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // space: O(u): u = unique numbers
        unordered_map<int, int> um; // <unique number, count>

        // O(n * m)
        for (int i = 0; i < lists.size(); i++) { // O(n) : n = no of lists
            ListNode *l = lists[i];              // O(1)
            while (l) {                          // O(m) : m = average element number in a list
                if (um.count(l->val) == 0) {     // value is not in map
                                                 // O(1) : hashmap's insertion, lookup time complexity is amortized constant.
                    um[l->val] = 1;              // O(1)
                } else {
                    um[l->val]++;
                }
                l = l->next;
            }
        }

        unordered_map<int, int>::iterator it;

        // Space: O(u)
        vector<pair<int, int>> v;

        // O(u) : u = unique element among all lists.
        for (it = um.begin(); it != um.end(); it++) {
            v.push_back(make_pair(it->first, it->second));
        }

        // O(u*log(u))
        sort(v.begin(), v.end());

        ListNode *ans = new ListNode(0);
        ListNode *ret = ans;

        // O(u*avgOccur) == O(total element number) == O(n*m) ; (I argue)
        for (int i = 0; i < v.size(); i++) {        // O(u)
            for (int j = 0; j < v[i].second; j++) { // O(avgOccur): avgOccur = average occurrence of a number
                ans->next = new ListNode(0);
                ans = ans->next;
                ans->val = v[i].first;
            }
        }
        return ret = ret->next;
    }
};

///////////////// Bruteforce ///////////////////////

class Solution1 {
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

/////////////////////////////////////////////////////////////
