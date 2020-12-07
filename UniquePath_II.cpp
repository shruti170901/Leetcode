class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        if(n == 1 and m == 1 and obstacleGrid[0][0] == 1)
            return 0;
        dp[1][1] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if((i == 1 and j == 1) or obstacleGrid[i-1][j-1] == 1)
                    continue;
                else if(i > 1 and j > 1 and obstacleGrid[i-1][j-2] == 1 and obstacleGrid[i-2][j-1] == 1)
                    continue;
                else if(i > 1 and obstacleGrid[i-2][j-1] == 1){
                    dp[i][j] = dp[i][j-1];
                }
                else if(j > 1 and obstacleGrid[i-1][j-2] == 1)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m][n];
    }
};
