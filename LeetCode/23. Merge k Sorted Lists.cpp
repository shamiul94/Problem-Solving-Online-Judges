
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//////////////////// Map based - Time 67%, Memory 9% //////////////////////////

/*
Idea: 
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

