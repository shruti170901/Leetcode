// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *t1=root, *t2;
        int i=1, j, k, mask=2, dep=0;
        while(t1){
            t1=t1->right;
            dep++;
        }
        //cout<<dep<<endl;
        dep--;
        while(i<=dep){
            mask=1<<i;
            t1=root;
            for(j=i-1;j>=0;j--){
                if(mask&(1<<j)) t1=t1->right;
                else t1=t1->left;
            }
            for(mask++;mask<1<<(i+1);mask++){
                t2=root;
                for(j=i-1;j>=0;j--){
                    if(mask&(1<<j)) t2=t2->right;
                    else t2=t2->left;
                }
                //cout<<endl<<t1->val<<t2->val<<endl;
                t1->next=t2;
                t1=t2;
            }
            i++;
            //cout<<t1->val<<" "<<t2->val<<endl;
        }
        return root;
    }
};