// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    void rec(TreeNode* root, int h, int &mx){
        if(root==NULL) return;
        mx=max(h, mx);
        rec(root->left, h+1, mx);
        rec(root->right, h+1, mx);
    }
    int maxDepth(TreeNode* root) {
        int mx=1;
        if(root==NULL) return 0;
        rec(root, 1, mx);
        return mx;
    }
};