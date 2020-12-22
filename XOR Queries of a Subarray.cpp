class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        int arr_size = arr.size();
        vector<int> x(arr_size);
        
        x[0] = arr[0];
        
        for(int i=1;i<arr_size;i++){
            x[i] = arr[i]^x[i-1];
        }
        
        for(int i=0;i<n;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==r)
                ans[i] = arr[r];
            else if(l!=0)
                ans[i] = x[r]^x[l-1];
            else
                ans[i] = x[r];
        }
        
        
        return ans;
    }
};