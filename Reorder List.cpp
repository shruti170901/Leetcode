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
#define ll long long 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head){
            return ;
        }
        if(!head->next){
            return;
        }
        if(!head->next->next){
            return;
        }
        stack<ListNode*>list;
        ListNode* ptr=head;
        ListNode* start=head;
        int size=0;
        while(ptr!=NULL){
            list.push(ptr);
            size++;
            ptr=ptr->next;
        }
        ListNode* temp;
        for(int i=0;i<size/2;i++){
            temp=list.top();
            list.pop();
            temp->next=start->next;
            start->next=temp;
            start=start->next->next;
        }
        start->next = NULL;
    }
};
