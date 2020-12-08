// https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* f(vector<int>& v, int l, int r){
        if(r<l) return NULL;
        TreeNode *root;
        int i, idx=l;
        for(i=l+1;i<=r;i++){
            if(v[i]>v[idx]) idx=i;
        }
        root=new TreeNode;
        root->val=v[idx];
        root->left=f(v, l, idx-1);
        root->right=f(v, idx+1, r);
        return root;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return f(nums, 0, nums.size()-1);
    }
};