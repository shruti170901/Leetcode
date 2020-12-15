class Solution {
public:
    vector<vector<int> > dp;
    int recur(vector<int> &nums,int left,int right)
    {
        if(left>=right)
        {
            return 0;
        }
        if(dp[left][right]!=-1)
            return dp[left][right];
        int ans=0;
        for(int k=left;k<right;k++)
        {
            ans = max(ans,recur(nums,left,k)+recur(nums,k+1,right)+nums[left-1]*nums[k]*nums[right]);
        }
        return dp[left][right] = ans;
    }
    int maxCoins(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        vector<int> v(nums.size()+2,1);
        for(int i=0;i<nums.size();i++)
        {
            v[i+1] = nums[i];
        }
        dp.resize(v.size(),vector<int> (v.size(),-1));
        return recur(v,1,v.size()-1);
    }
};
