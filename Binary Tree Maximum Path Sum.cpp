// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int mx;
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        int temp=root->val, l=rec(root->left), r=rec(root->right);
        mx=max(temp+l+r, mx);
        return max(temp+max(l,r), 0);
    }
    int maxPathSum(TreeNode* root) {
        mx=root->val;
        rec(root);
        return mx;
    }
};