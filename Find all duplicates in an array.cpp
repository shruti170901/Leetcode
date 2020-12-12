class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> output;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                output.push_back(index + 1);
            }
            nums[index] = -nums[index];
        }
        return output;
    }
};