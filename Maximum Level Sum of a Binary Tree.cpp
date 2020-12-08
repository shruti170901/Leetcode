// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    map<int, int> m;
    void trav(TreeNode* root, int lvl){
        if(root==NULL) return;
        m[lvl]+=root->val;
        trav(root->left, lvl+1);
        trav(root->right, lvl+1);
    }
    int maxLevelSum(TreeNode* root) {
        trav(root, 1);
        int mx=1;
        for(auto it:m){
            if(it.second>m[mx]) mx=it.first;
        }
        return mx;
    }
};