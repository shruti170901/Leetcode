// https://leetcode.com/problems/binary-tree-pruning/

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
    bool elim(TreeNode* root){
        if(root==NULL) return true;
        if(root->val==1) return false;
        return elim(root->left)&&elim(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(elim(root->left)) root->left=NULL;
        if(elim(root->right)) root->right=NULL;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        return root;
    }
};