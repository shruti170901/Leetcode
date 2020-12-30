/*
  Integer Break Leetcode
  Given a positive integer n, break it into the sum of at least two positive integers and 
    maximize the product of those integers. Return the maximum product you can get.
    
    Input: 2
    Output: 1
    
    Input: 10
    Output: 36
    
    */
    
class Solution {
public:
    int calcans(int *dp,int i,int n)
    {
        if(dp[i]!=-1)
            return dp[i];
        int pr=1;
        int f=i==n?i-1:i;
        for(int j=1;j<=f;j++)
        {
            int max_a=j*calcans(dp,i-j,n);
            if(max_a>=pr)
                pr=max_a;
        }
        dp[i]=pr;
        return pr;
    }
    int integerBreak(int n) {
         int *dp=(int *)malloc((n+1)*(sizeof(int)));
        for(int i=1;i<=n;i++)
            dp[i]=-1;
        dp[0]=1;
        int ans=calcans(dp,n,n);
        free(dp);
        return ans;
    }
};
