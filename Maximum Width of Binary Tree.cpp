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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        if (root) q.push({root, 1});
        while (!q.empty()) {
            int cnt = q.size();
            long long int left = q.front().second, right;
            for (int i = 0; i < cnt; i++) {
                TreeNode* n = q.front().first;
                right = q.front().second;
                q.pop();
                if (n->left != NULL) q.push({n->left, 2*right});
                if (n->right != NULL) q.push({n->right, 2*right+1});
            }
            ans = (ans, (int)(right - left + 1)) ? ans : (int)(right - left + 1);
        }
        return ans;
    }
};
