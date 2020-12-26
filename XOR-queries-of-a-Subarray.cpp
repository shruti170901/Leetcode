class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        int p[n+1];
        p[0]=0;
        for(int i=1;i<=n;i++){
            p[i]=arr[i-1]^p[i-1];
        }
        vector<int> ans;
        for(auto x:queries){
            ans.push_back(p[x[1]+1]^p[x[0]]);
        }
        return ans;
    }
};
