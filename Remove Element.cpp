// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        int i=0, j, n=nums.size(), len=0;
        while(i<n){
            if(nums[i]==val){
                len=0;
                j=i;
                while(j<n && nums[j]==val) j++, len++;
                break;
            }
            i++;
        }
        if(len>0){
            while(j<n){
                nums[i++]=nums[j++];
            }
        }
        return n-len;
    }
};