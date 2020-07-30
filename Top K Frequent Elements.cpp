class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        map<int,int> m; map<int,vector<int>> m1;
        int n = 0; vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] ++;
        for (auto it = m.begin();it!= m.end(); it++)
            m1[it -> second].push_back(it-> first);
        for (auto it = m1.rbegin();it!= m1.rend(); it++){
            for (int i = 0; i < it->second.size(); i++){
                if (n < k){
                    ans.push_back(it->second[i]);
                    n++;
                }
                else break;
            }
            if (n>=k) break;
        }
        return ans;
    }
};
