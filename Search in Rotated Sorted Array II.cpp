// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int l, r, i, n=nums.size(), m;
        if(n==0) return false;
        l=0, r=n-1;
        while(l<r){
            m=l+(r-l)/2;
            if(nums[m]==t) return true;
            if(nums[m]>nums[r]){
              if(nums[m]>t && nums[l] <= t) r = m;
              else l = m + 1;
          }else if(nums[m] < nums[r]){
              if(nums[m]<t && nums[r] >= t) l = m + 1;
              else r = m;
          }else{
              r--;
          }
        }
        return nums[l]==t;
    }
};