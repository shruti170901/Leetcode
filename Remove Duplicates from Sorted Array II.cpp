// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0, k=0, n=nums.size();
        if(n<=1) return n;
        while(i<n && j<n){
            while(j<n && nums[i]==nums[j]) j++;
            if(j-i>1){
                nums[k++]=nums[i];
                nums[k++]=nums[j-1];
                i=j;
            }
            else{
               nums[k++]=nums[i];
                i=j;
            }
        }
        return k;
    }
};