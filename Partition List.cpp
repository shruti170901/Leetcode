// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* t1=new ListNode(0), *t2=new ListNode(0), *temp, *h1, *h2;
        temp=head;
        h1=t1;
        h2=t2;
        while(temp){
            if(temp->val<x){
                t1->next=new ListNode(temp->val);
                temp=temp->next;
                t1=t1->next;
            }
            else{
                t2->next=new ListNode(temp->val);
                temp=temp->next;
                t2=t2->next;
            }
        }
        t1->next=h2->next;
        return h1->next;
    }
};