// https://leetcode.com/problems/combinations/

class Solution {
public:
    void rec(int prev, int k, int n, vector<int> &temp, vector<vector<int>>& ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        int i, sz=temp.size();
        for(i=prev+1;i<=n-k+1+sz;i++){
            temp.push_back(i);
            rec(i, k, n, temp, ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(k>n) return ans;
        rec(0, k, n, temp, ans);
        return ans;
    }
};