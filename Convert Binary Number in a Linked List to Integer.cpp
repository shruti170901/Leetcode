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
    int getDecimalValue(ListNode* head){
        int len=0;
        ListNode* head1=head;
        while(head1->next!=NULL){
            len++;
            head1=head1->next;
        }
        int cnt=0;
        while(head!=NULL){
            if(head->val==0){
                len--;
                //ntinue;
            }else{
            cnt+=1<<len;
                len--;
            }
            head=head->next;
        }
        return cnt;
    }
};
