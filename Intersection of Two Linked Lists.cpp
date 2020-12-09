// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        ListNode *t1=headA, *t2=headB;
        while(t1&&t2){
            if(s.find(t1)!=s.end()) return t1;
            s.insert(t1);
            if(s.find(t2)!=s.end()) return t2;
            s.insert(t2);
            t1=t1->next;
            t2=t2->next;
        }
        while(t1){
            if(s.find(t1)!=s.end()) return t1;
            s.insert(t1);
            t1=t1->next;
        }
        while(t2){
            if(s.find(t2)!=s.end()) return t2;
            s.insert(t1);
            t2=t2->next;
        }
        return NULL;
    }
};