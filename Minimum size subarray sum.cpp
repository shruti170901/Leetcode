class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int i=0, j=0, n=nums.size(), sum=0, count=1, ans=INT_MAX;
        while(j<n) {
            sum+=nums[j];

            if(sum>=s) {
                while(sum>=s) {
                    sum-=nums[i];
                    i++;
                }
                ans= min(ans, j-i+2);
                if(ans==1)
                    return ans;
            }
            j++;
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};