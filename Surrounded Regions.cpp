// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void dfs(vector<vector<char>> &v, vector<vector<bool>> &vis, int row, int col){
        if(row<0 || row>=v.size() || col<0 || col>=v[0].size()) return;
        if(vis[row][col]) return;
        vis[row][col]=true;
        if(v[row][col]!='O') return;
        v[row][col]='.';
        dfs(v, vis, row+1, col);
        dfs(v, vis, row-1, col);
        dfs(v, vis, row, col+1);
        dfs(v, vis, row, col-1);
        return;
    }
    void solve(vector<vector<char>>& v) {
        if(v.size()==0) return;
        int i, j, n=v.size(), m=v[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(i=0;i<n;i++){
            if(v[i][0]=='O') dfs(v, vis, i, 0);
            if(m>1 && v[i][m-1]=='O') dfs(v, vis, i, m-1);
        }
        for(i=1;i<m-1;i++){
            if(v[0][i]=='O') dfs(v, vis, 0, i);
            if(n>1 && v[n-1][i]=='O') dfs(v, vis, n-1, i);
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(v[i][j]=='O') v[i][j]='X';
                else if(v[i][j]=='.') v[i][j]='O';
            }
        }
        return;
    }
};