class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int ans=0, beg=0;
        while(beg<f.size() && f[beg]==0)beg++;
        if(beg==f.size()){
            return ((beg+1) >= 2*n);
        }
        ans = beg/2;
        
        int end=0;
        while(end<f.size() && f[f.size()-end-1]==0)end++;
        ans += end/2;
        int c=0;
        for(int i=beg+1; i<=f.size()-end-1; i++){
            if(f[i]==0)c++;
            else{
                ans += (c-1)/2;
                c=0;
            }
        }
        return (ans>=n);
    }
};

