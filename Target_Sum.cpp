// Question Link : https://leetcode.com/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (sum - S) % 2) return 0;
        int target = (sum - S) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int n : nums)
            for(int i = target; i >= n; --i)
                dp[i] += dp[i - n];
        return dp[target];
    }
};