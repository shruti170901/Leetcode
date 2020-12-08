// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int i, j, k, n=mat[0].size(), m=mat.size(), ans=0;
        vector<vector<int>> v(m+1, vector<int>(n+1));
        v[1][1]=mat[0][0];
        for(i=1;i<n;i++) v[1][i+1]=mat[0][i]+v[1][i];
        for(i=1;i<m;i++) v[i+1][1]=mat[i][0]+v[i][1];
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                v[i+1][j+1]=mat[i][j]+v[i][j+1]+v[i+1][j]-v[i][j];
            }
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                for(k=1;k<=min(i, j);k++){
                    if(v[i][j]-v[i-k][j]-v[i][j-k]+v[i-k][j-k]==k*k) ans++;
                }
            }
        }
        return ans;
    }
};