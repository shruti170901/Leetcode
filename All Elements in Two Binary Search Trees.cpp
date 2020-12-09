// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
 
 void pushelements(TreeNode*root,vector<int>&v){
     if(root==nullptr){
         return;
     }
     v.push_back(root->val);
     pushelements(root->left,v);
     pushelements(root->right,v);
 }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
     if(root1==nullptr&root2==nullptr){
          vector<int>v;
         return v;
     }
    else if(root1==nullptr){
          vector<int>v;
          pushelements(root2,v);
        sort(v.begin(),v.end());
        return v;
      }
       else  if(root2==nullptr){
          vector<int>v;
          pushelements(root1,v);
           sort(v.begin(),v.end());
           return v;
      }
        else{
              vector<int>v;
              pushelements(root1,v);
              pushelements(root2,v);
            sort(v.begin(),v.end());
           return v;
        }
    }
};   
