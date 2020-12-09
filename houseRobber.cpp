class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if(n == 1){
            return nums[0];
        }
        for(int i = 1; i < n; i++){
            
            if(i>2){
                dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
            }
            else if(i == 2){
                dp[i] = dp[i-2] + nums[i];
            }
            else{
                dp[i] = nums[i];
            }
        }
        return max(dp[n-1], dp[n-2]);
    }
};
