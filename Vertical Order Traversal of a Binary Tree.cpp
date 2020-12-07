// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    map<int, vector<pair<int,int>>> m;
    void trav(TreeNode* root, int idx, int d){
        if(root==NULL) return;
        m[idx].push_back({d,root->val});
        trav(root->left, idx-1, d+1);
        trav(root->right, idx+1, d+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        trav(root, 0, 0);
        vector<vector<int>> ans;
        for(auto it:m){
            sort(it.second.begin(), it.second.end());
            vector<int> temp;
            for(auto jt:it.second) temp.push_back(jt.second);
            ans.push_back(temp);
        }
        return ans;
    }
};