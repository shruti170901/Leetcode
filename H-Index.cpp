// https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& v) {
        sort(v.begin(), v.end());
        int i, n=v.size(), h=0;
        if(n==0) return 0;
        int l=0, r=INT_MAX, m;
        while(l<r){
            m=l+(r-l)/2+1;
            int it=lower_bound(v.begin(), v.end(), m)-v.begin();
            if(it>n-m) r=m-1;
            else l=m;
        }
        return l;
    }
};