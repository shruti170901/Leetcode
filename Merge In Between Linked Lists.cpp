class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = list1;
        b = (b - a) + 2;
        
        ListNode* help = dummy;
        
        while(a != 0 && help){
            help = help->next;
            a--;
        }
        
        ListNode* ne_node = help;
        while(b != 0 && help){
            help = help->next;
            b--;
        }
        
        ListNode* fi_node = help;
        ne_node->next = list2;
        
        while(ne_node->next){
            ne_node = ne_node->next;
        }
        
        ne_node->next = fi_node;
        
        return list1;
    }
};
