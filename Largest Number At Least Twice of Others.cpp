class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=*max_element(nums.begin(), nums.end());
        int index=0;
        for(int i=0;i<nums.size();i ++)
            if(nums[i]!=maxi)
            {
                if((maxi/2)<nums[i])
                    return -1;
            }
            else
                index = i;
            return index;
        }   
     
};