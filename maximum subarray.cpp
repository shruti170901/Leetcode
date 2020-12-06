//O(nlogn) using DnC
int maximum_sum(vector<int>& A,int low, int high){
    if (low == high)
			return A[low];
    
		int mid = (low + high) / 2;
 
        int left_max = A[mid];
        int sum = A[mid];
        for (int i = mid-1; i >= low; i--)
        {
            sum += A[i];
            if (sum > left_max)
            left_max = sum;
        }
        cout<<"left_max="<<left_max<<endl;
    
        int right_max = A[mid+1];
        sum = A[mid+1];    // reset sum to 0
        for (int i = mid + 2; i <= high; i++)
        {
            sum += A[i];
            if (sum > right_max)
            right_max = sum;
        }
         cout<<"right_max="<<right_max<<endl;
        int max_left_right = max(maximum_sum(A, low, mid),
                            maximum_sum(A, mid + 1, high));
 
        cout<<max_left_right<<endl;
        return max(max_left_right, left_max + right_max);
}
class Solution
{
public:
	int maxSubArray(vector<int>& nums){
		return maximum_sum(nums,0,nums.size()-1);
	}
	
};