// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        if(n==0) return ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        int i, j;
        for(i=1;i<n;i++){
            temp.clear();
            temp.push_back(1);
            for(j=1;j<ans[i-1].size();j++){
                temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};