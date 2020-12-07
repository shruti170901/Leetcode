// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void reverse(vector<int>& v, int l, int r){
        while(l<r){
            swap(v[l], v[r]);
            l++; r--;
        }
        return;
    }
    void nextPermutation(vector<int>& nums) {
        int l=-1, r, n=nums.size(), i;
        if(n<=1) return;
        i=0;
        while(i<n-1){
            if(nums[i]<nums[i+1]) l=i;
            i++;
        }
        if(l==-1){
            reverse(nums, 0, n-1);
            return;
        }
        r=l+1; i=l+1;
        while(i<n){
            if(nums[i]>nums[l]) r=i;
            i++;
        }
        swap(nums[l], nums[r]);
        reverse(nums, l+1, n-1);
        return;
    }
};