// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int i, j, n=grid.size(), m=grid[0].size(), f1, f2, min=0, len=0;
        queue<pair<int, int>> q;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==1) f1++;
                else if(grid[i][j]==2){
                    f2++;
                    q.push({i, j});
                }
            }
        }
        //if(f1==0) return 0;
        //else{
            while(!q.empty()){
                if(len==0) len=q.size();
                i=q.front().first; j=q.front().second;
                q.pop();
                if(i+1<n && grid[i+1][j]==1){grid[i+1][j]=2; q.push({i+1, j}); f1--;}
                if(j+1<m && grid[i][j+1]==1){grid[i][j+1]=2; q.push({i, j+1}); f1--;}
                if(i-1>=0 && grid[i-1][j]==1){grid[i-1][j]=2; q.push({i-1, j}); f1--;}
                if(j-1>=0 && grid[i][j-1]==1){grid[i][j-1]=2; q.push({i, j-1}); f1--;}
                
                len--;
                if(len==0 && !q.empty()) min++;
            }
            if(f1>0) return -1;
            else return min;
        //}
    }
};