// https://leetcode.com/problems/queries-on-a-permutation-with-key/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v, ans;
        for(int i=0;i<m;i++) v.push_back(i);
        for(int i=0;i<queries.size();i++){
            queries[i]--;
            ans.push_back(v[queries[i]]);
            for(int j=0;j<m;j++){
                if(v[j]<v[queries[i]]) v[j]++;
            }
            v[queries[i]]=0;
        }
        return ans;
    }
};