class Solution 
{
public:
    int dirx[4]={-1,0,1,0};//for the four directions
    int diry[4]={ 0,1,0,-1};// for four directions 
    int dfs(vector<vector<int>>&mat,int m,int n,vector<vector<int>>&dp,int i,int j)
    {
        if(i<0||i>=m||j<0||j>=n)
            return 0;
        if(dp[i][j]>1)
            return dp[i][j];
        for(int p=0;p<4;p++)
        {
            int x=i+dirx[p],y=j+diry[p];
            if(!(x<0||x>=m||y<0||y>=n))
            {
                if(mat[x][y]>mat[i][j])// checked for necessary condition 
                  dp[i][j]=max(dp[i][j],1+dfs(mat,m,n,dp,x,y));//then updated as i got the point 
            }   
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {  
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size(),l=0;
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==1)
                {
                    dfs(matrix,m,n,dp,i,j);
                    l=max(l,dp[i][j]);
                } 
            }
        }
        return l;
    
    }
};