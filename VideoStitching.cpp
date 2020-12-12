class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end());
        int i,j;
        vector<int> dp(101,101);        // maximum values according to contraints
        dp[0]=0;                        // setting up the initial value
        for(i=0;i<clips.size();i++)         
        {
            for(j=clips[i][0]+1;j<=clips[i][1];j++)
            {
                dp[j] = min(dp[j],dp[clips[i][0]]+1);      // the dp relation
            }
        }
        return dp[T]<100?dp[T]:-1;
    }
};
