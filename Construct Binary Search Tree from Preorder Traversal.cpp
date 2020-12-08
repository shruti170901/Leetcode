// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void ins(TreeNode* root, int v){
        if(v<root->val){
            if(root->left==NULL){
                root->left=new TreeNode;
                root->left->val=v;
            }
            else ins(root->left, v);
        }
        else{
            if(root->right==NULL){
                root->right=new TreeNode;
                root->right->val=v;
            }
            else ins(root->right, v);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        TreeNode* root = new TreeNode, *t;
        root->val=p[0];
        for(int i=1;i<p.size();i++){
            ins(root,p[i]);
        }
        return root;
    }
};