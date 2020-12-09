// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i, l=0, r=nums.size()-1, m;
        while(l<r){
            m=l+(r-l)/2;
            if(nums[m]>nums[l]){
                if(nums[m]>nums[r]) l=m+1;
                else r=m;
            }
            else{
                if(nums[m]<nums[r]) r=m;
                else l=m+1;
            }
        }
        return nums[l];
    }
};