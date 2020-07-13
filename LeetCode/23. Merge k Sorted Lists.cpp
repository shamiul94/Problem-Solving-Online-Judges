
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

/*

[
  1->4->5,
  1->3->4,
  2->6
]

//O(m*n * log(mn))

map[1] = 2  
map[4] = 2  
map[5] = 1  
map[3] = 1  
map[2] = 1  
map[6] = 1  

// O(u*log(u))

vector<pair<int, int>> v {(1,2), (4,2), (5,1), (3,1), (2,1), (6,1)}; // O(u*log(u))

After sorting: 

passedTillNow = 0 
idx = 0 

vector<pair<int, int>> v {(1,2), (2,1), (3,1), (4,2), (5,1), (6,1)}; 


*/

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        unordered_map<int, int> um; // <unique number, count>
        for (int i = 0; i < lists.size(); i++) {
            ListNode *l = lists[i];
            while (l) {
                if (um.count(l->val) == 0) { // value is not in map
                    um[l->val] = 1;
                } else {
                    um[l->val]++;
                }
                l = l->next;
            }
        }

        unordered_map<int, int>::iterator it;
        vector<pair<int, int>> v;

        for (it = um.begin(); it != um.end(); it++) {
            v.push_back(make_pair(it->first, it->second));
        }

        sort(v.begin(), v.end());

        ListNode *ans = new ListNode(0);
        ListNode *ret = ans;

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].second; j++) {
                ans->next = new ListNode(0);
                ans = ans->next;
                ans->val = v[i].first;
            }
        }
        return ret = ret->next;
    }
};
