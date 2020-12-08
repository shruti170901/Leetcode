// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans=0, mn=INT_MAX, mx, i, j, n=grid.size();
        vector<int> row, col;
        for(i=0;i<n;i++){
            mx=0;
            for(j=0;j<n;j++){
                mx=max(grid[i][j], mx);
            }
            row.push_back(mx);
        }
        
        for(j=0;j<n;j++){
            mx=0;
            for(i=0;i<n;i++){
                mx=max(mx, grid[i][j]);
            }
            col.push_back(mx);
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                ans+=min(row[i], col[j])-grid[i][j];
            }
        }
        return ans;
    }
};