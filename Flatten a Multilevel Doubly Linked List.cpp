/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;
        Node *temp = head;
        while(temp != NULL){
            if(temp->child == NULL)
                temp = temp->next;
            else {
                Node *p = temp->child;
                while(p->next != NULL)
                    p = p->next;
                p->next = temp->next;
                if(temp->next != NULL) 
                    temp->next->prev = p;
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
            }
        }
        return head;
    }
};
