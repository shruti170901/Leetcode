class Solution {
    int dp[201][20001];
public:
    int subset_sum(vector<int> val,int W,int n){  // refer to 1_subset_sum.cpp.
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(j==0){
                dp[i][j]=1;
            }
            if(i==0&&j!=0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            
            if(val[i-1]<=j){
            dp[i][j]=dp[i-1][j-val[i-1]]||dp[i-1][j];
    }
    else
    {
         dp[i][j]=dp[i-1][j];
    }
        }
    }
    
    return dp[n][W];
    
}
    bool canPartition(vector<int>& val) {
        int sum=0;
        int n=val.size();
    for(int i=0;i<n;i++)
        sum+=val[i];

    if(sum%2!=0){
        return 0;
    }
    else{
        if(subset_sum(val,sum/2,n)==1){
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    }
};
