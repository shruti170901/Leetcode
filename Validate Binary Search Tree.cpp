// https://leetcode.com/problems/validate-binary-search-tree/

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
    void rec(TreeNode* root, vector<int> &v){
        if(root==NULL) return;
        rec(root->left, v);
        v.push_back(root->val);
        rec(root->right, v);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        vector<int> v;
        rec(root, v);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]) return false;
        }
        return true;
    }
};