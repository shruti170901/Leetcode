class Solution {
private:
    int calculate_tilt(TreeNode* node, int& sum) {
        if (!node)
            return 0;
        
        int leftVal = calculate_tilt(node->left, sum);
        int rightVal = calculate_tilt(node->right, sum);
        
        sum += abs(leftVal - rightVal);
        return leftVal + rightVal + node->val;
    }
    
public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        calculate_tilt(root, sum);
        return sum;
    }
};
