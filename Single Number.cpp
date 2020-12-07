// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0, i, n=nums.size();
        for(i=0;i<n;i++) x^=nums[i];
        return x;
    }
};