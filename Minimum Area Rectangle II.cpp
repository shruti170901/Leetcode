class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      ListNode* endpoint=list1;
      ListNode* firstpoint=list1->next;
      ListNode* temp1=list1;
      ListNode* temp=list1;
      while(endpoint->val!=b)
      {
        endpoint=endpoint->next;
      }
      ListNode* lastlist=endpoint->next;
      endpoint->next=nullptr;
      while(firstpoint->val!=a)
      {
        temp1=temp1->next;
        firstpoint=firstpoint->next;
      }
      temp1->next=list2;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=lastlist;
      return list1;
    }
};
