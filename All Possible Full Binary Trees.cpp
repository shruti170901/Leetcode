// https://leetcode.com/problems/all-possible-full-binary-trees/

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
    unordered_map<int, vector<TreeNode*>> mp;
    
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ans;
        if(N%2==0) return ans;
        if(mp[N].size()!=0) return mp[N];
        if(N==1){
            ans.push_back(new TreeNode);
        }
        else if(N%2){
            for(int i=1;i<N;i+=2){
                int l=i, r=N-1-i;
                for(auto itl:allPossibleFBT(l)){
                    for(auto itr:allPossibleFBT(r)){
                        TreeNode* root=new TreeNode;
                        root->left=itl;
                        root->right=itr;
                        ans.push_back(root);
                    }
                }
            }
            mp[N]=ans;
            return mp[N];
        }
        return ans;
    }
};