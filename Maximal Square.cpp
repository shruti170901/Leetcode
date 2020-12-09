class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),ans=0;
        int m=matrix[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++){
        	if(matrix[i][0]=='1'){
        		dp[i][0]=1;
        	}
        	else{
        		dp[i][0]=0;
        	}
            ans=max(ans,dp[i][0]);
        }
        for(int i=0;i<m;i++){
        	if(matrix[0][i]=='1'){
        		dp[0][i]=1;
        	}
        	else{
        		dp[0][i]=0;
        	}
            ans=max(ans,dp[0][i]);
        }
        for(int i=1;i<n;i++){
        	for(int j=1;j<m;j++){
                if(matrix[i][j]=='1')
        		    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                else
                    dp[i][j]=0;
                ans=max(ans,dp[i][j]);
        	}
        }
        return ans*ans;
    }
};