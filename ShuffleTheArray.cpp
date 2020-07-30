class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<pair<int,int> > vec;
        for(int i=0;i<n;i++)vec.push_back({2*i,nums[i]});
        int j=0;
        for(int i=n;i<2*n;i++)vec.push_back({2*(j++)+1,nums[i]});
        sort(vec.begin(), vec.end()); 
        for(int i=0;i<2*n;i++)nums[i]=vec[i].second;
        return nums;
    }
};
