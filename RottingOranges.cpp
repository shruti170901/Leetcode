class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int i,j;
        int cnt1=0;
        queue<pair<int,int> > q;   
        
        // The concept of the problem lies in the fact:
        // Start a bfs with all the rotten oranges in the queue
        // Traverse in all possible diretions in the grid, and keep track of the levels which also acts as the time to for all the oranges to rott.
        
        for(i=0;i<grid.size();i++)
        {
            for(j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    cnt1++;
                }
            }
        }
        
        
        int lev=0;
        int dx[] = {1,0,-1,0};     
        int dy[] = {0,1,0,-1};
        while(!q.empty())
        {
            int s = q.size();
            int x;
            for(x=0;x<s;x++)
            {
                auto p = q.front();
                q.pop();
                int y;
                for(y=0;y<4;y++)
                {
                    int n_x = p.first + dx[y];
                    int n_y = p.second + dy[y];
                    if(n_x>=0 && n_x<grid.size() && n_y>=0 && n_y<grid[0].size() && (grid[n_x][n_y]==1 ))
                    {
                        grid[n_x][n_y] = 2;
                        q.push({n_x,n_y});
                        cnt1--;
                    }
                }
            }
            lev++;
        }
        if(lev==0 && cnt1==0)
            return 0;
        int ans = (cnt1==0) ? lev-1: -1;   
        return ans;
        
    }
};
