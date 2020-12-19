/*
    Smallest Subtree with all the Deepest Nodes - This problem appeared in the December Leetcode Challenge (Past Deadline)

    Given the root of a binary tree, the depth of each node is the shortest distance to the root.

    Return the smallest subtree such that it contains all the deepest nodes in the original tree.

    A node is called the deepest if it has the largest depth possible among any node in the entire tree.

    The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.
    
    Input: root = [3,5,1,6,2,0,8,null,null,7,4]
    Output: [2,7,4]
    
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
 
class Node
{
public:
    TreeNode *root;
    int depth;
    Node()
    {
        root=NULL;
    }
};
class Solution {
public:
    Node calcans(TreeNode *root,int d)
    {
        if(root==NULL)
        {
            Node obj;
            obj.depth=d;
            return obj;
        }
        Node obj;
        Node left=calcans(root->left,d+1);
        Node right=calcans(root->right,d+1);
        if(left.depth>right.depth)
        {
            if(left.root==NULL)
                obj.root=root;
            else
                obj.root=left.root;
            obj.depth=left.depth;
        }
        else if(right.depth>left.depth)
        {
            if(right.root==NULL)
                obj.root=root;
            else
                obj.root=right.root;
            obj.depth=right.depth;
        }
        else
        {
            obj.root=root;
            obj.depth=left.depth;
        }
        return obj;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        Node ans=calcans(root,0);
        return ans.root;
    }
};
