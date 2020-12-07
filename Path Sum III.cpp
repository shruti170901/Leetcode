// https://leetcode.com/problems/path-sum-iii/

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
    vector<int> res;
    int cnt=0;
    void rec(TreeNode* root, int sum){
        if(!root) return;
        int i, n=res.size();
        res.push_back(res[n-1]+root->val);
        //for(int it:res) cout<<it<<" "; cout<<endl;
        for(i=0;i<n;i++) if(res[n]-res[i]==sum) cnt++;
        rec(root->left, sum);
        rec(root->right, sum);
        res.pop_back();
        return;
    }
    int pathSum(TreeNode* root, int sum) {
        res.push_back(0);
        rec(root, sum);
        return cnt;
    }
};