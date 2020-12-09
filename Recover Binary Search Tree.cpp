// https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode *t1, *t2, *prev;
    void check1(TreeNode* root){
        if(root==NULL) return;
        check1(root->left);
        if(!t1 && root->val<prev->val){
            t1=prev;
        }
        if(t1!=NULL && root->val<prev->val){
            t2=root;
        }
        prev=root;
        check1(root->right);
    }
    void recoverTree(TreeNode* root) {
        t1=NULL; t2=NULL; prev=new TreeNode(INT_MIN);
        check1(root);
        swap(t1->val, t2->val);
        return;
    }
};