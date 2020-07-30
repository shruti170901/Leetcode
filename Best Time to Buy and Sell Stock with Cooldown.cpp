class Solution {
public:
    int dp[100001][2];
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return maxii(0,false,prices);
    }
private:
    int maxii(int i,bool have,vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(dp[i][have]!=-1) return dp[i][have];
        if(have==false) return dp[i][have]=max(-prices[i]+maxii(i+1,true,prices),maxii(i+1,false,prices));
        else return dp[i][have]=max({prices[i]+maxii(i+2,false,prices),maxii(i+1,true,prices)});
    }
};
