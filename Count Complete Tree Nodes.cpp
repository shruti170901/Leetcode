class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        return (1 + countNodes(root->right) + countNodes(root->left));
    }
};
