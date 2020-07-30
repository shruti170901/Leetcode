class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n = nums.size();
       vector<vector<int>> result(n);
       vector<int>ret;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
               if(nums[i]%nums[j]==0&&result[j].size()>result[i].size())
               result[i]=result[j];
           }
           result[i].push_back(nums[i]);
           if(result[i].size()>ret.size()) ret=result[i];
       }
       return ret;
    }
};
