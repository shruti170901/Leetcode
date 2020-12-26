class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int target2=target-nums[i]-nums[j];
                int left=j+1,right=nums.size()-1;
                while(left<right)
                {
                    if(nums[left]+nums[right]<target2)
                        left++;
                    else if(nums[left]+nums[right]>target2)
                        right--;
                    else
                    {
                        vector<int>quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[left];
                        quad[3]=nums[right];
                        ans.push_back(quad);
                        while(left<right&&quad[2]==nums[left])
                            left++;
                        while(right>left&&quad[3]==nums[right])
                            right--;
                    }
                    
                }
                
                while(j<nums.size()-1&&nums[j]==nums[j+1])
                    j++;
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1])
                    i++;
        }
        return ans;
        
    }
};