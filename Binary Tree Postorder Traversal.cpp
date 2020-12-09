// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, bool>> stk;
        TreeNode* temp=root;
        while(temp || !stk.empty()){
            if(temp){
                stk.push({temp, false});
                temp=temp->left;
            }
            else{
                pair<TreeNode*, bool> t=stk.top();
                stk.pop();
                if(!t.second){
                    stk.push({t.first, true});
                    temp=t.first->right;
                }
                else{
                    ans.push_back(t.first->val);
                }
            }
        }
        return ans;
    }
};