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
    vector<string> result;
public:
    void dfs(TreeNode *root, string src){
        if(root==NULL){
            return;
        }
        src += "->"+to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            result.push_back(src);
        }else if(root->left==NULL){
            dfs(root->right, src);
        }else if(root->right==NULL){
            dfs(root->left, src);
        }else{
            dfs(root->right, src);      
            dfs(root->left, src);
        }
    
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return result;
        else if(root->left==NULL && root->right==NULL){
            result.push_back(to_string(root->val));
        }else{
            dfs(root->left, to_string(root->val));
            dfs(root->right, to_string(root->val));
        }
        return result;
    }
};