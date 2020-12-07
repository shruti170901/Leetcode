// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> make(int l, int r){
        vector<TreeNode*> ans;
        if(l>r){
            ans.push_back(NULL);
            return ans;
        }
        else if(l==r){
            ans.push_back(new TreeNode(l));
            return ans;
        }
        vector<TreeNode*> lef, rig;
        for(int i=l;i<=r;i++){
            lef=make(l, i-1);
            rig=make(i+1, r);
            
            for(TreeNode* le:lef){
                for(TreeNode* ri:rig){
                    TreeNode* root=new TreeNode(i);
                    root->left=le;
                    root->right=ri;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> v;
        if(n==0) return v;
        return make(1, n);
    }
};