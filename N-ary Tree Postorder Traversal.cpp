// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> v;
    void post(Node* root){
        if(root==NULL) return;
        for(int i=0;i<root->children.size();i++){
            post(root->children[i]);
        }
        v.push_back(root->val);
    } 
    vector<int> postorder(Node* root) {
        post(root);
        return v;
    }
};