//Sum of Absolute Differences in a Sorted Array
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
 
        int n=nums.size();
        int pre[n]; memset(pre,0,sizeof(pre));
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=nums[i]+pre[i-1];
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int val=nums[i];  
            int left_count=i;  
            int right_count=n-i-1;  
			int temp1=0;
            if(i-1>=0)
            temp1+=pre[i-1];  // store sum from 0 to (i-1)index;
            int temp2=0;
            temp2=pre[n-1]-pre[i]; // store sum from n-1 to (i+1)  index;
            
            int total= (val*left_count - temp1) + (temp2 - right_count*val);  
            ans.push_back(total);
        }
        
        return ans;
    }
};
