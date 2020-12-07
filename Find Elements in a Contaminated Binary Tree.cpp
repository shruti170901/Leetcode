// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements {
public:
    TreeNode* t;
    FindElements(TreeNode* root) {
        fill(root, 0);
        t=root;
    }
    void fill(TreeNode* root, int v){
        if(root==NULL) return;
        root->val=v;
        fill(root->left, 2*v+1);
        fill(root->right, 2*v+2);
    }
    bool f(TreeNode* root, int v){
        if(root==NULL) return false;
        if(root->val==v) return true;
        return f(root->left, v)||f(root->right, v);
    }
    bool find(int target) {
        return f(t, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */