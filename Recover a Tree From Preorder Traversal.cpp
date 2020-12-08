// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

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
    
    TreeNode* recoverFromPreorder(string s) {
        TreeNode* root=new TreeNode;
        int num=0, i=0, n=s.size();
        while(i<s.size() && s[i]!='-'){
            num=10*num+(s[i]-'0');
            i++;
        }
        root->val=num;
        
        stack<pair<TreeNode*, int>> stk;
        pair<TreeNode*, int> pr;
        stk.push({root, 0});
        while(i<n){
            int d=0;
            while(s[i]=='-'){
                i++; d++;
            }
            int num=0;
            while(i<n && s[i]!='-'){
                num=10*num+s[i]-'0';
                i++;
            }
            pr=stk.top();
            while(pr.second+1!=d){
                stk.pop();
                pr=stk.top();
            }
            if((pr.first)->left==NULL){
                (pr.first)->left=new TreeNode(num);
                stk.push({(pr.first)->left, d});
            }
            else{
                (pr.first)->right=new TreeNode(num);
                stk.push({(pr.first)->right, d});
            }
        }
        return root;
    }
};