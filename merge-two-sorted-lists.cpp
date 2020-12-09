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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode* it;
        ListNode* h;
        if (l1->val < l2->val) {
            h = l1;
            l1 = l1->next;
        } else {
            h = l2;
            l2 = l2->next;
        }
        it = h;
        while (l1 != nullptr) {
            if (l2 == nullptr) {
                it->next = l1;
                return h;
            }
            if (l1->val < l2->val) {
                it->next = l1;
                l1 = l1->next;
                it = it->next;
            } else {
                it->next = l2;
                l2 = l2->next;
                it = it->next;
            }
        }
        it->next = l2;
        return h;
    }
};
