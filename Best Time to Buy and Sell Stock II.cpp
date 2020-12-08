// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0, n=p.size(), i, mn;
        i=0;
        while(i<n){
            while(i<n-1 && p[i]>=p[i+1]) i++;
            if(i==n-1) break;
            mn=p[i];
            while(i<n-1 && p[i]<=p[i+1]) i++;
            ans+=p[i]-mn;
        }
        return ans;
    }
};