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
        ListNode *ans, *ansh, *h1, *h2;
        h1=l1; h2=l2;
        int carry=0, temp, flag=1;
        while(h1!=NULL && h2!=NULL){
            if(flag){
                ans=new ListNode;
                ansh=ans;
                flag=0;
            }
            else{
               ansh->next=new ListNode;
                ansh=ansh->next;
            }
            temp=h1->val+h2->val+carry;
            ansh->val=temp%10;
            carry=temp/10;
            h1=h1->next; h2=h2->next;
        }
        while(h1!=NULL){
            ansh->next = new ListNode;
            ansh=ansh->next;
            temp=h1->val+carry;
            ansh->val=temp%10;
            carry=temp/10;
            h1=h1->next;
        }
        while(h2!=NULL){
            ansh->next = new ListNode;
            ansh=ansh->next;
            temp=h2->val+carry;
            ansh->val=temp%10;
            carry=temp/10;
            h2=h2->next;
        }
        if(carry){
            ansh->next=new ListNode;
            ansh=ansh->next;
            ansh->val=carry;
        }
        return ans;
    }
};