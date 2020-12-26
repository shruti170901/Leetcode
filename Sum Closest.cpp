class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int i, l, r, n=nums.size(), ans=INT_MAX, diff=INT_MAX, s1, d1;
        sort(nums.begin(), nums.end());
        for(i=0;i<n-2;i++){
            l=i+1; r=n-1;
            while(l<r){
                s1=nums[i]+nums[l]+nums[r];
                d1=abs(s1-t);
                if(d1<diff){
                    diff=d1;
                    ans=s1;
                }
                if(s1<t) l++;
                else if(s1>t) r--;
                else return t;
            }
        }
        return ans;
    }
};