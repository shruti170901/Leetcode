// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& v) {
        int i=1, n=v.size();
        if(n<=1) return n;
        vector<int> dp(n, 1);
        for(i=1;i<n;i++){
            if(v[i]>v[i-1]) dp[i]=1+dp[i-1];
        }
        for(i=n-2;i>=0;i--){
            if(v[i]>v[i+1]) dp[i]=max(dp[i], 1+dp[i+1]);
        }
        int ans=0;
        for(i=0;i<n;i++) ans+=dp[i];
        return ans;
    }
};