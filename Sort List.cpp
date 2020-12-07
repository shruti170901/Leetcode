// https://leetcode.com/problems/sort-list/

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
    ListNode* merge(ListNode* t1, ListNode* t2){
        if(!t1) return t2;
        if(!t2) return t1;
        ListNode* temp, *ret;
        if(t1->val<t2->val){
            temp=t1;
            t1=t1->next;
        }
        else{
            temp=t2;
            t2=t2->next;
        }
        ret=temp;
        while(t1 && t2){
            if(t1->val<t2->val){
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
            }
            else{
                temp->next=t2;
                t2=t2->next;
                temp=temp->next;
            }
        }
        if(!t1) temp->next=t2;
        else temp->next=t1;
        return ret;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        head=sortList(head);
        fast=sortList(fast);
        return merge(head, fast);
    }
};