// https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<vector<int>> dp(3, vector<int>(n));
        int i, c1=costs[0], c2=costs[1], c3=costs[2];
        dp[0][0]=c1;
        dp[1][0]=c2;
        dp[2][0]=c3;
        for(i=1;i<n;i++){
            dp[0][i]=min(dp[0][i-1],min(dp[1][i-1], dp[2][i-1]))+c1;
            auto it=upper_bound(days.begin(), days.end(), days[i]-7);
            if(it==days.begin()) dp[1][i]=c2;
            else{
                it--;
                int temp=it-days.begin();
                dp[1][i]=min(dp[0][temp],min(dp[1][temp], dp[2][temp]))+c2;
            }
            it=upper_bound(days.begin(), days.end(), days[i]-30);
            if(it==days.begin()) dp[2][i]=c3;
            else{
                it--;
                int temp=it-days.begin();
                dp[2][i]=min(dp[0][temp],min(dp[1][temp], dp[2][temp]))+c3;
            }
        }
        return min(dp[0][n-1],min(dp[1][n-1], dp[2][n-1]));
    }
};