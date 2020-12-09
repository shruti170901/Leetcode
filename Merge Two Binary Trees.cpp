// https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* merge(TreeNode* t1, TreeNode* t2){
        TreeNode* temp=new TreeNode;
        if(t1!=NULL && t2!=NULL){
            temp->val=t1->val+t2->val;
            temp->left=merge(t1->left, t2->left);
            temp->right=merge(t1->right, t2->right);
        }
        else if(t1!=NULL){
            temp->val=t1->val;
            temp->left=merge(t1->left, NULL);
            temp->right=merge(t1->right, NULL);
        }
        else if(t2!=NULL){
            temp->val=t2->val;
            temp->left=merge(NULL, t2->left);
            temp->right=merge(NULL, t2->right);
        }
        else return NULL;
        return temp;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1, t2);
    }
};