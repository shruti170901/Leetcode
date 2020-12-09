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
    vector<TreeNode *> ans;
public:
    TreeNode* dfs(TreeNode *src, set<int> &del){
        if(src==NULL) return NULL;
        src->left=dfs(src->left, del);
        src->right=dfs(src->right, del);
        if(del.count(src->val)){
            if(src->left!=NULL)ans.push_back(src->left);
            if(src->right!=NULL)ans.push_back(src->right);
            return NULL;
        }       
        
        return src;
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL){
            return vector<TreeNode *>(0);
        }
        set<int> del(to_delete.begin(), to_delete.end());
        if(del.count(root->val)==0) ans.push_back(root);
        dfs(root, del);
        return ans;
    }
};