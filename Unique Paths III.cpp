// https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    int sr, sc, tr, tc, rem=0, m, n, dr[4]={0, 1, 0, -1}, dc[4]={1, 0, -1, 0}, ans=0;
    void dfs(int r, int c, int rem, vector<vector<int>> &grid){
        rem--;
        if(rem<0) return;
        if(r==tr && c==tc){
            if(rem==0) ans++;
            return;
        }
        grid[r][c]=3;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(0<=nr && nr<m && 0<=nc && nc<n){
                if(grid[nr][nc]%2==0) dfs(nr, nc, rem, grid);
            }
        }
        grid[r][c]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size(); n=grid[0].size();
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=-1) rem++;
                if(grid[i][j]==1) sr=i,sc=j;
                if(grid[i][j]==2) tr=i,tc=j;
            }
        }
        dfs(sr,sc,rem, grid);
        return ans;
    }
};