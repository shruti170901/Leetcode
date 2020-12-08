class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        
        int i = 0 , j = 0, n = nums.size();
        int subarray_sum = 0 , max_length = -1;
        int sum = accumulate(nums.begin() , nums.end() , 0), target = sum - x;
		
		if(target < 0) // no elements remaning in the vector to make it 0
			return -1; 
        
		if(target == 0)  // all the elements needed
			return n; 
        
		
		while(j < n)
		{
            subarray_sum+=nums[j];
            
			if(subarray_sum < target)
                ++j;
         
		 	else if(subarray_sum == target)
			 {
                int len = j - i + 1;
                max_length = max(max_length , len);
                subarray_sum-=nums[i];
                ++i;
                ++j;
            }

            else if(subarray_sum > target)
			{
                while(subarray_sum > target)
				{
                    subarray_sum-=nums[i];
                    ++i;
                }

                if(subarray_sum == target)
				{
                    int len = j - i + 1 ;
                    max_length = max(max_length , len) ;
                    subarray_sum-=nums[i];
                    ++i;
                    ++j;
                    
                }
                else if(subarray_sum < target)
					++j;
    
            }
        }

        if(max_length == -1) 
			return -1; 
        return n - max_length ;
        
    }
};
