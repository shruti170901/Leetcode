class Solution
{
public:
	vector<int> rightSideView(TreeNode* root) {
         if(root==nullptr){
            vector<int>y;
            return y;
        }
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);  
        while(!q.empty()){
           int  s=q.size();
            int u;
            while(s-->0){
                TreeNode*q2=q.front();
                int t=q2->val;
                q.pop();
                u=t;
                if(q2->left){
                    q.push(q2->left);
                }
                if(q2->right){
                    q.push(q2->right);
                }
            }
              v.push_back(u);  
            }
        return v;
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
