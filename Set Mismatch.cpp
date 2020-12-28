class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_set<int> freq;
        int size = nums.size();
        int sum = (size * (size + 1)) / 2;
        int total = 0;
        int duplicate = 0;
        for (int i = 0; i < size; i++)
        {
            if (freq.count(nums[i]))
                duplicate = nums[i];

            freq.insert(nums[i]);
            total += nums[i];
        }
        return {duplicate, sum - (total - duplicate)};
    }
};