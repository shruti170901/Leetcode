// https://leetcode.com/problems/path-sum-ii/

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
    void dfs(vector<vector<int>> &ans, vector<int> &temp, TreeNode* root, int sum){
        if(root==NULL) return;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(root->val==sum) ans.push_back(temp);
            temp.pop_back();
            return;
        }
        dfs(ans, temp, root->left, sum-root->val);
        dfs(ans, temp, root->right, sum-root->val);
        temp.pop_back();
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(ans, temp, root, sum);
        return ans;
    }
};