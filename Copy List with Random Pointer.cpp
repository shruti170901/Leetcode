// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *t1, *t2=head, *ret;
        unordered_map<Node*, Node*> m;
        m[NULL]=NULL;
        while(t2){
            t1=new Node(t2->val);
            m[t2]=t1;
            t2=t2->next;
        }
        t1=m[head];
        ret=t1;
        t2=head;
        while(t2){
            t1->next=m[t2->next];
            t1->random=m[t2->random];
            t1=t1->next;
            t2=t2->next;
        }
        return ret;
    }
};