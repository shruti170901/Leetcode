class Solution {
public:
//     solution and tutorial used
    vector<int> lis_array(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                d[i] = max(d[i], d[j] + 1);
        }
    }
    return d;
}

int minimumMountainRemovals(vector<int>& nums)
{
    int n = nums.size();
    vector <int> df,db;
    df=lis_array(nums);
    reverse(nums.begin(),nums.end());
    db=lis_array(nums);

    int ans=0;

    for(int i=1;i<n-1;i++)
    {
        int l=df[i];
        int r=db[n-1-i];
        // dbg2(l,r);
        if(l>1 && r>1)ans=max(ans,l+r-1);
    }

    return min(n-ans,n-1);
}
};