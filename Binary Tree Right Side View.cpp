class Solution
{
public:
	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> output;

		if (root == nullptr)
		{
			return output;
		}

		queue<TreeNode *> q;
		q.push(root);

		TreeNode *curr = nullptr;

		while (!q.empty())
		{
			int size = q.size();
			int last = 0;

			while (last++ < size)
			{
				curr = q.front();
				q.pop();

				if (last == size)
					output.push_back(curr->val);

				if (curr->left)
					q.push(curr->left);

				if (curr->right)
					q.push(curr->right);
			}
		}

		return output;
	}
};

******************************************************************************************************************************************************

																																					 class Solution
{
public:
	unordered_map<int, int> map;

	void rightView(TreeNode *root, int level)
	{
		if (root == nullptr)
			return;

		map[level] = root->val;

		rightView(root->left, level + 1);
		rightView(root->right, level + 1);
	}

	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> output;

		rightView(root, 0);

		for (int i = 0; i < map.size(); i++)
		{
			output.push_back(map[i]);
		}

		return output;
	}
};