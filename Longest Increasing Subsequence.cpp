
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n + 1, 1), visited(n, 0);
        int i, k, Max = 0;
        for (i = 0; i < n; i++)
        {
            for (k = 0; k < i; k++)
            {
                if (visited[i] != 0)
                    break;
                if (nums[k] < nums[i])
                {
                    dp[i] = max(dp[i], dp[k] + 1);
                    visited[k] = 1;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            Max = max(Max, dp[i]);
        }
        return Max;
    }
};