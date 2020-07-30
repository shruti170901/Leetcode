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
private:
    TreeNode* construct(vector<int>&postorder, unordered_map<int,int>&mp,int pstart,int pend,int istart,int iend)
    {
        if(pstart>pend)
            return NULL;
        else{
            int mid=mp[postorder[pend]];
            TreeNode * root=new TreeNode(postorder[pend]);
            int l=mid-istart;
            int r=iend-mid;
            root->left=construct(postorder,mp,pstart,pstart+l-1,istart,mid-1);
            root->right=construct(postorder,mp,pstart+l,pstart+l+r-1,mid+1,iend);
            return root;
        }
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return construct(postorder, mp,0,n-1,0,n-1);
    }
};
