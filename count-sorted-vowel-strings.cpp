
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][5];
        memset(dp,0,sizeof dp);
        for(int i=0;i<5;i++)dp[1][i]=1;
        for(int i = 2; i <= n; i++){
            dp[i][0]+=dp[i-1][0];dp[i][1]+=dp[i-1][1]+dp[i][0];
            dp[i][2]+=dp[i-1][2]+dp[i][1];dp[i][3]+=dp[i-1][3]+dp[i][2];
            dp[i][4]+=dp[i-1][4]+dp[i][3];
        }
        int ans=0;
        for(int i=0;i<5;i++)ans+=dp[n][i];
        return ans;

    }
};
