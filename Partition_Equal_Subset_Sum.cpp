// Question Link : https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        if(n == 0) return false;
        for(auto x:nums) sum += x;
        if(sum & 1) return false;
        sum = sum / 2;
        vector<vector<int>> dp(sum+1, vector<int>(n, -1)); //-1 for unvisited, any other value 'visited' and 'output of already solved subproblem'
        return util(nums, n-1, sum, dp);
    }
    int util(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
        if(sum == 0) {
            return 1;
        }
        if(n < 0 || sum < 0) return 0;
        if(dp[sum][n] != -1) {
            return dp[sum][n];
        }
        int res = util(nums, n-1, sum-nums[n], dp) || util(nums, n-1, sum, dp);
        return dp[sum][n] = res;
    }
};