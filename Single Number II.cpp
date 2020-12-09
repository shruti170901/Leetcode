// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0, three=0;
        for(int i:nums){
            two|=one & i;
            one^=i;
            three=one&two;
            one &= ~three;
            two &= ~three;
            
        }
        return one;
    }
};