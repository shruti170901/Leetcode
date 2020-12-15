class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        if(k==0){
            for(auto x:mp){
                if(x.second>1)
                    cnt++;
            }
        }
        else{
            for(auto x:mp){
                if(mp.count(x.first-k))
                    cnt++;
            }
        }
        return cnt;
        
    }
};