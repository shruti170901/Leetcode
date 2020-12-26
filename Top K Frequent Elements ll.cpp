class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> match;
        for(int i=0; i< nums.size(); i++){
            match[nums[i]]++;
        }
        priority_queue<pair<int, int>> q;

        for(auto it=match.begin(); it!=match.end() ;it++){
            q.push({it->second,it->first});
        }
        for(int l=0; l<k; l++){
            int x=q.top().first;
            int res=q.top().second;
            result.push_back(res);
              q.pop();
        }
    
    
    	return result;
     }
    
};