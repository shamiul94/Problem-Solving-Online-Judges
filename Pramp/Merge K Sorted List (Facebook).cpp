
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Time: O(n*m), Space: O(u)

class Solution {
    int vectorIdx;      // which unique element we are checking now
    int currentCounter; // how many of the current unique number has been covered till now.
    // Space: O(u)
    vector<pair<int, int>> v;

public:
    Solution(vector<ListNode *> &lists) {
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

        // O(u) : u = unique element aong all lists.
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
        // return ret = ret->next;
    }

    // O(1)
    bool hasNext() {
        // we have completed traversing the list.
        if (vectorIdx > v.size() - 1) return false;
        // it means, there is a whole another unique number in the list untouched yet.
        if (vectorIdx < v.size() - 1) return true;

        // if equal, that means we are at the last unique number
        pair<int, int> curr = v[vectorIdx];

        if (currentCounter < curr.second) {
            return true;
        } else {
            return false;
        }
    }

    // O(1)
    int next() {
        // not necessary if hasnext() is always true
        // we have completed all elements.
        if (vectorIdx > v.size()) {
            return -1;
        }

        // assuming that hasnext() is always true
        pair<int, int> tem = v[vectorIdx];

        if (currentCounter < tem.second) { // there are more occurences of this number.
            currentCounter++;
            return tem.first;
        }

        if (currentCounter == tem.second) { // this is the last occurence of this number.
            vectorIdx++;
            currentCounter = 0;
            return tem.first;
        }

        // currentCounter > tem.second is not possible as currentcounter is set to 0 once it equals to the count value.
    }
};
