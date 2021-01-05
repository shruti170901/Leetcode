class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int l=i+1,h=nums.size()-1;
            int t=-nums[i];
            while(l<h)
            {
                int sum=nums[l]+nums[h];
                if(sum<t)
                    l++;
                else if(sum>t)
                    h--;
                else
                {
                    vector<int>temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[l];
                    temp[2]=nums[h];
                    ans.push_back(temp);
                    while(l<h&&nums[l]==temp[1])
                        l++;
                    while(l<h&&nums[h]==temp[2])
                        h--;
                    while(i<nums.size()-1&&nums[i]==nums[i+1])
                        i++;
                }
            }
        }
        return ans;
    }
};