// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        TreeNode *t1=root, *t2;
        while(t1!=NULL){
            if(t1->left){
                t2=t1->left;
                while(t2->right) t2=t2->right;
                t2->right=t1->right;
                t1->right=t1->left;
                t1->left=NULL;
            }
            //cout<<t1->val<<endl;
            t1=t1->right;
            //if(!t1) break;
            //cout<<(t1==NULL)<<"...\n";
        }
        //cout<<root->val;
        return;
    }
};