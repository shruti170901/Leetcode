/*problem link:-
  https://leetcode.com/problems/path-with-minimum-effort/
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        cost[0][0] = 0;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            
            for(auto d : dirs){
                int i = x + d[0];
                int j = y + d[1];
                if( i < 0 || i >=m || j < 0 || j>=n || cost[i][j] <= max(cost[x][y], abs(heights[i][j] - heights[x][y])))
                    continue;
                q.push({i,j});
                cost[i][j] = max(cost[x][y], abs(heights[i][j] - heights[x][y]) );
            }
        }
        
        return cost.back().back();
    }
};