// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int ans=0;
    void rec(TreeNode* root, int mx){
        if(root==NULL) return;
        if(root->val>=mx){
            ans++;
            mx=root->val;
        }
        rec(root->left, mx);
        rec(root->right, mx);
        
        
    }
    int goodNodes(TreeNode* root) {
        rec(root, root->val);
        return ans;
    }
};