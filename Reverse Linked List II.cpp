// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* rev(ListNode* h, ListNode* t){
        ListNode* prev=t, *curr=h, *nex;
        while(curr!=t){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || head->next==NULL || m==n) return head;
        ListNode* dummy=new ListNode(0, head);
        ListNode *t1=dummy, *t2;
        int i=1;
        while(i<m){
            t1=t1->next;
            i++;
        }
        t2=t1;
        while(i<=n){
            t2=t2->next;
            i++;
        }
        t2=t2->next;
        t1->next=rev(t1->next, t2);
        return dummy->next;
    }
};