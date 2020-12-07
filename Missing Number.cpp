class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0, total;
        for (int value : nums)
            sum += value;
        total = nums.size() * (nums.size() + 1) / 2;
        return (total - sum);
    }
};