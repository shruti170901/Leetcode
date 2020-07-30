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
private:
    int maxDepth(TreeNode* node){  
        if (node == NULL)return 0;  
        else{  
            int lDepth = maxDepth(node->left);  
            int rDepth = maxDepth(node->right); 
            if (lDepth > rDepth) return(lDepth + 1);  
            else return(rDepth + 1);  
        }  
    }  
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        TreeNode* temp=root;
        int height=maxDepth(temp);
        vector<vector<int>> ans(height);
        if(root==nullptr)return ans;
        vector<TreeNode*> sleft={root},sright;
        int layer=0;
        while(!(sleft.empty()&&sright.empty())){
            if(layer%2==0){
                while(sleft.empty()==false){
                    ans[layer].push_back(sleft[0]->val);
                    if(sleft[0]->left!=nullptr)
                        sright.push_back(sleft[0]->left);
                    if(sleft[0]->right!=nullptr)
                        sright.push_back(sleft[0]->right);
                    sleft.erase(sleft.begin());
                }
            }
            else{
                while(sright.empty()==false){
                    ans[layer].push_back(sright[0]->val);
                    if(sright[0]->left!=nullptr)
                        sleft.push_back(sright[0]->left);
                    if(sright[0]->right!=nullptr)
                        sleft.push_back(sright[0]->right);
                    sright.erase(sright.begin());
                }
                reverse(ans[layer].begin(),ans[layer].end());
            }
            layer++;
        }
        return ans;
    }
};
