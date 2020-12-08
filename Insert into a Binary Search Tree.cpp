// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int v) {
        if(root==NULL){
            root=new TreeNode;
            root->val=v;
        }
        else if(v<root->val){
            if(root->left==NULL){
                root->left=new TreeNode;
                root->left->val=v;
            }
            else insertIntoBST(root->left, v);
        }
        else{
            if(root->right==NULL){
                root->right=new TreeNode;
                root->right->val=v;
            }
            else insertIntoBST(root->right, v);
        }
        return root;
    }
};