/*
  Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if 
   at least one permutation of the node values in the path is a palindrome.

  Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
  
  Input: root = [2,3,1,3,1,null,1]
  Output: 2
  
  */
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
    void calcans(TreeNode *root,int &a,int *arr)
    {
        if(root==NULL)
            return;
        arr[root->val]++;
        if(root->left==NULL&&root->right==NULL)
        {
            int odd=0;
            for(int i=0;i<10;i++)
            {
                if(arr[i]%2!=0)
                    odd++;
            }
            if(odd<=1)
                a++;
        }
        calcans(root->left,a,arr);
        calcans(root->right,a,arr);
        arr[root->val]--;
        return;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int *arr=(int *)calloc(10,sizeof(int));
        int a=0;
        calcans(root,a,arr);
        free(arr);
        return a;
    }
};
