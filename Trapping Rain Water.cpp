// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& h) {
        int i, j, n=h.size(), ans=0;
        if(n==0) return 0;
        vector<int> pre(n, 0), suf(n, 0);
        pre[0]=0; suf[n-1]=0;
        for(i=1;i<n;i++){
            pre[i]=max(pre[i-1], h[i-1]);
        }
        for(i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1], h[i+1]);
        }
        //for(int it:pre) cout<<it<<" "; cout<<endl;
        //for(int it:suf) cout<<it<<" "; cout<<endl;
        for(i=1;i<n-1;i++){
            int temp=min(pre[i], suf[i]);
            if(h[i]<temp) ans+=temp-h[i];
        }
        return ans;
    }
};