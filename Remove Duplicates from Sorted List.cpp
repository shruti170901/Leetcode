// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        //if(!head) return head;
        //ListNode* dummy=new ListNode(0, head);
        ListNode* curr=head;
        while(curr && curr->next){
            while(curr->next && curr->val==curr->next->val){
                curr->next=curr->next->next;
            }
            curr=curr->next;
        }
        return head;
    }
};