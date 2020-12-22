class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int solution = 0;//if we have an empty vector the solution is 0
        if(nums.size())
        {
            solution = 1;
            int bigger = 0;//0 is the starting point to be followed by either an increasing or decreasing sequence
            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i] == nums[i - 1])
                    continue;//we can ignore duplicates as they can always be omitted
                else if(nums[i] > nums[i - 1])
                {
                    if(bigger == 0 || bigger == 2)
                    {
                        bigger = 1;//1 means we now have an increasing sequence
                        solution++;
                    }
                }
                else //if(nums[i] < nums[i - 1])
                {
                    if(bigger == 0 || bigger == 1)
                    {
                        bigger = 2;//2 means we now have a decreasing sequence
                        solution++;
                    }
                }
            }
        }
        return solution;
    }
