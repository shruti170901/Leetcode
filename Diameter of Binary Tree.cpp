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
    int height(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int ans=1+max(height(node->left),height(node->right));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lheight=height(root->left);
        int rheight=height(root->right);
        return max(lheight+rheight,max( diameterOfBinaryTree(root->left) , diameterOfBinaryTree(root->right) ));
    }
};
