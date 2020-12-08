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
private:
    bool chk(TreeNode *root, int &height){
        if(root==NULL){
            height=0;
            return true;
        }
        int h1, h2;
        if((chk(root->left, h1) && chk(root->right, h2)) == false){
            return false;
        }
        
        if(abs(h1-h2)>1)return false;
        height=max(h1, h2)+1;
        
        return true;
    }
public:
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        int h=0;
        return chk(root, h);
    }
};