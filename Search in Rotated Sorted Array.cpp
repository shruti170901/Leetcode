// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int t) {
        int i, j, mid, l, r, n=nums.size();
        if(n==0) return -1;
        l=0; r=n-1;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==t) return mid;
            else if(nums[mid]<nums[l]){
                if(t<nums[mid]) r=mid-1;
                else{
                    if(t<=nums[r]) l=mid+1;
                    else r=mid-1;
                }
            }
            else{
                if(t>nums[mid]) l=mid+1;
                else{
                    if(t>=nums[l]) r=mid-1;
                    else l=mid+1;
                }
            }
        }
        return -1;
    }
};