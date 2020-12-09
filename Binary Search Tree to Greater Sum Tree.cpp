// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    void trav(TreeNode* root, int& v){
        if(root==NULL) return;
        trav(root->right, v);
        root->val+=v;
        v=root->val;
        trav(root->left, v);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int v=0;
        trav(root, v);
        return root;
    }
};