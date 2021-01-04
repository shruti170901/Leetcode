struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *h,*t;
    h=t=head;
    while(h&&h->next){
        h=h->next->next;
        t=t->next;
    }
    return t;
}
