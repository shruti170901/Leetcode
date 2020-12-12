class Solution {
public:
    int n,m,count;
    void dfs(vector<vector<int>>& grid,int i,int j){
        grid[i][j]=0;
        count++;
        if(i+1<n&&grid[i+1][j])
            dfs(grid,i+1,j);
        if(j+1<m&&grid[i][j+1])
            dfs(grid,i,j+1);
        if(i-1>-1&&grid[i-1][j])
            dfs(grid,i-1,j);
        if(j-1>-1&&grid[i][j-1])
            dfs(grid,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        if(n==0)
            return 0;
        m=grid[0].size();// otherwise this will cause error if n==0;
        int max_count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    count=0;
                    dfs(grid,i,j);
                    max_count=max(max_count,count);
                }
            }
        }        
        return max_count;
    }
};
