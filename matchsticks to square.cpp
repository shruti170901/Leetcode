class Solution 
{
public:
    bool makesquare(vector<int>& nums) 
    {
         int n = nums.size();
         int s = 0;
        if(n<4)
        { 
            return false;
        }
        int t_s=1<<n;
        int dp[t_s];
        memset(dp,-1,sizeof(dp));
        int k=4;
        dp[0] = 0;
        for (int i = 0; i < n; i++) 
        {    s += nums[i];
        }
         if (s % k) 
         {   
             return false;
         }
        int tar = s/k;
        
        for (int j = 0; j < (t_s); j++) 
        {
            if (dp[j] == -1) 
            {
                continue;
            }  
            for (int i = 0; i < n; i++) 
            {
                if (!(j&(1<<i)) && dp[j]+nums[i] <= tar) 
                {  
                    int n_s=j|(1<<i); 
                    dp[n_s] = (dp[j]+nums[i]) % tar;
                }
            }
        }
        return dp[t_s-1] == 0;
    }
};