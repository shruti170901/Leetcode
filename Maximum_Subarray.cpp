//O(n) solution using DP

class Solution
{
public:
	int maxSubArray(vector<int>& nums){
		if (nums.size() == 1)
		{
			return nums[0];
		}
		int maximum_found = nums[0];
		int current_sum = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			current_sum = max(nums[i], current_sum+nums[i]);
			maximum_found = max(maximum_found,current_sum);
		}
		return maximum_found;
	}
	
};