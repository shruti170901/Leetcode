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
    
    int ans,z,cnt=0;
    
    void inorder(TreeNode* root)
    {
        if(root==NULL)return;
        inorder(root->left);
        cnt++;
        if(cnt==z)ans=root->val;
        inorder(root->right);
    }
    
    
    int kthSmallest(TreeNode* root, int k) 
    {
        z=k;
        inorder(root);
        return ans;
    }
};