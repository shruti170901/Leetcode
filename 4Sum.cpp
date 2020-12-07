class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(auto it=nums.begin();it!=nums.end();it++){
            //cout<<it-nums.begin()<<" ";
            for(auto jt=it+1;jt!=nums.end();jt++){
                //cout<<*it<<" "<<*jt<<endl;
                for(auto kt=jt+1; kt!=nums.end();kt++){
                    if(binary_search(kt+1, nums.end(), target-(*it+*jt+*kt))){
                        vector<int> temp {*it, *jt, *kt, target-(*it+*jt+*kt)};
                        ans.push_back(temp);
                    }
                    while(kt!=(--nums.end())&&*kt==*(kt+1)) kt++;
                }
                while(jt!=(--nums.end())&&*jt==*(jt+1)) {jt++;}
            }
            //cout<<it-nums.begin()<<endl;
            while(it!=(--nums.end()) && *it==*(it+1)) it++;
        }
        return ans;
    }
};