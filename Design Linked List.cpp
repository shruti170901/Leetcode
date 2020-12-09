struct node{
    int val;
    node *next;
    
    node() {val=0;next=nullptr;}
    node(int value){val=value;next=nullptr;}
};


class MyLinkedList {
private:
    node *head;
public:
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=nullptr;
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int count=0;
        node *ptr= this->head;
        while(ptr!=NULL){
            if(count==index) return ptr->val;
            count++;
            ptr=ptr->next;
        }
        
        return -1;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *temp = new node(val);
        if(this->head==NULL){
            this->head=temp;
        }else{
            temp->next=this->head;
            this->head=temp;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *temp=new node(val);
        if(this->head==NULL){
            this->head=temp;
        }else{
            node *top=this->head;
            while(top->next!=NULL){
                top=top->next;
            }
            top->next=temp;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index==0){
            this->addAtHead(val);
        }else{
            node *top =this->head;
            int c=1;
            while(top->next!=NULL){
                if(c==index){
                    node *obj= new node(val);
                    obj->next=top->next;
                    top->next=obj;
                    return;
                }
                top=top->next;
                c++;
            }
            if(c==index){
                    node *obj= new node(val);
                    top->next=obj;
                    return;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index==0){
            this->head=this->head->next;
        }else{
            node *temp = this->head;
            int c=1;
            while(temp->next!=NULL){
                // cout<<temp->val<<" ";
                if(c==index){
                    // cout<<temp->next->val<<" ";
                    temp->next=temp->next->next;
                    return;
                }
                c++;
                temp=temp->next;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */