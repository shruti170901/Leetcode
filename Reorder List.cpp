// https://leetcode.com/problems/reorder-list/

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
    ListNode* rev(ListNode* h){
        ListNode* curr=h, *prev=NULL, *nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* t1=head, *t2=head;
        if(head==NULL || head->next==NULL) return;
        while(t2!=NULL && t2->next!=NULL){
            t1=t1->next;
            t2=t2->next->next;
        }
        ListNode *t3, *t4;
        t2=t1->next;
        t2=rev(t2);
        t1->next=NULL;
        t1=head;
        int flag=0;
        while(t1 && t2){
            t3=t1->next;
            t4=t2->next;
            t1->next=t2;
            t2->next=t3;
            t1=t3;
            t2=t4;
        }
        return;
    }
};