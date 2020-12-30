/*
    You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
    The score you get by erasing the subarray is equal to the sum of its elements.

    Return the maximum score you can get by erasing exactly one subarray.

    An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
    
    Input: nums = [4,2,4,5,6]
    Output: 17
    
    Constraints:
  1 <= nums.length <= 105
  1 <= nums[i] <= 104
    
    */

#define M 10000
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int *pos=(int *)malloc((M+1) *sizeof(int)); 
        int *prefix_sum=(int *)malloc(n*sizeof(int));
        for(int i=0;i<=M;i++)
            pos[i]=-1;
        int sum=0;
        int i=0;
        pos[nums[i]]=0;
        prefix_sum[0]=nums[i];
        for(int j=1;j<n;j++)
        {
            prefix_sum[j]=prefix_sum[j-1]+nums[j];
            if(pos[nums[j]]==-1)
                pos[nums[j]]=j;
            else
            {
                int cp=pos[nums[j]];
                if(cp>=i)
                {
                    int temp_sum;
                    if(i>0)
                        temp_sum=prefix_sum[j-1]-prefix_sum[i-1];
                    else
                        temp_sum=prefix_sum[j-1];
                    if(temp_sum>sum)
                        sum=temp_sum;
                    i=cp+1;
                }
                pos[nums[j]]=j;
            }
        }
        int temp_sum;
        if(i>0)
            temp_sum=prefix_sum[n-1]-prefix_sum[i-1];
        else
            temp_sum=prefix_sum[n-1];
        if(temp_sum>sum)
            sum=temp_sum;
        free(pos);
        free(prefix_sum);
        return sum;
    }
};
