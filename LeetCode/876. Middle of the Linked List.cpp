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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0; 
        ListNode* tem = head; 
        
        while(tem != 0){
            len++; 
            tem = tem->next;     
        }
        
        int mid = len/2 , i = 0; // idx 
        tem = head; 
        
        while(i < mid){
            i++;
            tem = tem->next; 
        }
        return tem; 
    }
};