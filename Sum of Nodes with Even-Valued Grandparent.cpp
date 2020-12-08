// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        if(root==NULL){
            return 0;
        }
        TreeNode *l, *r;
        if((root->val)%2==0){
            l=root->left;
            if(l!=NULL){
                r=l->right;
                if(r!=NULL) ans+=r->val;
                l=l->left;
                if(l!=NULL) ans+=l->val;
            }
            r=root->right;
            if(r!=NULL){
                l=r->left;
                if(l!=NULL) ans+=l->val;
                r=r->right;
                if(r!=NULL) ans+=r->val;
            }
        }
        return ans+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
    }
};