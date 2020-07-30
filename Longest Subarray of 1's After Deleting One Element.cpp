class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int k=1;
        vector<int> v=a;
        int n=v.size();
        sort(v.begin(),v.end());
        if(v[0]==1)return (n-1);
        if(v[n-1]==0)return 0;
        int cnt0 = 0; 
        int l = 0; 
        int max_len = 0;  
        for (int i = 0; i < n; i++) { 
            if (a[i] == 0) 
                cnt0++; 
            while (cnt0 > k) { 
                if (a[l] == 0) 
                    cnt0--; 
                l++; 
            } 
            max_len = max(max_len, i - l + 1); 
        } 
        return max_len-1; 
    }
};
