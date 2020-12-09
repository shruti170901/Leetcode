/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
*/

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail =NULL) {
        if(!root) return tail;        
        TreeNode* res= increasingBST(root->left, root);  // step1: left child
        root->left = NULL;                               // step2: root
        root->right= increasingBST(root->right, tail);   // step3: right child
        return res;
    }
};
