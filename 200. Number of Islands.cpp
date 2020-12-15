class Solution {
public:
    int count,n,m;
    void dfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        if(i+1<n&&grid[i+1][j]=='1')
            dfs(grid,i+1,j);
        if(j+1<m&&grid[i][j+1]=='1')
            dfs(grid,i,j+1);
        if(i-1>-1&&grid[i-1][j]=='1')
            dfs(grid,i-1,j);
        if(j-1>-1&&grid[i][j-1]=='1')
            dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        count =0;
        // memset(visited,0, sizeof(grid));
        if(grid.size()==0)
            return 0;
        m=grid[0].size();
        n=grid.size();
        // vector<vector<bool>> visited(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
