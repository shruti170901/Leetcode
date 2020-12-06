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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *t1=head, *t2=head;
        int d=0;
        while(d<n){
            d++;
            t2=t2->next;
        }
        if(t2==NULL) return t1->next;
        t2=t2->next;
        while(t2!=NULL){
            t2=t2->next;
            t1=t1->next;
        }
        t1->next=t1->next->next;
        return head;
    }
};