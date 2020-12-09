// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int i, j, n=g.size(), m;
        if(n==0) return 0;
        m=g[0].size();
        
        vector<vector<int>> grid=g;
        for(i=0;i<n;i++) for(j=0;j<m;j++) if(grid[i][j]==1) grid[i][j]=-1;
        
        if(grid[0][0]==-1) return 0;
        grid[0][0]=1;
        for(i=1;i<m;i++) {
            //cout<<i<<endl;
            if(grid[0][i-1]!=-1 && grid[0][i]!=-1) grid[0][i]=1;
            else break;
        }
        for(i=1;i<n;i++) {
            //cout<<i<<endl;
            if(grid[i-1][0]!=-1 && grid[i][0]!=-1) grid[i][0]=1;
            else break;
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                //cout<<i<<j<<endl;
                if(grid[i][j]!=-1){ 
                    grid[i][j]=0;
                    if(grid[i-1][j]!=-1)grid[i][j]+=grid[i-1][j];
                    if(grid[i][j-1]!=-1)grid[i][j]+=grid[i][j-1];
                }
            }
        }
        if(grid[n-1][m-1]==-1) return 0;
        return grid[n-1][m-1];
    }
};