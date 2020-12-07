// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int i=0, len=0;
        ListNode* temp=head, *t2, *t1;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        k=k%len;
        //cout<<len<<k<<endl;
        if(k==0) return head;
        t2=head;
        temp=head;
        while(i<len-k){
            t1=temp;
            temp=temp->next;
            i++;
        }
        t1->next=NULL;
        head=temp;
        while(temp->next!=NULL)temp=temp->next;
        temp->next=t2;
        return head;

    }
};