class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int t3=target-nums[i];
            for(int j=i+1;j<n;j++){
                int t2=t3-nums[j];
                int k=j+1,l=n-1;
                while(k<l){
                    if(nums[k]+nums[l]>t2){
                        l--;
                    }
                    else if(nums[k]+nums[l]<t2){
                        k++;
                    }
                    else{
                        vector<int> v={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(v);
                        while(k<l&&nums[k]==v[2])k++;
                        while(k<l&&nums[l]==v[3])l--;
                    }
                }
                while(j+1<n&&nums[j+1]==nums[j])j++;
            }
            while(i+1<n&&nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};
