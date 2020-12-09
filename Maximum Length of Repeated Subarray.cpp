class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans=0;
        int n=A.size();
        int m=B.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
