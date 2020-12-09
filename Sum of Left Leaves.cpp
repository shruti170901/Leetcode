// https://leetcode.com/problems/sum-of-left-leaves/

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
    void sum(TreeNode* root, int &s, int x){
        if(!root) return;
        if(!root->left && !root->right){
            if(x==0) s+=root->val;
            return;
        }
        sum(root->left, s, 0);
        sum(root->right, s, 1);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int s=0;
        sum(root, s, 1);
        return s;
    }
};