// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(auto it=nums.begin();it!=nums.end();it++){
            //cout<<it-nums.begin()<<" ";
            for(auto jt=it+1;jt!=nums.end();jt++){
                //cout<<*it<<" "<<*jt<<endl;
                if(binary_search(jt+1, nums.end(), -(*it+*jt))){
                    vector<int> temp {*it, *jt, -(*it+*jt)};
                    ans.push_back(temp);
                }
                while(jt!=(--nums.end())&&*jt==*(jt+1)) {jt++;}
            }
            //cout<<it-nums.begin()<<endl;
            while(it!=(--nums.end()) && *it==*(it+1)) it++;
        }
        return ans;
    }
};