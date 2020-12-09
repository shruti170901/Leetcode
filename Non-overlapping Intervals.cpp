// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int i, n=v.size(), ans=0;
        for(i=0;i<n-1;i++){
            if(v[i][1]>v[i+1][0]){
                v[i+1][1]=min(v[i][1],v[i+1][1]);
                ans++;
            }
        }
        return ans;
    }
};