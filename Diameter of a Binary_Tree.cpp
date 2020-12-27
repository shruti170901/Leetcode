//Diameter of a Binary Tree

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
class Solution
{
public:
    int height(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;

        int lheight = height(root->left, ans);
        int rheight = height(root->right, ans);

        ans = max(ans, lheight + rheight);
        return 1 + max(lheight, rheight);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = INT_MIN;
        int height_of_tree = height(root, ans);
        return ans;
    }
};