// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0 || k==1) return head;
        ListNode* d=new ListNode(0, head), *curr, *prev, *nex, *trav, *s1, *s2;
        s1=d;
        while(true){
            int i=0;
            trav=s1;
            while(trav!=NULL && i<k){
                i++;
                trav=trav->next;
            }
            if(trav==NULL) break;
            prev=s1->next;
            curr=prev->next;
            nex=curr->next;
            s1->next=trav;
            s1=prev;
            prev->next=trav->next;
            while(curr!=trav){
                curr->next=prev;
                prev=curr;
                curr=nex;
                nex=curr->next;
            }
            curr->next=prev;
        }
        return d->next;
    }
};