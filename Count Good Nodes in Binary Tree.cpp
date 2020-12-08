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
    void dfs(TreeNode *root, int maxSF, int &cnt){
        if(!root) return;
        
        if(root->val >= maxSF){
            cnt++;
            maxSF = root->val;
            cout<<maxSF<<"\n";
        }
        
        if(root->left) dfs(root->left, maxSF, cnt);
        if(root->right) dfs(root->right, maxSF, cnt);        
        
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        if(!root) return 0;
    
        dfs(root, root->val, cnt);
        return cnt;
    }
};