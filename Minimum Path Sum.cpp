// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i, j, m, n;
        n=grid.size();
        if(n==0) return 0;
        m=grid[0].size();
        for(i=n-2;i>=0;i--) grid[i][m-1]+=grid[i+1][m-1];
        for(i=m-2;i>=0;i--) grid[n-1][i]+=grid[n-1][i+1];
        
        for(i=n-2;i>=0;i--){
            for(j=m-2;j>=0;j--){
                grid[i][j]+=min(grid[i+1][j], grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};