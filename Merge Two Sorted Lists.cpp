// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans, *t1=l1, *t2=l2, *t3;
        t3=new ListNode;
        ans=t3;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<t2->val){
                t3->next=t1;
                t3=t3->next;
                t1=t1->next;
            }
            else{
                t3->next=t2;
                t3=t3->next;
                t2=t2->next;
            }
        }
        while(t1!=NULL){
            t3->next=t1;
            t3=t3->next;
            t1=t1->next;
        }
        while(t2!=NULL){
            t3->next=t2;
            t3=t3->next;
            t2=t2->next;
        }
        return ans->next;
    }
};