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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        int sum=0,carry=0;
        ListNode*x=l1;
        ListNode*y=l2;
         ListNode*z=new ListNode(-1);
         ListNode*z2=nullptr;
        while(x!=nullptr&&y!=nullptr){
            sum=x->val+y->val+carry;
            carry=sum/10;
            x=x->next;
            y=y->next;
            z->next=new ListNode(sum%10);
            if(z2==nullptr){
                z2=z->next;
            }
            z=z->next;
        }
        if(x!=nullptr){
            while(x!=nullptr){
                sum=x->val+carry;
            carry=sum/10;
            x=x->next;
            z->next=new ListNode(sum%10);
                z=z->next;
            }
        }
         if(y!=nullptr){
            while(y!=nullptr){
                sum=y->val+carry;
            carry=sum/10;
            y=y->next;
             z->next=new ListNode(sum%10);
                z=z->next;
            }
        }
        if(carry!=0){
             z->next=new ListNode(carry);
        }
        return z2;
    }
};
