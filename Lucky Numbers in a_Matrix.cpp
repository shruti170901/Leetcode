// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int i, j, m=mat.size(), n=mat[0].size();
        vector<int> row(m), col(n);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(j==0) row[i]=mat[i][j];
                else row[i]=min(row[i], mat[i][j]);
                if(i==0) col[j]=mat[i][j];
                else col[j]=max(col[j], mat[i][j]);
            }
        }
        vector<int>ans;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(mat[i][j]==row[i] && mat[i][j]==col[j]) ans.push_back(mat[i][j]);
            }
        }
        return ans;
    }
};