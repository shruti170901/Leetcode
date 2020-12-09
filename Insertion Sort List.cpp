// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev=head, *curr=head->next, *temp, *dummy=new ListNode(0, head), *t;
        while(curr!=NULL){
            //cout<<prev->val<<" "<<curr->val<<endl;
            if(curr->val<prev->val){
                temp=dummy;
                while(temp->next->val<curr->val){
                    temp=temp->next;
                }
                //cout<<temp->val<<" ";
                t=curr->next;
                curr->next=temp->next;
                temp->next=curr;
                curr=t;
                prev->next=t;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
            //cout<<prev->val<<endl;
            //if(curr==NULL) cout<<"HERE\n";
        }
        return dummy->next;
    }
};