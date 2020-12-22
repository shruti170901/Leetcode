class Solution {
public:
    map<vector<int>,bool>mp;
   vector<vector<int>>myans;
    void find(vector<int>& nums, int target,int i,int a,int b){
        int l=i,r=nums.size()-1;
        vector<int>x;
        x.push_back(a);
        x.push_back(b);
        while(l<r){
            if(nums[l]+nums[r]==target){
                x.push_back(nums[l]);
                x.push_back(nums[r]);
                sort(x.begin(),x.end());
                if(mp.find(x)==mp.end()){
                  mp[x]=true;
                myans.push_back(x);
                }
                x.pop_back();
                x.pop_back();
                l++;r--;
            }
            else if(nums[l]+nums[r]<target){
                l++;
            }
            else{
                r--;
            }
        
        }  
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
          vector<vector<int>>v;
            return v;
        }
     
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){  
            if(i==0||(i!=0&&nums[i-1]!=nums[i])){
            int sum=target-nums[i];
            for(int j=i+1;j<nums.size()-1;j++){
                sum=sum-nums[j];
                find(nums,sum,j+1,nums[i],nums[j]);
                sum+=nums[j];
                while(j<nums.size()-1&&nums[j]==nums[j+1]){
                    j++;
                }
                }  
            }
          }
        return myans;
    }
    
}; 
