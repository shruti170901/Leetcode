// https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int i, j, k, l, m=mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                for(k=max(i-K, 0);k<=min(i+K, m-1);k++){
                    for(l=max(j-K, 0);l<=min(j+K, n-1);l++){
                        ans[i][j]+=mat[k][l];
                    }
                }
            }
        }
        return ans;
    }
};