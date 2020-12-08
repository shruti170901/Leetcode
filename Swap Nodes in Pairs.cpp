// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* dummy=new ListNode(0, head), *t1, *t2, *t3;
        t1=head;
        t2=t1->next;
        t3=t2->next;
        dummy->next=t2;
        dummy->next->next=t1;
        dummy->next->next->next=swapPairs(t3);
        return dummy->next;
    }
};