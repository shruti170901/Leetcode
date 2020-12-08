/* CPP SOLUTION 
  QUESTION LINK : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
  */
  
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int count = 0;
        for (int i=0; i<nums.size(); i++) {
           
            if(i == nums.size()-1) {
                 nums[count++]=nums[i];
            }
            else{
                if(nums[i] != nums[i+1]) {
                    nums[count++] = nums[i];
                }
            }
        }
        return count;
    }
    
};
