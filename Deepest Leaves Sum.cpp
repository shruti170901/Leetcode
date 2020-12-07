// Using DFS

class Solution
{
public:
    unordered_map<int, vector<int>> map;
    int height = INT_MIN;

    void leaf(TreeNode *root, int level)
    {
        if (root == nullptr)
            return;

        map[level].push_back(root->val);
        height = max(level, height);
        leaf(root->left, level + 1);
        leaf(root->right, level + 1);
    }

    int deepestLeavesSum(TreeNode *root)
    {
        int sum = 0;
        leaf(root, 0);
        for (auto it = map[height].begin(); it != map[height].end(); it++)
            sum += *it;
        return sum;
    }
};

/****************************************************************************************/

//Using BFS

class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        int result = 0;
        q.push(root);
        while (!q.empty())
        {
            result = 0;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                result += current->val;
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
        }
        return result;
    }
};
