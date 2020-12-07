// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int> pre, in;
        if(preorder.size()==0) return NULL;
        int i, j, n=preorder.size();
        TreeNode* root=new TreeNode(preorder[0]);
        for(i=0;i<n && inorder[i]!=preorder[0];i++){
            pre.push_back(preorder[i+1]);
            in.push_back(inorder[i]);
        }
        root->left=buildTree(pre, in);
        pre.clear();in.clear();
        for(;i<n-1;i++){
            pre.push_back(preorder[i+1]);
            in.push_back(inorder[i+1]);
        }
        root->right=buildTree(pre, in);
        return root;
    }
};