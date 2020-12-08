// https://leetcode.com/problems/increasing-order-search-tree/

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
    vector<int> v;
    void in(TreeNode* root){
        if(root==NULL) return;
        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }
    TreeNode* make(){
        TreeNode* root=new TreeNode;
        root->val=v[0];
        TreeNode* temp=root;
        for(int i=1;i<v.size();i++){
            root->right=new TreeNode;
            root=root->right;
            root->val=v[i];
        }
        return temp;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans;
        in(root);
        return make();
    }
};