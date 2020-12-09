bool isPossible(vector<int>& arr ,int m, int mid)
{   
	int count = 1;
	int  subarray_sum = 0;
    int n = arr.size();
	
    for( int i=0; i<n; i++)
	{
		if(subarray_sum+arr[i]> mid){
			
            ++count;
			subarray_sum = arr[i];
			
            if(count>m)
                return false;
		}
        
		else {
			subarray_sum += arr[i];
		}
		

	}
	return true;

}


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        // Using binary search w/ monotonic search space
        
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;
        
        
        while(s<=e) 
        {
            int mid = (s+e)/2;
            
            if(isPossible(nums,m,mid))
            {
                ans  = min(mid,ans);
                e = mid - 1;
            }
            
            else 
                s = mid+1;
            
        }
            
        return ans;
        
    }
};
