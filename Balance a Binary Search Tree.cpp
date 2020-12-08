// https://leetcode.com/problems/balance-a-binary-search-tree/

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
    TreeNode* balance(vector<int>& ans, int l, int r){
        if(l>r) return NULL;
        TreeNode* temp=new TreeNode;
        int m=(l+r)/2;
        temp->val=ans[m];
        temp->left=balance(ans, l, m-1);
        temp->right=balance(ans, m+1, r);
        return temp;
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        TreeNode *ans;
        inorder(root, arr);
        ans=balance(arr, 0, arr.size()-1);
        return ans;
    }
};