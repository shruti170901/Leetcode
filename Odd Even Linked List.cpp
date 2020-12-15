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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* second = head->next;
        
        while(odd!=NULL && odd->next!=NULL && even->next!=NULL){
            odd->next = odd->next->next;
            odd = odd->next;
            
            even->next = even->next->next;
            even = even->next;
        }
        
        odd->next = second;
        return head;
    
    }
};