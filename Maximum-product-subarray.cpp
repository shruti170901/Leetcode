class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int i, j = 0;
        int n = nums.size();
        vector<int> MAX(n + 1, 0);
        vector<int> MIN(n + 1, 0);
        int ans = -INT_MAX;

        ans = MAX[0] = MIN[0] = nums[0];
        for (i = 1; i < n; i++)
        {
            MAX[i] = nums[i];
            MIN[i] = nums[i];
            if (nums[i] > 0)
            {

                MAX[i] = max(MAX[i], MAX[i - 1] * nums[i]);
                MIN[i] = min(MIN[i], MIN[i - 1] * nums[i]);
            }

            if (nums[i] < 0)
            {
                MAX[i] = max(MAX[i], MIN[i - 1] * nums[i]);
                MIN[i] = min(MIN[i], MAX[i - 1] * nums[i]);
            }

            ans = max(ans, MAX[i]);
        }
        return ans;
    }
};