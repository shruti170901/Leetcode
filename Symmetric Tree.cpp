// https://leetcode.com/problems/symmetric-tree/

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
    bool rec(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return true;
        else if(!t1 || !t2) return false;
        return t1->val==t2->val && rec(t1->left, t2->right) && rec(t1->right, t2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return root==NULL || rec(root->left, root->right);
    }
};